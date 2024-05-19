; Auto-generated. Do not edit!


(cl:in-package my_cool_project-msg)


;//! \htmlinclude WorldFrame.msg.html

(cl:defclass <WorldFrame> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass WorldFrame (<WorldFrame>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WorldFrame>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WorldFrame)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_cool_project-msg:<WorldFrame> is deprecated: use my_cool_project-msg:WorldFrame instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WorldFrame>) ostream)
  "Serializes a message object of type '<WorldFrame>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WorldFrame>) istream)
  "Deserializes a message object of type '<WorldFrame>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WorldFrame>)))
  "Returns string type for a message object of type '<WorldFrame>"
  "my_cool_project/WorldFrame")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WorldFrame)))
  "Returns string type for a message object of type 'WorldFrame"
  "my_cool_project/WorldFrame")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WorldFrame>)))
  "Returns md5sum for a message object of type '<WorldFrame>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WorldFrame)))
  "Returns md5sum for a message object of type 'WorldFrame"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WorldFrame>)))
  "Returns full string definition for message of type '<WorldFrame>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WorldFrame)))
  "Returns full string definition for message of type 'WorldFrame"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WorldFrame>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WorldFrame>))
  "Converts a ROS message object to a list"
  (cl:list 'WorldFrame
))
