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
  debug_pub = nh.advertise<std_msgs::Float64MultiArray>("/debug", 1);
  imu_sub = nh.subscribe("/imu", 1, &KalmanFilter::imuCallback, this);

  // KalmanFilter
  //  Initialize state and covariance
  mu_t = Eigen::VectorXd(6);
  prediction.covariance = {0};
  mu_t << 0.5, 0.5, 0.0, 0.0, 0.0, 0.0; // Initialize start state //YAML PARAMSERVER
  z = Eigen::VectorXd(6);
  Sigma_t = 0.001 * Eigen::MatrixXd::Identity(6, 6);

  // Initialize models (example values, you should set these according to your system)
  A_t = Eigen::MatrixXd::Identity(6, 6);
  // Update A_t with the time dependency for the velocity components
  A_t(0, 3) = dt; // x depends on v_x
  A_t(1, 4) = dt; // y depends on v_y
  A_t(2, 5) = dt; // theta depends on omega
  B_t = Eigen::MatrixXd(6, 2);

  R_t = 0.001 * Eigen::MatrixXd::Identity(6, 6);
  C_t = Eigen::MatrixXd::Identity(6, 6);  // Observation model
  Q_t = 0.1 * Eigen::MatrixXd::Identity(6, 6);
  K_t = Eigen::MatrixXd::Zero(6, 6);
}

void KalmanFilter::predict()  //############## METHODE aufteilen ####
{
  u = Eigen::VectorXd(2);
  u << odom.twist.twist.linear.x, odom.twist.twist.angular.z;

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
  
  for(int i = 0; i < 6; i++)
  { 
    for(int j = 0; j < 6; j++)
    {
      prediction.covariance[i * 6 + j] = Sigma_t(i, j);
    }
  }

  std::fill(covePose.pose.covariance.begin(), covePose.pose.covariance.end(), 0.0);

  // Set the specific covariance values
  covePose.pose.covariance[0] = prediction.covariance[0];
  covePose.pose.covariance[7] = prediction.covariance[7];
  covePose.pose.covariance[35] = prediction.covariance[35];

  prediction_pub.publish(prediction);
  covPose_pub.publish(covePose);

  timer;
  timer += dt;
  // ROS_INFO("Current timer: %.2f sec", timer);
  if(timer > 0.5)
  {
    std_msgs::Float64MultiArray debug_msg;
    debug_msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
    debug_msg.layout.dim[0].size = 3;
    debug_msg.layout.dim[0].stride = 1;
    debug_msg.layout.dim[0].label = "covariance";
    debug_msg.data.clear();
    debug_msg.data.push_back(covePose.pose.covariance[0]);
    debug_msg.data.push_back(covePose.pose.covariance[7]);
    debug_msg.data.push_back(covePose.pose.covariance[35]);
    debug_pub.publish(debug_msg);
    timer = 0.0;
  }

  // ROS_INFO("Predict mu_t: %.2f %.2f %.2f %.2f %.2f %.2f", mu_t(0), mu_t(1), mu_t(2), mu_t(3), mu_t(4), mu_t(5));
  // ROS_INFO("Predict Sigma_t: %.2f %.2f %.2f %.2f %.2f %.2f", Sigma_t(0, 0), Sigma_t(1, 1), Sigma_t(2, 2), Sigma_t(3, 3), Sigma_t(4, 4), Sigma_t(5, 5));
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
    // ROS_INFO("Current publish rate: %.2f sec", dt);
  }
  last_time_ = current_time;

  predict();
};

void KalmanFilter::imuCallback(const sensor_msgs::Imu::ConstPtr &msg)
{
  
  std::cout << "IMU data: " << msg->linear_acceleration.x << std::endl;
  std::cout << "IMU data:" << msg->angular_velocity.z << std::endl;
  // ROS_INFO("IMU data: %.2f %.2f %.2f", imu.orientation.x, imu.orientation.y, imu.orientation.z);
  z << msg->linear_acceleration.x * cos(prediction.pose.theta) * dt,
       msg->linear_acceleration.x * sin(prediction.pose.theta) * dt,
       msg->angular_velocity.z,
       msg->linear_acceleration.x * cos(prediction.pose.theta),   //############### oder IMU.angluar_velocity.x / dt
       msg->linear_acceleration.x * sin(prediction.pose.theta),
       msg->angular_velocity.z / dt;

  update();
}

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

void KalmanFilter::update()
{ 
  C_t << 1/dt, 0, 0, 0, 0, 0,
         0, 1/dt, 0, 0, 0, 0,
         0, 0, 1/dt, 0, 0, 0,
         0, 0, 0, 1/dt, 0, 0,
         0, 0, 0, 0, 1/dt, 0,
         0, 0, 0, 0, 0, 1/dt;

  K_t = Sigma_t * C_t.transpose() * (C_t * Sigma_t * C_t.transpose() + Q_t).inverse();
  
  // std::cout << "K_t: " << K_t << std::endl;

  // mu_t = mu_t + K_t * (z - C_t * mu_t);
 
  Eigen::VectorXd test = Eigen::VectorXd(6);
  test = z; //- C_t * mu_t;
  std::cout << "test: " << test << std::endl;
  // Sigma_t = (Eigen::MatrixXd::Identity(6, 6) - K_t * C_t) * Sigma_t;
}

Eigen::VectorXd KalmanFilter::getState() const
{
  return mu_t;
}