//KalmanFiler.cpp
#include <iostream>
#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(ros::NodeHandle &N) : nh(N)
{
  // ROS_INFO_STREAM("Init KlammanFilter");
  //  subscribe to the topic /odom
  odom_sub = nh.subscribe("/odom", 1, &KalmanFilter::odomCallback, this);
  prediction_pub = nh.advertise<my_cool_project::custom>("/prediction", 1);
  covPose_pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/covPose", 1);
  // KalmanFilter
  //  Initialize state and covariance
  mu_t = Eigen::VectorXd(6);
  prediction.covariance = {0};
  mu_t << 0.5, 0.5, 0.0, 0.0, 0.0, 0.0; // Initialize start state //YAML PARAMSERVER
  Sigma_t = Eigen::MatrixXd::Identity(6, 6);

  // Initialize models (example values, you should set these according to your system)
  A_t = Eigen::MatrixXd::Identity(6, 6);
  // Update A_t with the time dependency for the velocity components
  A_t(0, 3) = dt; // x depends on v_x
  A_t(1, 4) = dt; // y depends on v_y
  A_t(2, 5) = dt; // theta depends on omega
  B_t = Eigen::MatrixXd(6, 2);

  R_t = 0.01 * Eigen::MatrixXd::Identity(6, 6);
  C_t = Eigen::MatrixXd::Identity(6, 6);
  Q_t = 0.1 * Eigen::MatrixXd::Identity(6, 6);
}

void KalmanFilter::predict()
{
  u = Eigen::VectorXd(2);
  u << odom.twist.twist.linear.x, odom.twist.twist.angular.z;
  // ROS_INFO("Predict u: %.2f %.2f", u(0), u(1));

  //update B_t
  B_t << dt * cos(mu_t(2)),   0,
         dt * sin(mu_t(2)),   0,
         0,                   dt,
         cos(mu_t(2)),        0,
         sin(mu_t(2)),        0,
         0,                   1;

  mu_t(3) = 0;
  mu_t(4) = 0;
  mu_t(5) = 0;

  mu_t = A_t * mu_t + B_t * u;

  Sigma_t = A_t * Sigma_t * A_t.transpose() + R_t;

  prediction.pose.x = mu_t(0);
  prediction.pose.y = mu_t(1);
  prediction.pose.theta = normalizeAngle(mu_t(2));
  prediction.velocity.linear.x = mu_t(3);
  prediction.velocity.linear.y = mu_t(4);
  prediction.velocity.angular.z = mu_t(5);
  
  for(int i = 0; i < 6; i++)
  { 
    for(int j = 0; j < 6; j++)
    {
      prediction.covariance[i * 6 + j] = Sigma_t(i, j);
    }
  }

  double roll, pitch, yaw;
  roll, pitch = 0;
  yaw = prediction.pose.theta;

  eulerToQuaternion(roll, pitch, yaw);

  covePose.pose.pose.position.x = prediction.pose.x;
  covePose.pose.pose.position.y = prediction.pose.y;
  covePose.pose.pose.orientation.x = q.x();
  covePose.pose.pose.orientation.y = q.y();
  covePose.pose.pose.orientation.z = q.z();
  covePose.pose.pose.orientation.w = q.w();

  std::fill(covePose.pose.covariance.begin(), covePose.pose.covariance.end(), 0.0);

  // Set the specific covariance values
  covePose.pose.covariance[0] = prediction.covariance[0];
  covePose.pose.covariance[7] = prediction.covariance[7];
  covePose.pose.covariance[35] = prediction.covariance[35];

  prediction_pub.publish(prediction);
  covPose_pub.publish(covePose);
  ROS_INFO("Predict mu_t: %.2f %.2f %.2f %.2f %.2f %.2f", mu_t(0), mu_t(1), mu_t(2), mu_t(3), mu_t(4), mu_t(5));
  ROS_INFO("Predict Sigma_t: %.2f %.2f %.2f %.2f %.2f %.2f", Sigma_t(0, 0), Sigma_t(1, 1), Sigma_t(2, 2), Sigma_t(3, 3), Sigma_t(4, 4), Sigma_t(5, 5));
  }

// subscribe to the topic /odom
void KalmanFilter::odomCallback(const nav_msgs::Odometry::ConstPtr &msg)
{
  odom = *msg;
  covePose.header = odom.header;
  ros::Time current_time = ros::Time::now();
  dt = 0;
  if (last_time_.isValid())
  {
    dt = (current_time - last_time_).toSec();
    // ROS_INFO("Current publish rate: %.2f Hz", dt);
  }
  last_time_ = current_time;
};

double KalmanFilter::normalizeAngle(double angle) {
    while (angle > M_PI) angle -= 2.0 * M_PI;
    while (angle < -M_PI) angle += 2.0 * M_PI;
    return angle;
}

// euler to q
tf2::Quaternion KalmanFilter::eulerToQuaternion(double roll, double pitch, double yaw) {
  q.setRPY(roll, pitch, yaw);
    return q;
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
  u << poseWorld.x, poseWorld.y, poseWorld.theta; //####### U WRONG

  double rfL_vX = odom.twist.twist.linear.x;
  double rfL_vY = odom.twist.twist.linear.y;
  double rfA_vZ = odom.twist.twist.angular.z;
  twistWorld.linear.x = cos(poseWorld.theta) * rfL_vX - sin(poseWorld.theta) * rfL_vY;
  twistWorld.linear.y = sin(poseWorld.theta) * rfL_vX + cos(poseWorld.theta) * rfL_vY;
  twistWorld.angular.z = rfA_vZ;

  std::cout << "World Frame Pose2D: " << poseWorld.x << " " << poseWorld.y << " " << poseWorld.theta << std::endl;
  std::cout << "World Frame Velocity: " << twistWorld.linear.x << " " << twistWorld.linear.y << " " << twistWorld.angular.z << std::endl;
};