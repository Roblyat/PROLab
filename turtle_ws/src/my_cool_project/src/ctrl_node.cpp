// ctrl_node.cpp
#include "../include/my_cool_project/Controller.h"
#include <iostream>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "controller_node");
  ros::NodeHandle n;
  ros::Rate loop_rate(30);

  Controller controller(n);

  // Add a 5-second delay before sending the first goal
  // ros::Duration(5.0).sleep();

  while (ros::ok())
  {
    controller.sendGoal();

    ros::spinOnce();

    loop_rate.sleep();
  };

  return 0;
}