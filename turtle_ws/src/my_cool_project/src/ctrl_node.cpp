// main.cpp
#include "Controller.h"
#include <iostream>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "controller_node");
  ros::NodeHandle n;
  ros::Rate loop_rate(30);

  Controller controller(n);

  while (ros::ok())
  {
    controller.sendGoal();

    ros::spinOnce();

    loop_rate.sleep();
  };

  return 0;
}