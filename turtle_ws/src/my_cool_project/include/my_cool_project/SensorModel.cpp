// SensorModel.cpp
#include <geometry_msgs/Point.h>      
#include <tf/transform_datatypes.h> 
#include "SensorModel.h"

// Constructor
SensorModel::SensorModel()
{
}

// Destructor
SensorModel::~SensorModel()
{
}

// Function to calculate the expected distance to an obstacle from a given particle's perspective
double SensorModel::calculateExpected(nav_msgs::OccupancyGrid &map_data, Particle &particle, double beam_angle) {
    // Extract map parameters
    double map_resolution = map_data.info.resolution;
    int map_width = map_data.info.width;
    int map_height = map_data.info.height;
    double map_origin_x = map_data.info.origin.position.x;
    double map_origin_y = map_data.info.origin.position.y;

    // Get particle's position and orientation
    double particle_x = particle.pose.position.x;
    double particle_y = particle.pose.position.y;
    double particle_theta = tf::getYaw(particle.pose.orientation);

    // Compute the global angle of the beam
    double global_beam_angle = particle_theta + beam_angle;

    double max_range = 3.5; // Maximum range of the sensor

    // Step along the beam until max range or obstacle is found
    for (double r = 0; r <= max_range; r += map_resolution) {
        double x = particle_x + r * cos(global_beam_angle);
        double y = particle_y + r * sin(global_beam_angle);

        // Convert world coordinates to grid coordinates
        int grid_x = static_cast<int>((x - map_origin_x) / map_resolution);
        int grid_y = static_cast<int>((y - map_origin_y) / map_resolution);

        // Check if coordinates are within map bounds
        if (grid_x >= 0 && grid_x < map_width && grid_y >= 0 && grid_y < map_height) {
            if (map_data.data[grid_y * map_width + grid_x] > 50) { // Obstacle cell
                return r; // Return the distance to the obstacle
            }
        } else {
            return max_range; // Beam extends beyond map
        }
    }
    return max_range; // No obstacle found within max range
}

// Function to correct particle weights using laser scan data
void SensorModel::correct(std::vector<Particle> &particles, const sensor_msgs::LaserScan::ConstPtr &scan_msg, nav_msgs::OccupancyGrid &map_data, double &dt, Debug &debug) {
    // Clear previous debug data
    debug.beam_angles.clear();
    debug.beam_hits_dist.clear();
    debug.beam_expected_dist.clear();
    debug.beam_hit_positions.clear();
    debug.beam_probabilities.clear();

    // Precompute beam angles from the LaserScan message
    for (int i = 0; i < scan_msg->ranges.size(); ++i) {
        double beam_angle = scan_msg->angle_min + i * scan_msg->angle_increment;
        debug.beam_angles.push_back(beam_angle);
    }

    // Correct each particle based on the sensor model
    for (auto &particle : particles) {
        double log_weight = 0.0; // Initialize log weight for numerical stability

        // Loop through each beam in the laser scan
        for (int i = 0; i < scan_msg->ranges.size(); ++i) {
            double z_t = scan_msg->ranges[i]; // Actual laser scan measurement
            double theta = tf::getYaw(particle.pose.orientation); // Particle's orientation
            double beam_angle = debug.beam_angles[i]; // Precomputed beam angle

            // Calculate expected measurement based on the map and particle's state
            double expected_dist = calculateExpected(map_data, particle, beam_angle);

            // Probability variables for different sensor models
            double p_hit, p_short, p_max, p_rand;

            // Determine probabilities based on the measurement range
            if (z_t >= scan_msg->range_max) {
                p_hit = 0.0;
                p_short = 0.0;
                p_max = 1.0; // Full probability for max range reading
                p_rand = 1.0 / scan_msg->range_max; // Uniform random probability
            } else {
                p_hit = normalPDF(z_t, expected_dist, sigma_hit); // Gaussian probability for a "hit"
                p_short = z_t < expected_dist ? 2.0 * (expected_dist - z_t) / expected_dist : 0.0; // Short range probability
                p_max = 0.0; // No probability for max range
                p_rand = 1.0 / scan_msg->range_max; // Uniform random probability
            }

            // Combine probabilities with weight factors
            double p_z = z_hit * p_hit + z_short * p_short + z_max * p_max + z_rand * p_rand;
            log_weight += log(p_z); // Update log weight

            // Store debug information
            debug.beam_hits_dist.push_back(z_t);
            debug.beam_expected_dist.push_back(expected_dist);
            debug.beam_probabilities.push_back(exp(log_weight));

            // Calculate hit position in the world frame for visualization
            geometry_msgs::Point hit_position;
            hit_position.x = particle.pose.position.x + z_t * cos(theta + beam_angle);
            hit_position.y = particle.pose.position.y + z_t * sin(theta + beam_angle);
            debug.beam_hit_positions.push_back(hit_position);
        }
        
        // Update particle weight after processing all beams
        particle.weight = exp(log_weight);
    }

    // Normalize weights to sum up to 1
    normalizeWeights(particles);
    ROS_INFO("Weights normalized");
}

// Function to calculate the normal (Gaussian) probability density function
double SensorModel::normalPDF(double x, double mean, double std_dev) {
    double variance = std_dev * std_dev;
    return (1.0 / sqrt(2.0 * M_PI * variance)) * exp(-0.5 * pow((x - mean) / std_dev, 2));
}

// Function to normalize the weights of particles so that they sum to 1
void SensorModel::normalizeWeights(std::vector<Particle> &particles) {
    double sum_weights = 0.0;
    // Compute the sum of all weights
    for (const auto& particle : particles) {
        sum_weights += particle.weight;
    }
    // Normalize each particle's weight
    for (auto& particle : particles) {
        particle.weight /= sum_weights;
    }
}
