#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperSensorRawData_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperSensorRawData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperSensorRawData : public ros::Msg
  {
    public:
      ros::Time stamp;
      double left_finger_pad_force;
      double right_finger_pad_force;
      double left_finger_pad_force_filtered;
      double right_finger_pad_force_filtered;
      double left_finger_pad_forces[22];
      double right_finger_pad_forces[22];
      double left_finger_pad_forces_filtered[22];
      double right_finger_pad_forces_filtered[22];
      double acc_x_raw;
      double acc_y_raw;
      double acc_z_raw;
      double acc_x_filtered;
      double acc_y_filtered;
      double acc_z_filtered;
      bool left_contact;
      bool right_contact;

    PR2GripperSensorRawData():
      stamp(),
      left_finger_pad_force(0),
      right_finger_pad_force(0),
      left_finger_pad_force_filtered(0),
      right_finger_pad_force_filtered(0),
      left_finger_pad_forces(),
      right_finger_pad_forces(),
      left_finger_pad_forces_filtered(),
      right_finger_pad_forces_filtered(),
      acc_x_raw(0),
      acc_y_raw(0),
      acc_z_raw(0),
      acc_x_filtered(0),
      acc_y_filtered(0),
      acc_z_filtered(0),
      left_contact(0),
      right_contact(0)
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
      } u_left_finger_pad_force;
      u_left_finger_pad_force.real = this->left_finger_pad_force;
      *(outbuffer + offset + 0) = (u_left_finger_pad_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_finger_pad_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_finger_pad_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_finger_pad_force.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_finger_pad_force.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_finger_pad_force.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_finger_pad_force.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_finger_pad_force.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_finger_pad_force);
      union {
        double real;
        uint64_t base;
      } u_right_finger_pad_force;
      u_right_finger_pad_force.real = this->right_finger_pad_force;
      *(outbuffer + offset + 0) = (u_right_finger_pad_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_finger_pad_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_finger_pad_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_finger_pad_force.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_finger_pad_force.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_finger_pad_force.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_finger_pad_force.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_finger_pad_force.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_finger_pad_force);
      union {
        double real;
        uint64_t base;
      } u_left_finger_pad_force_filtered;
      u_left_finger_pad_force_filtered.real = this->left_finger_pad_force_filtered;
      *(outbuffer + offset + 0) = (u_left_finger_pad_force_filtered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_finger_pad_force_filtered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_finger_pad_force_filtered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_finger_pad_force_filtered.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_finger_pad_force_filtered.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_finger_pad_force_filtered.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_finger_pad_force_filtered.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_finger_pad_force_filtered.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_finger_pad_force_filtered);
      union {
        double real;
        uint64_t base;
      } u_right_finger_pad_force_filtered;
      u_right_finger_pad_force_filtered.real = this->right_finger_pad_force_filtered;
      *(outbuffer + offset + 0) = (u_right_finger_pad_force_filtered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_finger_pad_force_filtered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_finger_pad_force_filtered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_finger_pad_force_filtered.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_finger_pad_force_filtered.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_finger_pad_force_filtered.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_finger_pad_force_filtered.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_finger_pad_force_filtered.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_finger_pad_force_filtered);
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_left_finger_pad_forcesi;
      u_left_finger_pad_forcesi.real = this->left_finger_pad_forces[i];
      *(outbuffer + offset + 0) = (u_left_finger_pad_forcesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_finger_pad_forcesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_finger_pad_forcesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_finger_pad_forcesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_finger_pad_forcesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_finger_pad_forcesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_finger_pad_forcesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_finger_pad_forcesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_finger_pad_forces[i]);
      }
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_right_finger_pad_forcesi;
      u_right_finger_pad_forcesi.real = this->right_finger_pad_forces[i];
      *(outbuffer + offset + 0) = (u_right_finger_pad_forcesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_finger_pad_forcesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_finger_pad_forcesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_finger_pad_forcesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_finger_pad_forcesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_finger_pad_forcesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_finger_pad_forcesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_finger_pad_forcesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_finger_pad_forces[i]);
      }
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_left_finger_pad_forces_filteredi;
      u_left_finger_pad_forces_filteredi.real = this->left_finger_pad_forces_filtered[i];
      *(outbuffer + offset + 0) = (u_left_finger_pad_forces_filteredi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_finger_pad_forces_filteredi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_finger_pad_forces_filteredi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_finger_pad_forces_filteredi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_finger_pad_forces_filteredi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_finger_pad_forces_filteredi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_finger_pad_forces_filteredi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_finger_pad_forces_filteredi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_finger_pad_forces_filtered[i]);
      }
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_right_finger_pad_forces_filteredi;
      u_right_finger_pad_forces_filteredi.real = this->right_finger_pad_forces_filtered[i];
      *(outbuffer + offset + 0) = (u_right_finger_pad_forces_filteredi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_finger_pad_forces_filteredi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_finger_pad_forces_filteredi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_finger_pad_forces_filteredi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_finger_pad_forces_filteredi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_finger_pad_forces_filteredi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_finger_pad_forces_filteredi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_finger_pad_forces_filteredi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_finger_pad_forces_filtered[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_acc_x_raw;
      u_acc_x_raw.real = this->acc_x_raw;
      *(outbuffer + offset + 0) = (u_acc_x_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_x_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_x_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_x_raw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acc_x_raw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acc_x_raw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acc_x_raw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acc_x_raw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acc_x_raw);
      union {
        double real;
        uint64_t base;
      } u_acc_y_raw;
      u_acc_y_raw.real = this->acc_y_raw;
      *(outbuffer + offset + 0) = (u_acc_y_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_y_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_y_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_y_raw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acc_y_raw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acc_y_raw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acc_y_raw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acc_y_raw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acc_y_raw);
      union {
        double real;
        uint64_t base;
      } u_acc_z_raw;
      u_acc_z_raw.real = this->acc_z_raw;
      *(outbuffer + offset + 0) = (u_acc_z_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_z_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_z_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_z_raw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acc_z_raw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acc_z_raw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acc_z_raw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acc_z_raw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acc_z_raw);
      union {
        double real;
        uint64_t base;
      } u_acc_x_filtered;
      u_acc_x_filtered.real = this->acc_x_filtered;
      *(outbuffer + offset + 0) = (u_acc_x_filtered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_x_filtered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_x_filtered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_x_filtered.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acc_x_filtered.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acc_x_filtered.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acc_x_filtered.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acc_x_filtered.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acc_x_filtered);
      union {
        double real;
        uint64_t base;
      } u_acc_y_filtered;
      u_acc_y_filtered.real = this->acc_y_filtered;
      *(outbuffer + offset + 0) = (u_acc_y_filtered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_y_filtered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_y_filtered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_y_filtered.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acc_y_filtered.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acc_y_filtered.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acc_y_filtered.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acc_y_filtered.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acc_y_filtered);
      union {
        double real;
        uint64_t base;
      } u_acc_z_filtered;
      u_acc_z_filtered.real = this->acc_z_filtered;
      *(outbuffer + offset + 0) = (u_acc_z_filtered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_z_filtered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_z_filtered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_z_filtered.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acc_z_filtered.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acc_z_filtered.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acc_z_filtered.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acc_z_filtered.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acc_z_filtered);
      union {
        bool real;
        uint8_t base;
      } u_left_contact;
      u_left_contact.real = this->left_contact;
      *(outbuffer + offset + 0) = (u_left_contact.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_contact);
      union {
        bool real;
        uint8_t base;
      } u_right_contact;
      u_right_contact.real = this->right_contact;
      *(outbuffer + offset + 0) = (u_right_contact.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_contact);
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
      } u_left_finger_pad_force;
      u_left_finger_pad_force.base = 0;
      u_left_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_finger_pad_force = u_left_finger_pad_force.real;
      offset += sizeof(this->left_finger_pad_force);
      union {
        double real;
        uint64_t base;
      } u_right_finger_pad_force;
      u_right_finger_pad_force.base = 0;
      u_right_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_finger_pad_force.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_finger_pad_force = u_right_finger_pad_force.real;
      offset += sizeof(this->right_finger_pad_force);
      union {
        double real;
        uint64_t base;
      } u_left_finger_pad_force_filtered;
      u_left_finger_pad_force_filtered.base = 0;
      u_left_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_finger_pad_force_filtered = u_left_finger_pad_force_filtered.real;
      offset += sizeof(this->left_finger_pad_force_filtered);
      union {
        double real;
        uint64_t base;
      } u_right_finger_pad_force_filtered;
      u_right_finger_pad_force_filtered.base = 0;
      u_right_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_finger_pad_force_filtered.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_finger_pad_force_filtered = u_right_finger_pad_force_filtered.real;
      offset += sizeof(this->right_finger_pad_force_filtered);
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_left_finger_pad_forcesi;
      u_left_finger_pad_forcesi.base = 0;
      u_left_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_finger_pad_forces[i] = u_left_finger_pad_forcesi.real;
      offset += sizeof(this->left_finger_pad_forces[i]);
      }
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_right_finger_pad_forcesi;
      u_right_finger_pad_forcesi.base = 0;
      u_right_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_finger_pad_forcesi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_finger_pad_forces[i] = u_right_finger_pad_forcesi.real;
      offset += sizeof(this->right_finger_pad_forces[i]);
      }
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_left_finger_pad_forces_filteredi;
      u_left_finger_pad_forces_filteredi.base = 0;
      u_left_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_finger_pad_forces_filtered[i] = u_left_finger_pad_forces_filteredi.real;
      offset += sizeof(this->left_finger_pad_forces_filtered[i]);
      }
      for( uint8_t i = 0; i < 22; i++){
      union {
        double real;
        uint64_t base;
      } u_right_finger_pad_forces_filteredi;
      u_right_finger_pad_forces_filteredi.base = 0;
      u_right_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_finger_pad_forces_filteredi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_finger_pad_forces_filtered[i] = u_right_finger_pad_forces_filteredi.real;
      offset += sizeof(this->right_finger_pad_forces_filtered[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_acc_x_raw;
      u_acc_x_raw.base = 0;
      u_acc_x_raw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_x_raw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_x_raw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_x_raw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acc_x_raw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acc_x_raw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acc_x_raw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acc_x_raw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acc_x_raw = u_acc_x_raw.real;
      offset += sizeof(this->acc_x_raw);
      union {
        double real;
        uint64_t base;
      } u_acc_y_raw;
      u_acc_y_raw.base = 0;
      u_acc_y_raw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_y_raw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_y_raw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_y_raw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acc_y_raw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acc_y_raw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acc_y_raw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acc_y_raw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acc_y_raw = u_acc_y_raw.real;
      offset += sizeof(this->acc_y_raw);
      union {
        double real;
        uint64_t base;
      } u_acc_z_raw;
      u_acc_z_raw.base = 0;
      u_acc_z_raw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_z_raw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_z_raw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_z_raw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acc_z_raw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acc_z_raw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acc_z_raw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acc_z_raw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acc_z_raw = u_acc_z_raw.real;
      offset += sizeof(this->acc_z_raw);
      union {
        double real;
        uint64_t base;
      } u_acc_x_filtered;
      u_acc_x_filtered.base = 0;
      u_acc_x_filtered.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_x_filtered.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_x_filtered.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_x_filtered.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acc_x_filtered.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acc_x_filtered.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acc_x_filtered.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acc_x_filtered.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acc_x_filtered = u_acc_x_filtered.real;
      offset += sizeof(this->acc_x_filtered);
      union {
        double real;
        uint64_t base;
      } u_acc_y_filtered;
      u_acc_y_filtered.base = 0;
      u_acc_y_filtered.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_y_filtered.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_y_filtered.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_y_filtered.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acc_y_filtered.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acc_y_filtered.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acc_y_filtered.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acc_y_filtered.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acc_y_filtered = u_acc_y_filtered.real;
      offset += sizeof(this->acc_y_filtered);
      union {
        double real;
        uint64_t base;
      } u_acc_z_filtered;
      u_acc_z_filtered.base = 0;
      u_acc_z_filtered.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_z_filtered.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_z_filtered.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_z_filtered.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acc_z_filtered.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acc_z_filtered.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acc_z_filtered.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acc_z_filtered.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acc_z_filtered = u_acc_z_filtered.real;
      offset += sizeof(this->acc_z_filtered);
      union {
        bool real;
        uint8_t base;
      } u_left_contact;
      u_left_contact.base = 0;
      u_left_contact.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_contact = u_left_contact.real;
      offset += sizeof(this->left_contact);
      union {
        bool real;
        uint8_t base;
      } u_right_contact;
      u_right_contact.base = 0;
      u_right_contact.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_contact = u_right_contact.real;
      offset += sizeof(this->right_contact);
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperSensorRawData"; };
    const char * getMD5(){ return "696a1f2e6969deb0bc6998636ae1b17e"; };

  };

}
#endif