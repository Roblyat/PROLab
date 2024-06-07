// Generated by gencpp from file my_cool_project/custom.msg
// DO NOT EDIT!


#ifndef MY_COOL_PROJECT_MESSAGE_CUSTOM_H
#define MY_COOL_PROJECT_MESSAGE_CUSTOM_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Twist.h>

namespace my_cool_project
{
template <class ContainerAllocator>
struct custom_
{
  typedef custom_<ContainerAllocator> Type;

  custom_()
    : pose()
    , velocity()
    , covariance()  {
      covariance.assign(0.0);
  }
  custom_(const ContainerAllocator& _alloc)
    : pose(_alloc)
    , velocity(_alloc)
    , covariance()  {
  (void)_alloc;
      covariance.assign(0.0);
  }



   typedef  ::geometry_msgs::Pose2D_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _velocity_type;
  _velocity_type velocity;

   typedef boost::array<double, 36>  _covariance_type;
  _covariance_type covariance;





  typedef boost::shared_ptr< ::my_cool_project::custom_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::my_cool_project::custom_<ContainerAllocator> const> ConstPtr;

}; // struct custom_

typedef ::my_cool_project::custom_<std::allocator<void> > custom;

typedef boost::shared_ptr< ::my_cool_project::custom > customPtr;
typedef boost::shared_ptr< ::my_cool_project::custom const> customConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::my_cool_project::custom_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::my_cool_project::custom_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::my_cool_project::custom_<ContainerAllocator1> & lhs, const ::my_cool_project::custom_<ContainerAllocator2> & rhs)
{
  return lhs.pose == rhs.pose &&
    lhs.velocity == rhs.velocity &&
    lhs.covariance == rhs.covariance;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::my_cool_project::custom_<ContainerAllocator1> & lhs, const ::my_cool_project::custom_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace my_cool_project

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::my_cool_project::custom_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_cool_project::custom_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_cool_project::custom_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_cool_project::custom_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_cool_project::custom_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_cool_project::custom_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::my_cool_project::custom_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8459995fd53fcae095e12638a1f2300c";
  }

  static const char* value(const ::my_cool_project::custom_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8459995fd53fcae0ULL;
  static const uint64_t static_value2 = 0x95e12638a1f2300cULL;
};

template<class ContainerAllocator>
struct DataType< ::my_cool_project::custom_<ContainerAllocator> >
{
  static const char* value()
  {
    return "my_cool_project/custom";
  }

  static const char* value(const ::my_cool_project::custom_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::my_cool_project::custom_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Pose2D pose\n"
"geometry_msgs/Twist velocity\n"
"float64[36] covariance\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose2D\n"
"# Deprecated\n"
"# Please use the full 3D pose.\n"
"\n"
"# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.\n"
"\n"
"# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.\n"
"\n"
"\n"
"# This expresses a position and orientation on a 2D manifold.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 theta\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Twist\n"
"# This expresses velocity in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::my_cool_project::custom_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::my_cool_project::custom_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pose);
      stream.next(m.velocity);
      stream.next(m.covariance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct custom_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::my_cool_project::custom_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::my_cool_project::custom_<ContainerAllocator>& v)
  {
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose2D_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.velocity);
    s << indent << "covariance[]" << std::endl;
    for (size_t i = 0; i < v.covariance.size(); ++i)
    {
      s << indent << "  covariance[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.covariance[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MY_COOL_PROJECT_MESSAGE_CUSTOM_H