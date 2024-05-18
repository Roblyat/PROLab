#include "kalmanFilter.h"

KalmanFilter::KalmanFilter() {
  // Initialize state and covariance
  mu_t = Eigen::VectorXd::Zero(3);  // Assuming [x, y, theta]
  Sigma_t = Eigen::MatrixXd::Identity(3, 3);

  // Initialize models (example values, you should set these according to your system)
  A_t = Eigen::MatrixXd::Identity(3, 3);
  B_t = Eigen::MatrixXd::Zero(3, 2);
  R_t = 0.01 * Eigen::MatrixXd::Identity(3, 3);
  C_t = Eigen::MatrixXd::Identity(3, 3);
  Q_t = 0.1 * Eigen::MatrixXd::Identity(3, 3);
}

void KalmanFilter::predict(const Eigen::VectorXd& u) {
  mu_t = A_t * mu_t + B_t * u;
  Sigma_t = A_t * Sigma_t * A_t.transpose() + R_t;
}

void KalmanFilter::update(const Eigen::VectorXd& z) {
  Eigen::MatrixXd K_t = Sigma_t * C_t.transpose() * (C_t * Sigma_t * C_t.transpose() + Q_t).inverse();
  mu_t = mu_t + K_t * (z - C_t * mu_t);
  Sigma_t = (Eigen::MatrixXd::Identity(3, 3) - K_t * C_t) * Sigma_t;
}

Eigen::VectorXd KalmanFilter::getState() const {
  return mu_t;
}
