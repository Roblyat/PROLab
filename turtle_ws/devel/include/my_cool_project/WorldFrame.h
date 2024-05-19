// Generated by gencpp from file my_cool_project/WorldFrame.msg
// DO NOT EDIT!


#ifndef MY_COOL_PROJECT_MESSAGE_WORLDFRAME_H
#define MY_COOL_PROJECT_MESSAGE_WORLDFRAME_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace my_cool_project
{
template <class ContainerAllocator>
struct WorldFrame_
{
  typedef WorldFrame_<ContainerAllocator> Type;

  WorldFrame_()
    {
    }
  WorldFrame_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::my_cool_project::WorldFrame_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::my_cool_project::WorldFrame_<ContainerAllocator> const> ConstPtr;

}; // struct WorldFrame_

typedef ::my_cool_project::WorldFrame_<std::allocator<void> > WorldFrame;

typedef boost::shared_ptr< ::my_cool_project::WorldFrame > WorldFramePtr;
typedef boost::shared_ptr< ::my_cool_project::WorldFrame const> WorldFrameConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::my_cool_project::WorldFrame_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::my_cool_project::WorldFrame_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace my_cool_project

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::my_cool_project::WorldFrame_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_cool_project::WorldFrame_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_cool_project::WorldFrame_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_cool_project::WorldFrame_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_cool_project::WorldFrame_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_cool_project::WorldFrame_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::my_cool_project::WorldFrame_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::my_cool_project::WorldFrame_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::my_cool_project::WorldFrame_<ContainerAllocator> >
{
  static const char* value()
  {
    return "my_cool_project/WorldFrame";
  }

  static const char* value(const ::my_cool_project::WorldFrame_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::my_cool_project::WorldFrame_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::my_cool_project::WorldFrame_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::my_cool_project::WorldFrame_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WorldFrame_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::my_cool_project::WorldFrame_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::my_cool_project::WorldFrame_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // MY_COOL_PROJECT_MESSAGE_WORLDFRAME_H