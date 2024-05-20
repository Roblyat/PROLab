//KalmanFiler.cpp
#include <iostream>
#include "../include/KalmanFilter.h"

KalmanFilter::KalmanFilter(ros::NodeHandle &N) : nh(N)
{

  // ROS_INFO_STREAM("Init KlammanFilter");
  //  subscribe to the topic /odom
  odom_sub = nh.subscribe("/odom", 1, &KalmanFilter::odomCallback, this);

  // KalmanFilter
  //  Initialize state and covariance
  mu_t = Eigen::VectorXd(3);
  mu_t << 0.5, 0.5, 0; // Initialize start state
  Sigma_t = Eigen::MatrixXd::Identity(3, 3);

  // Initialize models (example values, you should set these according to your system)
  A_t = Eigen::MatrixXd::Identity(3, 3);
  B_t = Eigen::MatrixXd(3, 2);
  // B_t << rate * cos(odom.twist.twist.angular.z * rate), 0,
  //        rate * sin(odom.twist.twist.angular.z * rate), 0,
  //        0, rate;

  R_t = 0.01 * Eigen::MatrixXd::Identity(3, 3);
  C_t = Eigen::MatrixXd::Identity(3, 3);
  Q_t = 0.1 * Eigen::MatrixXd::Identity(3, 3);
}

void KalmanFilter::predict()
{
  u = Eigen::VectorXd(2);
  u << odom.twist.twist.linear.x, odom.twist.twist.angular.z;
  // ROS_INFO("Predict u: %.2f %.2f", u(0), u(1));
  theta = mu_t(2);
  theta_new = normalizeAngle(theta + u(1) * dt);

  //update B_t
  B_t << dt * cos(theta_new), 0,
        dt * sin(theta_new), 0,
        0, dt;

  mu_t = A_t * mu_t + B_t * u;

  Sigma_t = A_t * Sigma_t * A_t.transpose() + R_t;

  ROS_INFO("Predict mu_t: %.2f %.2f %.2f", mu_t(0), mu_t(1), mu_t(2));
}

// subscribe to the topic /odom
void KalmanFilter::odomCallback(const nav_msgs::Odometry::ConstPtr &msg)
{
  odom = *msg;
  ros::Time current_time = ros::Time::now();
  dt = 0;
  if (last_time_.isValid())
  {
    dt = (current_time - last_time_).toSec();
    // ROS_INFO("Current publish rate: %.2f Hz", dt);
    // ROS_INFO("Odometry linear velocity x: %.2f", odom.twist.twist.linear.x);
    // ROS_INFO("Odometry linear velocity y: %.2f", odom.twist.twist.linear.y);
    // ROS_INFO("Odometry angular velocity z: %.2f", odom.twist.twist.angular.z);
  }
  last_time_ = current_time;
};

double KalmanFilter::normalizeAngle(double angle) {
    while (angle > M_PI) angle -= 2.0 * M_PI;
    while (angle < -M_PI) angle += 2.0 * M_PI;
    return angle;
}

void KalmanFilter::update(const Eigen::VectorXd &z)
{
  Eigen::MatrixXd K_t = Sigma_t * C_t.transpose() * (C_t * Sigma_t * C_t.transpose() + Q_t).inverse();
  mu_t = mu_t + K_t * (z - C_t * mu_t);
  Sigma_t = (Eigen::MatrixXd::Identity(3, 3) - K_t * C_t) * Sigma_t;
}

Eigen::VectorXd KalmanFilter::getState() const
{
  return mu_t;
}

// calulate euler angle
void KalmanFilter::clcEuler()
{
  double rf_x = odom.pose.pose.orientation.x;
  double rf_y = odom.pose.pose.orientation.y;
  double rf_z = odom.pose.pose.orientation.z;
  double rf_w = odom.pose.pose.orientation.w;
  double roll, pitch, yaw;
  tf2::Quaternion q(rf_x, rf_y, rf_z, rf_w);
  tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);
  poseWorld.theta = yaw;
}

// calulate world frame
void KalmanFilter::clcWorldFrame()
{
  // calculate world frame
  double rf_x = odom.pose.pose.position.x;
  double rf_y = odom.pose.pose.position.y;
  poseWorld.x = cos(poseWorld.theta) * rf_x - sin(poseWorld.theta) * rf_y;
  poseWorld.y = sin(poseWorld.theta) * rf_x + cos(poseWorld.theta) * rf_y;
  u << poseWorld.x, poseWorld.y, poseWorld.theta; //####### U WRONG

  double rfL_vX = odom.twist.twist.linear.x;
  double rfL_vY = odom.twist.twist.linear.y;
  double rfA_vZ = odom.twist.twist.angular.z;
  twistWorld.linear.x = cos(poseWorld.theta) * rfL_vX - sin(poseWorld.theta) * rfL_vY;
  twistWorld.linear.y = sin(poseWorld.theta) * rfL_vX + cos(poseWorld.theta) * rfL_vY;
  twistWorld.angular.z = rfA_vZ;

  std::cout << "World Frame Pose2D: " << poseWorld.x << " " << poseWorld.y << " " << poseWorld.theta << std::endl;
  std::cout << "World Frame Velocity: " << twistWorld.linear.x << " " << twistWorld.linear.y << " " << twistWorld.angular.z << std::endl;
};