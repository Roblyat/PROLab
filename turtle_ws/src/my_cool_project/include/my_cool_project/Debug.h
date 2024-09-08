//Debug.h
#pragma once

#include <vector>                     // For std::vector
#include <geometry_msgs/Point.h>      // For geometry_msgs::Point

struct Debug {

    std::vector<double> beam_angles;      // Angles of beams relative to the robot
    std::vector<double> beam_hits_dist;        // Distances of beam hits
    std::vector<double> beam_expected_dist;    // Expected distances of beam hits
    std::vector<geometry_msgs::Point> beam_hit_positions; // Positions of beam hits in the world
    std::vector<double> beam_probabilities; // Probabilities for each beam measurement
};