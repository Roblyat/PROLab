// kalmannfilter.cpp
#include "../include/KalmanFilter.h"
#include <iostream>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "controller_node");
  ros::NodeHandle n;

  KalmanFilter kalmanfilter(n);

  while (ros::ok())
  {
    
    ros::spinOnce();

  };

  return 0;
}