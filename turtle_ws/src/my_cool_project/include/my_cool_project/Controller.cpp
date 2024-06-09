//Contoller.cpp
#include "Controller.h"

Controller::Controller(ros::NodeHandle &N) : ac("move_base", true), nh(N)
{
    // Wait for the action server to come up
    while (!ac.waitForServer(ros::Duration(5.0)))
    {
        ROS_INFO("Waiting for the move_base action server to come up");
    }
}

void Controller::sendGoal()
{
    move_base_msgs::MoveBaseGoal goal;

    // We'll send a goal to the robot to move 1 meter forward
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    goal.target_pose.pose.position.x = 3.5;
    goal.target_pose.pose.position.y = 0.5;
    goal.target_pose.pose.orientation.w = 1.0;

    ROS_INFO("Sending goal to position (3.5, 0.5)");

    ac.sendGoal(goal);

    ac.waitForResult();

    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Hooray, the base moved to (3.5, 0.5)");
    else
        ROS_INFO("The base failed to move to (3.5, 0.5). State: %s", ac.getState().toString().c_str());
}