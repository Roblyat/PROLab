#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include "../include/kalmanfilter.h"

class evaluation {
public:
  evaluation() {
    vel_sub_ = nh_.subscribe("/cmd_vel", 1, &KalmanFilterNode::velocityCallback, this);
    odom_pub_ = nh_.advertise<nav_msgs::Odometry>("/odom_kf", 1);
    kf_ = KalmanFilter();
  }

  void velocityCallback(const geometry_msgs::Twist::ConstPtr& msg) {
    Eigen::VectorXd u(2);
    u << msg->linear.x, msg->angular.z;
    kf_.predict(u);
  }

  void publishKf() {
    nav_msgs::Odometry odom;
    Eigen::VectorXd state = kf_.getState();
    odom.pose.pose.position.x = state(0);
    odom.pose.pose.position.y = state(1);
    odom.pose.pose.orientation.z = sin(state(2) / 2.0);
    odom.pose.pose.orientation.w = cos(state(2) / 2.0);
    odom_pub_.publish(odom);
  }

private:
  ros::NodeHandle nh_;
  ros::Subscriber vel_sub_;
  ros::Publisher odom_pub_;
  KalmanFilter kf_;
};

