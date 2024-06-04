;; Auto-generated. Do not edit!


(when (boundp 'my_cool_project::custom)
  (if (not (find-package "MY_COOL_PROJECT"))
    (make-package "MY_COOL_PROJECT"))
  (shadow 'custom (find-package "MY_COOL_PROJECT")))
(unless (find-package "MY_COOL_PROJECT::CUSTOM")
  (make-package "MY_COOL_PROJECT::CUSTOM"))

(in-package "ROS")
;;//! \htmlinclude custom.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass my_cool_project::custom
  :super ros::object
  :slots (_pose _velocity _covVelocity _covPose ))

(defmethod my_cool_project::custom
  (:init
   (&key
    ((:pose __pose) (instance geometry_msgs::Pose2D :init))
    ((:velocity __velocity) (instance geometry_msgs::Twist :init))
    ((:covVelocity __covVelocity) 0.0)
    ((:covPose __covPose) 0.0)
    )
   (send-super :init)
   (setq _pose __pose)
   (setq _velocity __velocity)
   (setq _covVelocity (float __covVelocity))
   (setq _covPose (float __covPose))
   self)
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:velocity
   (&rest __velocity)
   (if (keywordp (car __velocity))
       (send* _velocity __velocity)
     (progn
       (if __velocity (setq _velocity (car __velocity)))
       _velocity)))
  (:covVelocity
   (&optional __covVelocity)
   (if __covVelocity (setq _covVelocity __covVelocity)) _covVelocity)
  (:covPose
   (&optional __covPose)
   (if __covPose (setq _covPose __covPose)) _covPose)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose2D _pose
    (send _pose :serialization-length)
    ;; geometry_msgs/Twist _velocity
    (send _velocity :serialization-length)
    ;; float64 _covVelocity
    8
    ;; float64 _covPose
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose2D _pose
       (send _pose :serialize s)
     ;; geometry_msgs/Twist _velocity
       (send _velocity :serialize s)
     ;; float64 _covVelocity
       (sys::poke _covVelocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _covPose
       (sys::poke _covPose (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose2D _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;; geometry_msgs/Twist _velocity
     (send _velocity :deserialize buf ptr-) (incf ptr- (send _velocity :serialization-length))
   ;; float64 _covVelocity
     (setq _covVelocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _covPose
     (setq _covPose (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get my_cool_project::custom :md5sum-) "87669b4932b8fa165d30f2a8d3607b44")
(setf (get my_cool_project::custom :datatype-) "my_cool_project/custom")
(setf (get my_cool_project::custom :definition-)
      "geometry_msgs/Pose2D pose
geometry_msgs/Twist velocity
float64 covVelocity
float64 covPose
================================================================================
MSG: geometry_msgs/Pose2D
# Deprecated
# Please use the full 3D pose.

# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.

# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.


# This expresses a position and orientation on a 2D manifold.

float64 x
float64 y
float64 theta

================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :my_cool_project/custom "87669b4932b8fa165d30f2a8d3607b44")


