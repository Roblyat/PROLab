#include "MotionModel.h"

MotionModel::MotionModel()
{
}

MotionModel::~MotionModel()
{
}

void MotionModel::predict(nav_msgs::Odometry &odom,  std::vector<Particle> &particles, double &dt) {

    // Extract velocity and angular velocity from the odometry message
    double v = odom.twist.twist.linear.x;
    double w = odom.twist.twist.angular.z;  

    for (auto &particle : particles) {

        // Sample noisy velocities using Gaussian noise
        double v_hat = v + sampleGaussian(alpha1 * std::abs(v) + alpha2 * std::abs(w));
        double w_hat = w + sampleGaussian(alpha3 * std::abs(v) + alpha4 * std::abs(w));
        double gamma_hat = sampleGaussian(alpha5 * std::abs(v) + alpha6 * std::abs(w));

        // Get the current particle state
        double theta = tf::getYaw(particle.pose.orientation); // Extract current orientation (theta)

        if (std::abs(w_hat) < 1e-6) { // If angular velocity is close to zero
            // Update particle state using the sampled velocities for straight line motion
            particle.pose.position.x += v_hat * cos(theta) * dt;
            particle.pose.position.y += v_hat * sin(theta) * dt;
        } else {
            // Update particle state using the sampled velocities for circular motion
            double delta_x = (v_hat / w_hat) * (sin(theta + w_hat * dt) - sin(theta));
            double delta_y = (v_hat / w_hat) * (-cos(theta + w_hat * dt) + cos(theta));
            double delta_theta = w_hat * dt + gamma_hat * dt;

            // Update particle's pose
            particle.pose.position.x += delta_x;
            particle.pose.position.y += delta_y;
            theta += delta_theta;

            // Normalize theta and convert it back to quaternion
            tf::Quaternion q;
            q.setRPY(0, 0, theta); // Roll and pitch are zero in 2D

            q.normalize(); // Normalize the quaternion to prevent drift

            particle.pose.orientation.x = q.x();
            particle.pose.orientation.y = q.y();
            particle.pose.orientation.z = q.z();
            particle.pose.orientation.w = q.w();
        }
    }

}

// Utility function to sample from a Gaussian distribution
double MotionModel::sampleGaussian(double variance) {
    std::normal_distribution<double> dist(0.0, sqrt(variance));
    std::default_random_engine generator;
    return dist(generator);
}