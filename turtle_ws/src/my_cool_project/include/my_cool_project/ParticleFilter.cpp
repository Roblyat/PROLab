// ParticleFilter.cpp
#include "ParticleFilter.h" 

// Constructor for the ParticleFilter class
ParticleFilter::ParticleFilter(ros::NodeHandle &N) : nh(N), num_particles_(400)
{
    // Subscribe to odometry, laser scan, and map topics
    odom_sub = nh.subscribe("/odom", 1, &ParticleFilter::odomCallback, this);
    laser_sub= nh.subscribe("/scan", 10, &ParticleFilter::laserScanCallback, this);
    map_sub = nh.subscribe("/map", 1, &ParticleFilter::mapCallback, this);

    // Advertise particle, corrected pose, and debug topics
    particles_pub = nh.advertise<geometry_msgs::PoseArray>("particles", 30);
    debug_pub = nh.advertise<my_cool_project::debug>("debug", 30);
    ROS_INFO("Debug publisher initialized with topic: %s", debug_pub.getTopic().c_str());

    // Initialize a timer for periodic debug information publishing
    debug_timer = nh.createTimer(ros::Duration(debug_interval), &ParticleFilter::debugTimerCallback, this);

    // Publish the initial set of particles
    publishParticles();
}

// Callback function for odometry messages
void ParticleFilter::odomCallback(const nav_msgs::Odometry::ConstPtr &msg)
{
    odom = *msg; // Store the received odometry message

    // Calculate the time difference (dt) since the last message
    ros::Time current_time = msg->header.stamp;
    dt = 0;
    if (last_time.isValid())
    {
        dt = (current_time - last_time).toSec(); // Calculate time difference
    }
    last_time = current_time;

    // Predict the new particle states using the motion model
    motion_model.predict(odom, particles, dt);
  
    // Publish updated particles
    publishParticles();
}

// Callback function for laser scan messages
void ParticleFilter::laserScanCallback(const sensor_msgs::LaserScan::ConstPtr &scan_msg) {
    // Correct particle weights using sensor model based on laser scan data
    sensor_model.correct(particles, scan_msg, map_data, dt, debug); 

    // Resample particles based on updated weights
    resampleParticles(); 

    // Publish the updated particles
    publishParticles();
}

// Callback function for map messages
void ParticleFilter::mapCallback(const nav_msgs::OccupancyGrid::ConstPtr &msg) {
    static bool is_initialized = false; // Static flag to ensure one-time initialization

    // Store the map data in the member variable
    map_data = *msg;
    ROS_INFO("Map received: resolution = %.2f, width = %d, height = %d",
             map_data.info.resolution, map_data.info.width, map_data.info.height);

    // Initialize particles only once
    if (!is_initialized) {
        initializeParticles();
        is_initialized = true; // Set flag to true after first initialization
    }
}

// Function to initialize particles randomly in free space
void ParticleFilter::initializeParticles() {
    particles.clear(); // Clear existing particles

    // Find all free cells in the map
    std::vector<std::pair<float, float>> free_cells = findFreeCells(map_data);

    if (free_cells.empty()) {
        ROS_WARN("No free cells available in the map for particle initialization.");
        return;
    }

    // Set up random number generators for selecting positions and orientations
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, free_cells.size() - 1); // For random positions
    std::uniform_real_distribution<double> orientation_distribution(-M_PI, M_PI); // For random orientations
    
    bool cheat = false; // Option for cheat initialization (not used here)

    // Initialize particles with random positions and orientations
    for (int i = 0; i < num_particles_; ++i) {
        Particle particle;

        // Select a random free cell for the particle's initial position
        int cell_index = distrib(gen);
        particle.pose.position.x = free_cells[cell_index].first;
        particle.pose.position.y = free_cells[cell_index].second;

        // Assign a random orientation
        double theta = orientation_distribution(gen);

        // Convert random angle to quaternion for particle orientation
        tf::Quaternion q;
        q.setRPY(0, 0, theta); // Roll and pitch are zero in 2D
        q.normalize(); // Normalize the quaternion
        particle.pose.orientation.x = q.x();
        particle.pose.orientation.y = q.y();
        particle.pose.orientation.z = q.z();
        particle.pose.orientation.w = q.w();

        // Initialize the particle weight uniformly
        particle.weight = 1.0 / num_particles_; 

        // Initialize custom vector properties for visualization
        particle.vector.origin = particle.pose.position;
        particle.vector.end.x = particle.pose.position.x + cos(theta);
        particle.vector.end.y = particle.pose.position.y + sin(theta);
        particle.vector.angle = theta; 
        particle.vector.lenth = sqrt(pow(particle.vector.end.x - particle.vector.origin.x, 2) +
                                     pow(particle.vector.end.y - particle.vector.origin.y, 2));

        // Add the initialized particle to the list
        particles.push_back(particle);
    }
}

