#pragma once

#include <nav_msgs/OccupancyGrid.h>
#include <sensor_msgs/LaserScan.h>
#include <vector>
//my_cool_project
#include "Particle.h"
#include "Debug.h"

class SensorModel {
public:
    SensorModel();
    ~SensorModel();
    
    void correct(std::vector<Particle> &particles, const sensor_msgs::LaserScan::ConstPtr &msg, nav_msgs::OccupancyGrid &map_data, double &dt,Debug &debug);

private:
    double calculateExpected(nav_msgs::OccupancyGrid &map_data, Particle &particle, double beam_angle);
    double normalPDF(double x, double mean, double std_dev);
    void normalizeWeights(std::vector<Particle> &particles);

    // Sensor model parameters
    double z_hit = 0.8;     // Probability for hit model
    double z_short = 0.1;   // Probability for short reading model
    double z_max = 0.05;    // Probability for max range reading model
    double z_rand = 0.05;   // Probability for random measurement model
    double sigma_hit = 0.3; // Standard deviation for the hit model
};
