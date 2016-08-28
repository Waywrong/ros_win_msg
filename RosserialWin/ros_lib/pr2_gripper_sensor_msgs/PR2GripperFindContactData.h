#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperFindContactData_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperFindContactData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "pr2_gripper_sensor_msgs/PR2GripperSensorRTState.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperFindContactData : public ros::Msg
  {
    public:
      ros::Time stamp;
      bool contact_conditions_met;
      bool left_fingertip_pad_contact;
      bool right_fingertip_pad_contact;
      double left_fingertip_pad_force;
      double right_fingertip_pad_force;
      double joint_position;
      double joint_effort;
      pr2_gripper_sensor_msgs::PR2GripperSensorRTState rtstate;

    PR2GripperFindContactData():
      stamp(),
      contact_conditions_met(0),
      left_fingertip_pad_contact(0),
      right_fingertip_pad_contact(0),
      left_fingertip_pad_force(0),
      right_fingertip_pad_force(0),
      joint_position(0),
      joint_effort(0),
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
        bool real;
        uint8_t base;
      } u_contact_conditions_met;
      u_contact_conditions_met.real = this->contact_conditions_met;
      *(outbuffer + offset + 0) = (u_contact_conditions_met.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contact_conditions_met);
      union {
        bool real;
        uint8_t base;
      } u_left_fingertip_pad_contact;
      u_left_fingertip_pad_contact.real = this->left_fingertip_pad_contact;
      *(outbuffer + offset + 0) = (u_left_fingertip_pad_contact.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_fingertip_pad_contact);
      union {
        bool real;
        uint8_t base;
      } u_right_fingertip_pad_contact;
      u_right_fingertip_pad_contact.real = this->right_fingertip_pad_contact;
      *(outbuffer + offset + 0) = (u_right_fingertip_pad_contact.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_fingertip_pad_contact);
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
      } u_joint_position;
      u_joint_position.real = this->joint_position;
      *(outbuffer + offset + 0) = (u_joint_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_joint_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_joint_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_joint_position.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_joint_position.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_joint_position.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_joint_position.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_joint_position.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->joint_position);
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
        bool real;
        uint8_t base;
      } u_contact_conditions_met;
      u_contact_conditions_met.base = 0;
      u_contact_conditions_met.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contact_conditions_met = u_contact_conditions_met.real;
      offset += sizeof(this->contact_conditions_met);
      union {
        bool real;
        uint8_t base;
      } u_left_fingertip_pad_contact;
      u_left_fingertip_pad_contact.base = 0;
      u_left_fingertip_pad_contact.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_fingertip_pad_contact = u_left_fingertip_pad_contact.real;
      offset += sizeof(this->left_fingertip_pad_contact);
      union {
        bool real;
        uint8_t base;
      } u_right_fingertip_pad_contact;
      u_right_fingertip_pad_contact.base = 0;
      u_right_fingertip_pad_contact.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_fingertip_pad_contact = u_right_fingertip_pad_contact.real;
      offset += sizeof(this->right_fingertip_pad_contact);
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
      } u_joint_position;
      u_joint_position.base = 0;
      u_joint_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_joint_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_joint_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_joint_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_joint_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_joint_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_joint_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_joint_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->joint_position = u_joint_position.real;
      offset += sizeof(this->joint_position);
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
      offset += this->rtstate.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperFindContactData"; };
    const char * getMD5(){ return "bc53e3dc7d19b896ca9b5ea205d54b91"; };

  };

}
#endif