// Helper function to find free cells in the map for particle initialization
std::vector<std::pair<float, float>> ParticleFilter::findFreeCells(const nav_msgs::OccupancyGrid &map) {
    std::vector<std::pair<float, float>> free_cells;
    // Iterate through the map to find all free cells (cells with value 0)
    for (unsigned int y = 0; y < map.info.height; y++) {
        for (unsigned int x = 0; x < map.info.width; x++) {
            int index = x + y * map.info.width;
            if (map.data[index] == 0) { // 0 means the cell is free
                float world_x = map.info.origin.position.x + (x + 0.5) * map.info.resolution;
                float world_y = map.info.origin.position.y + (y + 0.5) * map.info.resolution;
                free_cells.emplace_back(world_x, world_y);
            }
        }
    }
    return free_cells;
}

// Function to resample particles based on their weights
void ParticleFilter::resampleParticles() {
    std::vector<Particle> new_particles;

    // Prepare for resampling by setting up random number generators
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a weight distribution for resampling
    std::vector<double> weights;
    weights.reserve(particles.size());
    for (const auto& particle : particles) {
        weights.push_back(particle.weight);
    }
    std::discrete_distribution<> distribution(weights.begin(), weights.end());

    // Determine number of random particles to add
    double percentage_rand_particles = 0.1;  // Example: 10% random particles
    int num_random_particles = static_cast<int>(particles.size() * percentage_rand_particles);
    int num_resampled_particles = particles.size() - num_random_particles;

    // Set standard deviations for adding noise during resampling
    double std_dev_position = 0.2; // Standard deviation for x and y
    double std_dev_theta = M_PI / 36; // Standard deviation for theta (5 degrees)
    std::normal_distribution<> gauss_x(0, std_dev_position);
    std::normal_distribution<> gauss_y(0, std_dev_position);
    std::normal_distribution<> gauss_theta(0, std_dev_theta);

    // Resample particles with added Gaussian noise
    for (int i = 0; i < num_resampled_particles; ++i) {
        Particle original = particles[distribution(gen)];
        double x = original.pose.position.x + gauss_x(gen);
        double y = original.pose.position.y + gauss_y(gen);
        double theta = tf::getYaw(original.pose.orientation) + gauss_theta(gen);

        // Normalize theta to the range [-π, π]
        theta = std::fmod(theta, 2 * M_PI);
        if (theta > M_PI) theta -= 2 * M_PI;
        else if (theta < -M_PI) theta += 2 * M_PI;

        // Create new particle with updated pose
        Particle new_particle;
        new_particle.pose.position.x = x;
        new_particle.pose.position.y = y;
        tf::Quaternion q;
        q.setRPY(0, 0, theta);
        q.normalize();
        new_particle.pose.orientation.x = q.x();
        new_particle.pose.orientation.y = q.y();
        new_particle.pose.orientation.z = q.z();
        new_particle.pose.orientation.w = q.w();
        new_particle.weight = 1.0 / particles.size(); // Reset weight

        new_particles.push_back(new_particle);
    }

    // Add completely random particles to the new particle set
    std::uniform_real_distribution<double> dist_x(map_data.info.origin.position.x,
                                                  map_data.info.origin.position.x + map_data.info.width * map_data.info.resolution);
    std::uniform_real_distribution<double> dist_y(map_data.info.origin.position.y,
                                                  map_data.info.origin.position.y + map_data.info.height * map_data.info.resolution);
    std::uniform_real_distribution<double> dist_theta(-M_PI, M_PI);

    for (int i = 0; i < num_random_particles; ++i) {
        Particle random_particle;
        random_particle.pose.position.x = dist_x(gen);
        random_particle.pose.position.y = dist_y(gen);
        double theta = dist_theta(gen);
        tf::Quaternion q;
        q.setRPY(0, 0, theta);
        q.normalize();
        random_particle.pose.orientation.x = q.x();
        random_particle.pose.orientation.y = q.y();
        random_particle.pose.orientation.z = q.z();
        random_particle.pose.orientation.w = q.w();
        random_particle.weight = 1.0 / particles.size(); // Reset weight

        new_particles.push_back(random_particle);
    }

    // Replace the old particle set with the new resampled set
    particles = new_particles;

    ROS_INFO("Particles resampled successfully.");
}

