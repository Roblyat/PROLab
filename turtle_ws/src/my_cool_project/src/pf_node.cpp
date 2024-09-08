// pf_node.cpp (stared in launch file)
#include <iostream>
#include "ParticleFilter.h" 


int main(int argc, char **argv)
{

  ros::init(argc, argv, "pf_node");
  ros::NodeHandle n;

  ParticleFilter filter(n);

  ros::Rate loop_rate(30);
  
  while (ros::ok())
  {
    ros::spin();
    loop_rate.sleep();
  };

  return 0;
}