#include <iostream>
#include "../include/KalmanFilter.h"

KalmanFilter::KalmanFilter(ros::NodeHandle &N) : nh(N)
{

  // ROS_INFO_STREAM("Init KlammanFilter");
  //  subscribe to the topic /odom
  odom_sub = nh.subscribe("/odom", 1, &KalmanFilter::odomCallback, this);

  // KalmanFilter
  //  Initialize state and covariance
  mu_t = Eigen::VectorXd::Zero(3); // Assuming [x, y, theta]
  Sigma_t = Eigen::MatrixXd::Identity(3, 3);

  // Initialize models (example values, you should set these according to your system)
  A_t = Eigen::MatrixXd::Identity(3, 3);
  B_t = Eigen::MatrixXd::Zero(3, 2);
  R_t = 0.01 * Eigen::MatrixXd::Identity(3, 3);
  C_t = Eigen::MatrixXd::Identity(3, 3);
  Q_t = 0.1 * Eigen::MatrixXd::Identity(3, 3);
}

void KalmanFilter::predict(const Eigen::VectorXd &u)
{
  mu_t = A_t * mu_t + B_t * u;
  Sigma_t = A_t * Sigma_t * A_t.transpose() + R_t;
  std::cout << "Predicted state: " << mu_t << std::endl;
}

void KalmanFilter::update(const Eigen::VectorXd &z)
{
  Eigen::MatrixXd K_t = Sigma_t * C_t.transpose() * (C_t * Sigma_t * C_t.transpose() + Q_t).inverse();
  mu_t = mu_t + K_t * (z - C_t * mu_t);
  Sigma_t = (Eigen::MatrixXd::Identity(3, 3) - K_t * C_t) * Sigma_t;
}

Eigen::VectorXd KalmanFilter::getState() const
{
  return mu_t;
}

// subscribe to the topic /odom
void KalmanFilter::odomCallback(const nav_msgs::Odometry::ConstPtr &msg)
{
  odom = *msg;
};

// calulate euler angle
void KalmanFilter::clcEuler()
{
  double rf_x = odom.pose.pose.orientation.x;
  double rf_y = odom.pose.pose.orientation.y;
  double rf_z = odom.pose.pose.orientation.z;
  double rf_w = odom.pose.pose.orientation.w;
  double roll, pitch, yaw;
  tf2::Quaternion q(rf_x, rf_y, rf_z, rf_w);
  tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);
  poseWorld.theta = yaw;
}

// calulate world frame
void KalmanFilter::clcWorldFrame()
{
  // calculate world frame
  double rf_x = odom.pose.pose.position.x;
  double rf_y = odom.pose.pose.position.y;
  poseWorld.x = cos(poseWorld.theta) * rf_x - sin(poseWorld.theta) * rf_y;
  poseWorld.y = sin(poseWorld.theta) * rf_x + cos(poseWorld.theta) * rf_y;
  u << poseWorld.x, poseWorld.y, poseWorld.theta;

  double rfL_vX = odom.twist.twist.linear.x;
  double rfL_vY = odom.twist.twist.linear.y;
  double rfA_vZ = odom.twist.twist.angular.z;
  twistWorld.linear.x = cos(poseWorld.theta) * rfL_vX - sin(poseWorld.theta) * rfL_vY;
  twistWorld.linear.y = sin(poseWorld.theta) * rfL_vX + cos(poseWorld.theta) * rfL_vY;
  twistWorld.angular.z = rfA_vZ;

  std::cout << "World Frame Pose2D: " << poseWorld.x << " " << poseWorld.y << " " << poseWorld.theta << std::endl;
  std::cout << "World Frame Velocity: " << twistWorld.linear.x << " " << twistWorld.linear.y << " " << twistWorld.angular.z << std::endl;
};
