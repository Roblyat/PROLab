
(cl:in-package :asdf)

(defsystem "my_cool_project-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "custom" :depends-on ("_package_custom"))
    (:file "_package_custom" :depends-on ("_package"))
  ))