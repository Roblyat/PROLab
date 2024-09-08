// ctrl_node.cpp (stared in launch file)
#include "../include/my_cool_project/Controller.h"
#include <iostream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "controller_node");
    ros::NodeHandle n;

    Controller controller(n);

    // Send all goals in sequence
    controller.sendGoal();

    ros::spin(); 

    return 0;
}
