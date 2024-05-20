# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "my_cool_project: 1 messages, 0 services")

set(MSG_I_FLAGS "-Imy_cool_project:/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(my_cool_project_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg" NAME_WE)
add_custom_target(_my_cool_project_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_cool_project" "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(my_cool_project
  "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_cool_project
)

### Generating Services

### Generating Module File
_generate_module_cpp(my_cool_project
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_cool_project
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(my_cool_project_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(my_cool_project_generate_messages my_cool_project_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg" NAME_WE)
add_dependencies(my_cool_project_generate_messages_cpp _my_cool_project_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(my_cool_project_gencpp)
add_dependencies(my_cool_project_gencpp my_cool_project_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_cool_project_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(my_cool_project
  "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_cool_project
)

### Generating Services

### Generating Module File
_generate_module_eus(my_cool_project
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_cool_project
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(my_cool_project_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(my_cool_project_generate_messages my_cool_project_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg" NAME_WE)
add_dependencies(my_cool_project_generate_messages_eus _my_cool_project_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(my_cool_project_geneus)
add_dependencies(my_cool_project_geneus my_cool_project_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_cool_project_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(my_cool_project
  "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_cool_project
)

### Generating Services

### Generating Module File
_generate_module_lisp(my_cool_project
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_cool_project
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(my_cool_project_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(my_cool_project_generate_messages my_cool_project_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg" NAME_WE)
add_dependencies(my_cool_project_generate_messages_lisp _my_cool_project_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(my_cool_project_genlisp)
add_dependencies(my_cool_project_genlisp my_cool_project_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_cool_project_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(my_cool_project
  "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_cool_project
)

### Generating Services

### Generating Module File
_generate_module_nodejs(my_cool_project
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_cool_project
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(my_cool_project_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(my_cool_project_generate_messages my_cool_project_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg" NAME_WE)
add_dependencies(my_cool_project_generate_messages_nodejs _my_cool_project_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(my_cool_project_gennodejs)
add_dependencies(my_cool_project_gennodejs my_cool_project_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_cool_project_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(my_cool_project
  "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_cool_project
)

### Generating Services

### Generating Module File
_generate_module_py(my_cool_project
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_cool_project
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(my_cool_project_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(my_cool_project_generate_messages my_cool_project_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/msg/WorldFrame.msg" NAME_WE)
add_dependencies(my_cool_project_generate_messages_py _my_cool_project_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(my_cool_project_genpy)
add_dependencies(my_cool_project_genpy my_cool_project_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_cool_project_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_cool_project)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_cool_project
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(my_cool_project_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(my_cool_project_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_cool_project)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_cool_project
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(my_cool_project_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(my_cool_project_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_cool_project)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_cool_project
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(my_cool_project_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(my_cool_project_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_cool_project)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_cool_project
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(my_cool_project_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(my_cool_project_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_cool_project)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_cool_project\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_cool_project
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(my_cool_project_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(my_cool_project_generate_messages_py geometry_msgs_generate_messages_py)
endif()
