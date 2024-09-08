//controller.h
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <my_cool_project/goal.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class Controller{
public:
  Controller(ros::NodeHandle &N);
  void sendGoal();

private:
  MoveBaseClient ac;
  ros::NodeHandle nh;
  move_base_msgs::MoveBaseGoal goal_0, goal_1, goal_2, goal_3, goal_4, goal_5, goal_6, goal_7;
  move_base_msgs::MoveBaseGoal* goals[8] = {&goal_0, &goal_1, &goal_2, &goal_3, &goal_4, &goal_5, &goal_6, &goal_7};
};