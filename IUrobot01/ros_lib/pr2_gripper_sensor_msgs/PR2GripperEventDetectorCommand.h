#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperEventDetectorCommand_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperEventDetectorCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperEventDetectorCommand : public ros::Msg
  {
    public:
      int8_t trigger_conditions;
      double acceleration_trigger_magnitude;
      double slip_trigger_magnitude;
      enum { FINGER_SIDE_IMPACT_OR_ACC =  0 };
      enum { SLIP_AND_ACC =  1 };
      enum { FINGER_SIDE_IMPACT_OR_SLIP_OR_ACC =  2 };
      enum { SLIP =  3 };
      enum { ACC =  4 };

    PR2GripperEventDetectorCommand():
      trigger_conditions(0),
      acceleration_trigger_magnitude(0),
      slip_trigger_magnitude(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_trigger_conditions;
      u_trigger_conditions.real = this->trigger_conditions;
      *(outbuffer + offset + 0) = (u_trigger_conditions.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trigger_conditions);
      union {
        double real;
        uint64_t base;
      } u_acceleration_trigger_magnitude;
      u_acceleration_trigger_magnitude.real = this->acceleration_trigger_magnitude;
      *(outbuffer + offset + 0) = (u_acceleration_trigger_magnitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acceleration_trigger_magnitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acceleration_trigger_magnitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acceleration_trigger_magnitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acceleration_trigger_magnitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acceleration_trigger_magnitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acceleration_trigger_magnitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acceleration_trigger_magnitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acceleration_trigger_magnitude);
      union {
        double real;
        uint64_t base;
      } u_slip_trigger_magnitude;
      u_slip_trigger_magnitude.real = this->slip_trigger_magnitude;
      *(outbuffer + offset + 0) = (u_slip_trigger_magnitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_slip_trigger_magnitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_slip_trigger_magnitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_slip_trigger_magnitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_slip_trigger_magnitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_slip_trigger_magnitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_slip_trigger_magnitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_slip_trigger_magnitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->slip_trigger_magnitude);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_trigger_conditions;
      u_trigger_conditions.base = 0;
      u_trigger_conditions.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->trigger_conditions = u_trigger_conditions.real;
      offset += sizeof(this->trigger_conditions);
      union {
        double real;
        uint64_t base;
      } u_acceleration_trigger_magnitude;
      u_acceleration_trigger_magnitude.base = 0;
      u_acceleration_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acceleration_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acceleration_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acceleration_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acceleration_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acceleration_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acceleration_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acceleration_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acceleration_trigger_magnitude = u_acceleration_trigger_magnitude.real;
      offset += sizeof(this->acceleration_trigger_magnitude);
      union {
        double real;
        uint64_t base;
      } u_slip_trigger_magnitude;
      u_slip_trigger_magnitude.base = 0;
      u_slip_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_slip_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_slip_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_slip_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_slip_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_slip_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_slip_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_slip_trigger_magnitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->slip_trigger_magnitude = u_slip_trigger_magnitude.real;
      offset += sizeof(this->slip_trigger_magnitude);
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperEventDetectorCommand"; };
    const char * getMD5(){ return "b91a7e1e863671a84c1d06e0cac3146e"; };

  };

}
#endif