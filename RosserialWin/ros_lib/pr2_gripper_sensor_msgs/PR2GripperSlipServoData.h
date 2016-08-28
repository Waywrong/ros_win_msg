#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperSlipServoData_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperSlipServoData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "pr2_gripper_sensor_msgs/PR2GripperSensorRTState.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperSlipServoData : public ros::Msg
  {
    public:
      ros::Time stamp;
      double deformation;
      double left_fingertip_pad_force;
      double right_fingertip_pad_force;
      double joint_effort;
      bool slip_detected;
      bool deformation_limit_reached;
      bool fingertip_force_limit_reached;
      bool gripper_empty;
      pr2_gripper_sensor_msgs::PR2GripperSensorRTState rtstate;

    PR2GripperSlipServoData():
      stamp(),
      deformation(0),
      left_fingertip_pad_force(0),
      right_fingertip_pad_force(0),
      joint_effort(0),
      slip_detected(0),
      deformation_limit_reached(0),
      fingertip_force_limit_reached(0),
      gripper_empty(0),
      rtstate()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      union {
        double real;
        uint64_t base;
      } u_deformation;
      u_deformation.real = this->deformation;
      *(outbuffer + offset + 0) = (u_deformation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deformation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deformation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deformation.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_deformation.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_deformation.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_deformation.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_deformation.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->deformation);
      union {
        double real;
        uint64_t base;
      } u_left_fingertip_pad_force;
      u_left_fingertip_pad_force.real = this->left_fingertip_pad_force;
      *(outbuffer + offset + 0) = (u_left_fingertip_pad_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_fingertip_pad_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_fingertip_pad_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_fingertip_pad_force.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_fingertip_pad_force.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_fingertip_pad_force.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_fingertip_pad_force.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_fingertip_pad_force.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_fingertip_pad_force);
      union {
        double real;
        uint64_t base;
      } u_right_fingertip_pad_force;
      u_right_fingertip_pad_force.real = this->right_fingertip_pad_force;
      *(outbuffer + offset + 0) = (u_right_fingertip_pad_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_fingertip_pad_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_fingertip_pad_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_fingertip_pad_force.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_fingertip_pad_force.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_fingertip_pad_force.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_fingertip_pad_force.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_fingertip_pad_force.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_fingertip_pad_force);
      union {
        double real;
        uint64_t base;
      } u_joint_effort;
      u_joint_effort.real = this->joint_effort;
      *(outbuffer + offset + 0) = (u_joint_effort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_joint_effort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_joint_effort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_joint_effort.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_joint_effort.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_joint_effort.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_joint_effort.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_joint_effort.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->joint_effort);
      union {
        bool real;
        uint8_t base;
      } u_slip_detected;
      u_slip_detected.real = this->slip_detected;
      *(outbuffer + offset + 0) = (u_slip_detected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->slip_detected);
      union {
        bool real;
        uint8_t base;
      } u_deformation_limit_reached;
      u_deformation_limit_reached.real = this->deformation_limit_reached;
      *(outbuffer + offset + 0) = (u_deformation_limit_reached.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->deformation_limit_reached);
      union {
        bool real;
        uint8_t base;
      } u_fingertip_force_limit_reached;
      u_fingertip_force_limit_reached.real = this->fingertip_force_limit_reached;
      *(outbuffer + offset + 0) = (u_fingertip_force_limit_reached.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fingertip_force_limit_reached);
      union {
        bool real;
        uint8_t base;
      } u_gripper_empty;
      u_gripper_empty.real = this->gripper_empty;
      *(outbuffer + offset + 0) = (u_gripper_empty.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gripper_empty);
      offset += this->rtstate.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      union {
        double real;
        uint64_t base;
      } u_deformation;
      u_deformation.base = 0;
      u_deformation.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deformation.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deformation.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deformation.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_deformation.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_deformation.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_deformation.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_deformation.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->deformation = u_deformation.real;
      offset += sizeof(this->deformation);
      union {
        double real;
        uint64_t base;
      } u_left_fingertip_pad_force;
      u_left_fingertip_pad_force.base = 0;
      u_left_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_fingertip_pad_force = u_left_fingertip_pad_force.real;
      offset += sizeof(this->left_fingertip_pad_force);
      union {
        double real;
        uint64_t base;
      } u_right_fingertip_pad_force;
      u_right_fingertip_pad_force.base = 0;
      u_right_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_fingertip_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_fingertip_pad_force = u_right_fingertip_pad_force.real;
      offset += sizeof(this->right_fingertip_pad_force);
      union {
        double real;
        uint64_t base;
      } u_joint_effort;
      u_joint_effort.base = 0;
      u_joint_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_joint_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_joint_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_joint_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_joint_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_joint_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_joint_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_joint_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->joint_effort = u_joint_effort.real;
      offset += sizeof(this->joint_effort);
      union {
        bool real;
        uint8_t base;
      } u_slip_detected;
      u_slip_detected.base = 0;
      u_slip_detected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->slip_detected = u_slip_detected.real;
      offset += sizeof(this->slip_detected);
      union {
        bool real;
        uint8_t base;
      } u_deformation_limit_reached;
      u_deformation_limit_reached.base = 0;
      u_deformation_limit_reached.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->deformation_limit_reached = u_deformation_limit_reached.real;
      offset += sizeof(this->deformation_limit_reached);
      union {
        bool real;
        uint8_t base;
      } u_fingertip_force_limit_reached;
      u_fingertip_force_limit_reached.base = 0;
      u_fingertip_force_limit_reached.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fingertip_force_limit_reached = u_fingertip_force_limit_reached.real;
      offset += sizeof(this->fingertip_force_limit_reached);
      union {
        bool real;
        uint8_t base;
      } u_gripper_empty;
      u_gripper_empty.base = 0;
      u_gripper_empty.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gripper_empty = u_gripper_empty.real;
      offset += sizeof(this->gripper_empty);
      offset += this->rtstate.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperSlipServoData"; };
    const char * getMD5(){ return "a49728a2e0c40706b3c9b74046f006aa"; };

  };

}
#endif