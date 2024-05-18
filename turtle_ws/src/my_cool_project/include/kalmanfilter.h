#include <eigen3/Eigen/Dense>

class KalmanFilter {
public:
    KalmanFilter();
    void predict(const Eigen::VectorXd& u);
    void update(const Eigen::VectorXd& z);
    Eigen::VectorXd getState() const;


private:
    Eigen::VectorXd mu_t;  // State estimate
    Eigen::MatrixXd Sigma_t;  // State covariance
    Eigen::MatrixXd A_t;  // State transition model
    Eigen::MatrixXd B_t;  // Control input model
    Eigen::MatrixXd R_t;  // Process noise covariance
    Eigen::MatrixXd C_t;  // Observation model
    Eigen::MatrixXd Q_t;  // Measurement noise covariance
};
