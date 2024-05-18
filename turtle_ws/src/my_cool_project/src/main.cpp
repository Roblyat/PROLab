#include "../include/controller.h"
#include "../include/evaluation.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "controller_goals");
  ros::Rate rate(10);

  controller controller;
  evaluation evaluation;
  

  while (ros::ok())
  {
    ros::spinOnce();

    controller.sendGoal();

    evaluation.publishKf();

    rate.sleep();
  }

  return 0;
}