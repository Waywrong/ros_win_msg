#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperPressureData_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperPressureData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperPressureData : public ros::Msg
  {
    public:
      double pressure_left[22];
      double pressure_right[22];
      double rostime;

    PR2GripperPressureData():
      pressure_left(),
      pressure_right(),
      rostime(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_pressure_lefti;
      u_pressure_lefti.real = this->pressure_left[i];
      *(outbuffer + offset + 0) = (u_pressure_lefti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure_lefti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure_lefti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure_lefti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pressure_lefti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pressure_lefti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pressure_lefti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pressure_lefti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pressure_left[i]);
      }
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_pressure_righti;
      u_pressure_righti.real = this->pressure_right[i];
      *(outbuffer + offset + 0) = (u_pressure_righti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure_righti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure_righti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure_righti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pressure_righti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pressure_righti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pressure_righti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pressure_righti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pressure_right[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_rostime;
      u_rostime.real = this->rostime;
      *(outbuffer + offset + 0) = (u_rostime.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rostime.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rostime.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rostime.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rostime.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rostime.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rostime.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rostime.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rostime);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_pressure_lefti;
      u_pressure_lefti.base = 0;
      u_pressure_lefti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressure_lefti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressure_lefti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressure_lefti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pressure_lefti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pressure_lefti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pressure_lefti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pressure_lefti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pressure_left[i] = u_pressure_lefti.real;
      offset += sizeof(this->pressure_left[i]);
      }
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_pressure_righti;
      u_pressure_righti.base = 0;
      u_pressure_righti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressure_righti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressure_righti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressure_righti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pressure_righti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pressure_righti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pressure_righti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pressure_righti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pressure_right[i] = u_pressure_righti.real;
      offset += sizeof(this->pressure_right[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_rostime;
      u_rostime.base = 0;
      u_rostime.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rostime.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rostime.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rostime.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rostime.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rostime.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rostime.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rostime.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rostime = u_rostime.real;
      offset += sizeof(this->rostime);
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperPressureData"; };
    const char * getMD5(){ return "b69255f5117bf05fdcd1e83d4e6ab779"; };

  };

}
#endif