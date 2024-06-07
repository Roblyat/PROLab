//KalmanFilter.h
#include <eigen3/Eigen/Dense>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose2D.h>
#include <ros/ros.h>
#include <my_cool_project/custom.h>

class KalmanFilter {
public:
    KalmanFilter(ros::NodeHandle &N);
    void odomCallback(const nav_msgs::Odometry::ConstPtr &msg);
    void predict();
    void update(const Eigen::VectorXd& z);
    void clcEuler();
    void clcWorldFrame();
    Eigen::VectorXd getState() const;

private:
    //subscribe to the topic /odom
    ros::Subscriber odom_sub;
    ros::Publisher prediction_pub;
    nav_msgs::Odometry odom;
    geometry_msgs::Pose2D poseWorld;
    geometry_msgs::Twist twistWorld;
    my_cool_project::custom prediction;
    Eigen::VectorXd u;
    ros::NodeHandle nh;
    ros::Time last_time_;
    double dt, theta, theta_new;
    Eigen::VectorXd mu_t;  // State estimate
    Eigen::MatrixXd Sigma_t;  // State covariance
    Eigen::MatrixXd A_t;  // State transition model
    Eigen::MatrixXd B_t;  // Control input model
    Eigen::MatrixXd R_t;  // Process noise covariance
    Eigen::MatrixXd C_t;  // Observation model
    Eigen::MatrixXd Q_t;  // Measurement noise covariance
    double normalizeAngle(double angle);  // Normalization function
};