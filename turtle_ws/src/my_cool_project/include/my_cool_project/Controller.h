#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class Controller{
public:
  Controller(ros::NodeHandle &N);
  void sendGoal();

private:
  MoveBaseClient ac;
  ros::NodeHandle nh;
  // ############## PUBLISHER ######################
};