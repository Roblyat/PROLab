;; Auto-generated. Do not edit!


(when (boundp 'my_cool_project::WorldFrame)
  (if (not (find-package "MY_COOL_PROJECT"))
    (make-package "MY_COOL_PROJECT"))
  (shadow 'WorldFrame (find-package "MY_COOL_PROJECT")))
(unless (find-package "MY_COOL_PROJECT::WORLDFRAME")
  (make-package "MY_COOL_PROJECT::WORLDFRAME"))

(in-package "ROS")
;;//! \htmlinclude WorldFrame.msg.html


(defclass my_cool_project::WorldFrame
  :super ros::object
  :slots ())

(defmethod my_cool_project::WorldFrame
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(setf (get my_cool_project::WorldFrame :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get my_cool_project::WorldFrame :datatype-) "my_cool_project/WorldFrame")
(setf (get my_cool_project::WorldFrame :definition-)
      "

")



(provide :my_cool_project/WorldFrame "d41d8cd98f00b204e9800998ecf8427e")