// Function to publish the current set of particles for visualization
void ParticleFilter::publishParticles() {
    if (!particles_pub) {
        ROS_WARN("Particle publisher is not initialized properly.");
        return;
    }

    // Prepare PoseArray message to publish particles
    geometry_msgs::PoseArray particles_msg;
    particles_msg.header.stamp = ros::Time::now();
    particles_msg.header.frame_id = "map";

    // Add particle poses to the message
    for (const auto& particle : particles) {
        particles_msg.poses.push_back(particle.pose);
    }

    particles_pub.publish(particles_msg);
}

// Function to publish debug information about the particle filter's state
void ParticleFilter::publishDebugInfo(const std::string &step_name) {
    if (!debug_pub) {
        ROS_WARN("Debug publisher is not initialized properly.");
        return;
    }

    my_cool_project::debug debug_msg;
    debug_msg.header.stamp = ros::Time::now();
    debug_msg.header.frame_id = "map";

    // Fill in the robot's current pose
    debug_msg.robot_pose.x = odom.pose.pose.position.x;
    debug_msg.robot_pose.y = odom.pose.pose.position.y;
    debug_msg.robot_pose.theta = tf::getYaw(odom.pose.pose.orientation);

    // Calculate time elapsed since the last debug message
    static ros::Time last_debug_time = ros::Time::now();
    debug_msg.time_elapsed_since_last_debug = (ros::Time::now() - last_debug_time).toSec();
    last_debug_time = ros::Time::now();

    // Include beam information for specific angles of interest
    std::vector<int> indices_of_interest = {0, 89, 179, 269};

    for (int index : indices_of_interest) {
        if (index < debug.beam_angles.size()) {
            debug_msg.beam_angles.push_back(debug.beam_angles[index]);
            debug_msg.beam_hits.push_back(debug.beam_hits_dist[index]);
            debug_msg.beam_expected.push_back(debug.beam_expected_dist[index]);
            debug_msg.beam_probabilities.push_back(debug.beam_probabilities[index]);

            geometry_msgs::Pose2D hit_position;
            hit_position.x = debug.beam_hit_positions[index].x;
            hit_position.y = debug.beam_hit_positions[index].y;
            hit_position.theta = debug.beam_angles[index];
            debug_msg.beam_hit_positions.push_back(hit_position);
        } else {
            ROS_WARN("Index %d is out of bounds for beam data arrays.", index);
        }
    }

    debug_msg.step_name = step_name;

    // Publish the debug message
    debug_pub.publish(debug_msg);
}

// Callback for the debug timer, triggers periodic debug information publishing
void ParticleFilter::debugTimerCallback(const ros::TimerEvent& event) {
    publishDebugInfo("Timer Callback");
}
