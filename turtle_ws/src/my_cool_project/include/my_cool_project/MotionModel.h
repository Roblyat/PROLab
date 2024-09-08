#pragma once

#include <ros/ros.h>
#include <Particle.h>
#include <geometry_msgs/PoseArray.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/LaserScan.h>
#include <random>
#include <tf/transform_datatypes.h>
#include <nav_msgs/OccupancyGrid.h>
#include <my_cool_project/debug.h>

class MotionModel {
public:
    MotionModel();
    ~MotionModel();

    void predict(nav_msgs::Odometry &odom, std::vector<Particle> &particles, double &dt);

private:
    std::default_random_engine generator;
    double sampleGaussian(double variance);

    // Noise parameters for the motion model
    double alpha1 = 0.1; // Noise related to rotational error
    double alpha2 = 0.1; // Noise related to translational error due to rotation
    double alpha3 = 0.1; // Noise related to rotational error due to translation
    double alpha4 = 0.1; // Noise related to rotational drift
    double alpha5 = 0.1; // Noise related to translational error due to translation
    double alpha6 = 0.1; // Noise related to rotational error due to translation
};