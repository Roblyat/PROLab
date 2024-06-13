//KalmanFilter.h
#include <eigen3/Eigen/Dense>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <ros/ros.h>
#include <my_cool_project/custom.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h>
#include <sensor_msgs/Imu.h>

class KalmanFilter {
public:
    KalmanFilter(ros::NodeHandle &N);
    Eigen::VectorXd getState() const;

private:
    void odomCallback(const nav_msgs::Odometry::ConstPtr &msg);
    void imuCallback(const sensor_msgs::Imu::ConstPtr &msg);
    tf2::Quaternion eulerToQuaternion(double roll, double pitch, double yaw);
    void update();
    void predict();

    ros::Subscriber odom_sub;
    ros::Subscriber imu_sub;
    ros::Publisher prediction_pub;
    ros::Publisher covPose_pub;
    ros::Publisher debug_pub;

    nav_msgs::Odometry odom;
    geometry_msgs::Pose2D poseWorld;
    geometry_msgs::Twist twistWorld;
    geometry_msgs::PoseWithCovarianceStamped covePose;
    my_cool_project::custom prediction;
    
    tf2::Quaternion q;
    Eigen::VectorXd u;
    ros::NodeHandle nh;
    ros::Time last_time_;
    double dt, theta, timer;
    Eigen::VectorXd mu_t;  // State estimate
    Eigen::MatrixXd Sigma_t;  // State covariance
    Eigen::MatrixXd A_t;  // State transition model
    Eigen::MatrixXd B_t;  // Control input model
    Eigen::VectorXd z;  // Observation data
    Eigen::MatrixXd R_t;  // Process noise covariance
    Eigen::MatrixXd C_t;  // Observation model
    Eigen::MatrixXd Q_t;  // Measurement noise covariance
    Eigen::MatrixXd K_t;  // Kalman gain
    double normalizeAngle(double angle);  // Normalization function
};