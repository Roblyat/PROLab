// Particle.h
#pragma once
#include <geometry_msgs/Pose.h>
#include <vector>

struct Particle {
    geometry_msgs::Pose pose;
    double weight;

    struct vector{
        geometry_msgs::Point origin, end;
        double angle;
        double lenth;
    }vector;
};