
(cl:in-package :asdf)

(defsystem "my_cool_project-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "WorldFrame" :depends-on ("_package_WorldFrame"))
    (:file "_package_WorldFrame" :depends-on ("_package"))
  ))