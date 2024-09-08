# debug.msg

# Standard ROS header with timestamp and frame_id
Header header

# Robot pose information
geometry_msgs/Pose2D robot_pose          # Current pose of the robot (x, y, theta)

# ----------------------------------------------------------------------
# Particle Filter Information
# ----------------------------------------------------------------------

# Particle states and weights
geometry_msgs/Pose2D[] particle_poses    # Array of particle poses (x, y, theta)
float64[] particle_weights               # Weights for each particle (normalized to sum to 1)

# Vector information for each particle (used for debugging visualization)
geometry_msgs/Point[] vector_origins     # Origins of vectors for each particle (start points)
geometry_msgs/Point[] vector_ends        # Endpoints of vectors for each particle (end points)

# ----------------------------------------------------------------------
# Beam Measurement Information (Laser Scan Data)
# ----------------------------------------------------------------------

# Angles and measurements of laser beams relative to the robot's frame
float64[] beam_angles                    # Angles of beams (radians) from the laser scanner
float64[] beam_hits                      # Measured distances from the robot to the nearest obstacles
float64[] beam_expected                  # Expected distances to obstacles based on particle poses
geometry_msgs/Pose2D[] beam_hit_positions # Positions where each beam hit an obstacle (x, y, theta)
float64[] beam_probabilities             # Probabilities associated with each beam measurement 

# ----------------------------------------------------------------------
# Additional Information
# ----------------------------------------------------------------------

string step_name                         # Name of the current processing step (e.g., "After Correction")
float64 time_elapsed_since_last_debug    # Time since the last debug message was published (seconds)
