#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperGrabCommand_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperGrabCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperGrabCommand : public ros::Msg
  {
    public:
      double hardness_gain;

    PR2GripperGrabCommand():
      hardness_gain(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_hardness_gain;
      u_hardness_gain.real = this->hardness_gain;
      *(outbuffer + offset + 0) = (u_hardness_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hardness_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hardness_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hardness_gain.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hardness_gain.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hardness_gain.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hardness_gain.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hardness_gain.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hardness_gain);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_hardness_gain;
      u_hardness_gain.base = 0;
      u_hardness_gain.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hardness_gain.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hardness_gain.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hardness_gain.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hardness_gain.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hardness_gain.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hardness_gain.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hardness_gain.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hardness_gain = u_hardness_gain.real;
      offset += sizeof(this->hardness_gain);
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperGrabCommand"; };
    const char * getMD5(){ return "cf286b093615060c79527896d36bf694"; };

  };

}
#endif