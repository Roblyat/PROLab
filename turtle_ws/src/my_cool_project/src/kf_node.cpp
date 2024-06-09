// kf_node.cpp
#include <iostream>
#include "../include/my_cool_project/KalmanFilter.h"


int main(int argc, char **argv)
{

  ros::init(argc, argv, "kf_node");
  ros::NodeHandle n;
  ros::Rate loop_rate(30); // Set loop rate to 30 Hz

  KalmanFilter kalmanfilter(n);

  while (ros::ok())
  {
    kalmanfilter.predict();

    ros::spinOnce();
    loop_rate.sleep(); // Sleep for the rest of the cycle to enforce the loop rate

  };

  return 0;
}