// ParticleFilter.h
#pragma once
#include <ros/ros.h>
#include <geometry_msgs/PoseArray.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/LaserScan.h>
#include <random>
#include <tf/transform_datatypes.h>
#include <nav_msgs/OccupancyGrid.h>
#include <ros/timer.h>
//my_cool_project
#include "Particle.h"
#include "Debug.h"
#include "MotionModel.h"
#include "SensorModel.h"

class ParticleFilter {
public:
    ParticleFilter(ros::NodeHandle &N);

private:
    //callbacks & initialization
    void initializeParticles();
    std::vector<std::pair<float, float>> findFreeCells(const nav_msgs::OccupancyGrid &map); // throw patricle just in map

    void odomCallback(const nav_msgs::Odometry::ConstPtr &msg);
    void laserScanCallback(const sensor_msgs::LaserScan::ConstPtr &msg);
    void mapCallback(const nav_msgs::OccupancyGrid::ConstPtr &msg);

    //filter
    void publishParticles(); 
    void resampleParticles();
    MotionModel motion_model;
    SensorModel sensor_model;

    //utilities
    ros::NodeHandle nh;
    ros::Time last_time;

    //odom callback &dt calculation
    ros::Subscriber odom_sub;
    nav_msgs::Odometry odom;
    double dt;
    
    //laser & map callback
    ros::Subscriber laser_sub;
    ros::Subscriber map_sub;
    nav_msgs::OccupancyGrid map_data;

    //filter
    ros::Publisher particles_pub;
    std::vector<Particle> particles;
    int num_particles_;
    

    //debug
    ros::Publisher debug_pub;
    Debug debug;
    ros::Timer debug_timer; // Timer for publishing debug messages
    double debug_interval = 5;  // Interval for debug messages (in seconds)
    void debugTimerCallback(const ros::TimerEvent& event);
    void publishDebugInfo(const std::string &step_name);
    
};
