#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperForceServoCommand_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperForceServoCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperForceServoCommand : public ros::Msg
  {
    public:
      double fingertip_force;

    PR2GripperForceServoCommand():
      fingertip_force(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_fingertip_force;
      u_fingertip_force.real = this->fingertip_force;
      *(outbuffer + offset + 0) = (u_fingertip_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fingertip_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fingertip_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fingertip_force.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_fingertip_force.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_fingertip_force.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_fingertip_force.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_fingertip_force.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->fingertip_force);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_fingertip_force;
      u_fingertip_force.base = 0;
      u_fingertip_force.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fingertip_force.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fingertip_force.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fingertip_force.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_fingertip_force.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_fingertip_force.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_fingertip_force.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_fingertip_force.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->fingertip_force = u_fingertip_force.real;
      offset += sizeof(this->fingertip_force);
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperForceServoCommand"; };
    const char * getMD5(){ return "dd4b2a0dfafa27b67d2002841f544379"; };

  };

}
#endif