//Contoller.cpp
#include "Controller.h"

Controller::Controller(ros::NodeHandle &N) : ac("move_base", true), nh(N)
{   
    // Loop to load each goal from the parameter server
    for(int i = 0; i < 8; i++)
    {
        move_base_msgs::MoveBaseGoal& goal = *goals[i]; // Reference to the current goal object in the array

        // Load goal parameters from the parameter server
        if (nh.getParam("goals/goal_" + std::to_string(i) + "/target_pose/header/frame_id", goal.target_pose.header.frame_id) &&
            nh.getParam("goals/goal_" + std::to_string(i) + "/target_pose/pose/position/x", goal.target_pose.pose.position.x) &&
            nh.getParam("goals/goal_" + std::to_string(i) + "/target_pose/pose/position/y", goal.target_pose.pose.position.y) &&
            nh.getParam("goals/goal_" + std::to_string(i) + "/target_pose/pose/position/z", goal.target_pose.pose.position.z) &&
            nh.getParam("goals/goal_" + std::to_string(i) + "/target_pose/pose/orientation/x", goal.target_pose.pose.orientation.x) &&
            nh.getParam("goals/goal_" + std::to_string(i) + "/target_pose/pose/orientation/y", goal.target_pose.pose.orientation.y) &&
            nh.getParam("goals/goal_" + std::to_string(i) + "/target_pose/pose/orientation/z", goal.target_pose.pose.orientation.z) &&
            nh.getParam("goals/goal_" + std::to_string(i) + "/target_pose/pose/orientation/w", goal.target_pose.pose.orientation.w))
        {
            ROS_INFO("Successfully loaded goal %d parameters from the parameter server.", i);
        }
        else
        {
            ROS_ERROR("Failed to get goal %d parameters from the parameter server.", i);
            ros::shutdown();
        }
    }

    // Wait for the action server to come up
    while (!ac.waitForServer(ros::Duration(5.0)))
    {
        ROS_INFO("Waiting for the move_base action server to come up");
    }
}

void Controller::sendGoal()
{
    for(int rep = 0; rep < 2; rep++){
        
        for (int i = 0; i < 8; i++)
        {
            ROS_INFO("Sending goal_%d to move_base...", i);
            ac.sendGoal(*goals[i]); // Send the current goal

            // Wait for the result
            ac.waitForResult();

            if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
            {
                ROS_INFO("Hooray, the base moved to goal_%d!", i);
            }
            else
            {
                ROS_WARN("The base failed to move to goal_%d. State: %s", i, ac.getState().toString().c_str());
                // Optionally, break the loop if a goal fails or continue depending on your strategy
                // break; // Exit the loop if one goal fails
            }
        }
        ROS_INFO("All goals have been processed.");
    }
}


