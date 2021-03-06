#ifndef _ROS_moveit_msgs_JointLimits_h
#define _ROS_moveit_msgs_JointLimits_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class JointLimits : public ros::Msg
  {
    public:
      const char* joint_name;
      bool has_position_limits;
      double min_position;
      double max_position;
      bool has_velocity_limits;
      double max_velocity;
      bool has_acceleration_limits;
      double max_acceleration;

    JointLimits():
      joint_name(""),
      has_position_limits(0),
      min_position(0),
      max_position(0),
      has_velocity_limits(0),
      max_velocity(0),
      has_acceleration_limits(0),
      max_acceleration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_joint_name = strlen(this->joint_name);
      memcpy(outbuffer + offset, &length_joint_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_name, length_joint_name);
      offset += length_joint_name;
      union {
        bool real;
        uint8_t base;
      } u_has_position_limits;
      u_has_position_limits.real = this->has_position_limits;
      *(outbuffer + offset + 0) = (u_has_position_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_position_limits);
      union {
        double real;
        uint64_t base;
      } u_min_position;
      u_min_position.real = this->min_position;
      *(outbuffer + offset + 0) = (u_min_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_position.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_min_position.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_min_position.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_min_position.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_min_position.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->min_position);
      union {
        double real;
        uint64_t base;
      } u_max_position;
      u_max_position.real = this->max_position;
      *(outbuffer + offset + 0) = (u_max_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_position.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_position.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_position.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_position.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_position.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_position);
      union {
        bool real;
        uint8_t base;
      } u_has_velocity_limits;
      u_has_velocity_limits.real = this->has_velocity_limits;
      *(outbuffer + offset + 0) = (u_has_velocity_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_velocity_limits);
      union {
        double real;
        uint64_t base;
      } u_max_velocity;
      u_max_velocity.real = this->max_velocity;
      *(outbuffer + offset + 0) = (u_max_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_velocity);
      union {
        bool real;
        uint8_t base;
      } u_has_acceleration_limits;
      u_has_acceleration_limits.real = this->has_acceleration_limits;
      *(outbuffer + offset + 0) = (u_has_acceleration_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_acceleration_limits);
      union {
        double real;
        uint64_t base;
      } u_max_acceleration;
      u_max_acceleration.real = this->max_acceleration;
      *(outbuffer + offset + 0) = (u_max_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_acceleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_joint_name;
      memcpy(&length_joint_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_name-1]=0;
      this->joint_name = (char *)(inbuffer + offset-1);
      offset += length_joint_name;
      union {
        bool real;
        uint8_t base;
      } u_has_position_limits;
      u_has_position_limits.base = 0;
      u_has_position_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_position_limits = u_has_position_limits.real;
      offset += sizeof(this->has_position_limits);
      union {
        double real;
        uint64_t base;
      } u_min_position;
      u_min_position.base = 0;
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->min_position = u_min_position.real;
      offset += sizeof(this->min_position);
      union {
        double real;
        uint64_t base;
      } u_max_position;
      u_max_position.base = 0;
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_position = u_max_position.real;
      offset += sizeof(this->max_position);
      union {
        bool real;
        uint8_t base;
      } u_has_velocity_limits;
      u_has_velocity_limits.base = 0;
      u_has_velocity_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_velocity_limits = u_has_velocity_limits.real;
      offset += sizeof(this->has_velocity_limits);
      union {
        double real;
        uint64_t base;
      } u_max_velocity;
      u_max_velocity.base = 0;
      u_max_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_velocity = u_max_velocity.real;
      offset += sizeof(this->max_velocity);
      union {
        bool real;
        uint8_t base;
      } u_has_acceleration_limits;
      u_has_acceleration_limits.base = 0;
      u_has_acceleration_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_acceleration_limits = u_has_acceleration_limits.real;
      offset += sizeof(this->has_acceleration_limits);
      union {
        double real;
        uint64_t base;
      } u_max_acceleration;
      u_max_acceleration.base = 0;
      u_max_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_acceleration = u_max_acceleration.real;
      offset += sizeof(this->max_acceleration);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/JointLimits"; };
    const char * getMD5(){ return "8ca618c7329ea46142cbc864a2efe856"; };

  };

}
#endif