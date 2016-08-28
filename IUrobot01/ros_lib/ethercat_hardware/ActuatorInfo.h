#ifndef _ROS_ethercat_hardware_ActuatorInfo_h
#define _ROS_ethercat_hardware_ActuatorInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ethercat_hardware
{

  class ActuatorInfo : public ros::Msg
  {
    public:
      uint32_t id;
      const char* name;
      const char* robot_name;
      const char* motor_make;
      const char* motor_model;
      double max_current;
      double speed_constant;
      double motor_resistance;
      double motor_torque_constant;
      double encoder_reduction;
      double pulses_per_revolution;

    ActuatorInfo():
      id(0),
      name(""),
      robot_name(""),
      motor_make(""),
      motor_model(""),
      max_current(0),
      speed_constant(0),
      motor_resistance(0),
      motor_torque_constant(0),
      encoder_reduction(0),
      pulses_per_revolution(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_robot_name = strlen(this->robot_name);
      memcpy(outbuffer + offset, &length_robot_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->robot_name, length_robot_name);
      offset += length_robot_name;
      uint32_t length_motor_make = strlen(this->motor_make);
      memcpy(outbuffer + offset, &length_motor_make, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->motor_make, length_motor_make);
      offset += length_motor_make;
      uint32_t length_motor_model = strlen(this->motor_model);
      memcpy(outbuffer + offset, &length_motor_model, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->motor_model, length_motor_model);
      offset += length_motor_model;
      union {
        double real;
        uint64_t base;
      } u_max_current;
      u_max_current.real = this->max_current;
      *(outbuffer + offset + 0) = (u_max_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_current);
      union {
        double real;
        uint64_t base;
      } u_speed_constant;
      u_speed_constant.real = this->speed_constant;
      *(outbuffer + offset + 0) = (u_speed_constant.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed_constant.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed_constant.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed_constant.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_speed_constant.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_speed_constant.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_speed_constant.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_speed_constant.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->speed_constant);
      union {
        double real;
        uint64_t base;
      } u_motor_resistance;
      u_motor_resistance.real = this->motor_resistance;
      *(outbuffer + offset + 0) = (u_motor_resistance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_resistance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_resistance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_resistance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_motor_resistance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_motor_resistance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_motor_resistance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_motor_resistance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->motor_resistance);
      union {
        double real;
        uint64_t base;
      } u_motor_torque_constant;
      u_motor_torque_constant.real = this->motor_torque_constant;
      *(outbuffer + offset + 0) = (u_motor_torque_constant.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_torque_constant.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_torque_constant.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_torque_constant.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_motor_torque_constant.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_motor_torque_constant.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_motor_torque_constant.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_motor_torque_constant.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->motor_torque_constant);
      union {
        double real;
        uint64_t base;
      } u_encoder_reduction;
      u_encoder_reduction.real = this->encoder_reduction;
      *(outbuffer + offset + 0) = (u_encoder_reduction.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_encoder_reduction.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_encoder_reduction.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_encoder_reduction.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_encoder_reduction.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_encoder_reduction.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_encoder_reduction.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_encoder_reduction.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->encoder_reduction);
      union {
        double real;
        uint64_t base;
      } u_pulses_per_revolution;
      u_pulses_per_revolution.real = this->pulses_per_revolution;
      *(outbuffer + offset + 0) = (u_pulses_per_revolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pulses_per_revolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pulses_per_revolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pulses_per_revolution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pulses_per_revolution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pulses_per_revolution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pulses_per_revolution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pulses_per_revolution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pulses_per_revolution);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_robot_name;
      memcpy(&length_robot_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_name-1]=0;
      this->robot_name = (char *)(inbuffer + offset-1);
      offset += length_robot_name;
      uint32_t length_motor_make;
      memcpy(&length_motor_make, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_motor_make; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_motor_make-1]=0;
      this->motor_make = (char *)(inbuffer + offset-1);
      offset += length_motor_make;
      uint32_t length_motor_model;
      memcpy(&length_motor_model, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_motor_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_motor_model-1]=0;
      this->motor_model = (char *)(inbuffer + offset-1);
      offset += length_motor_model;
      union {
        double real;
        uint64_t base;
      } u_max_current;
      u_max_current.base = 0;
      u_max_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_current = u_max_current.real;
      offset += sizeof(this->max_current);
      union {
        double real;
        uint64_t base;
      } u_speed_constant;
      u_speed_constant.base = 0;
      u_speed_constant.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed_constant.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed_constant.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed_constant.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_speed_constant.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_speed_constant.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_speed_constant.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_speed_constant.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->speed_constant = u_speed_constant.real;
      offset += sizeof(this->speed_constant);
      union {
        double real;
        uint64_t base;
      } u_motor_resistance;
      u_motor_resistance.base = 0;
      u_motor_resistance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_resistance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_resistance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_resistance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_motor_resistance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_motor_resistance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_motor_resistance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_motor_resistance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->motor_resistance = u_motor_resistance.real;
      offset += sizeof(this->motor_resistance);
      union {
        double real;
        uint64_t base;
      } u_motor_torque_constant;
      u_motor_torque_constant.base = 0;
      u_motor_torque_constant.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_torque_constant.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_torque_constant.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_torque_constant.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_motor_torque_constant.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_motor_torque_constant.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_motor_torque_constant.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_motor_torque_constant.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->motor_torque_constant = u_motor_torque_constant.real;
      offset += sizeof(this->motor_torque_constant);
      union {
        double real;
        uint64_t base;
      } u_encoder_reduction;
      u_encoder_reduction.base = 0;
      u_encoder_reduction.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_encoder_reduction.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_encoder_reduction.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_encoder_reduction.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_encoder_reduction.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_encoder_reduction.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_encoder_reduction.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_encoder_reduction.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->encoder_reduction = u_encoder_reduction.real;
      offset += sizeof(this->encoder_reduction);
      union {
        double real;
        uint64_t base;
      } u_pulses_per_revolution;
      u_pulses_per_revolution.base = 0;
      u_pulses_per_revolution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pulses_per_revolution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pulses_per_revolution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pulses_per_revolution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pulses_per_revolution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pulses_per_revolution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pulses_per_revolution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pulses_per_revolution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pulses_per_revolution = u_pulses_per_revolution.real;
      offset += sizeof(this->pulses_per_revolution);
     return offset;
    }

    const char * getType(){ return "ethercat_hardware/ActuatorInfo"; };
    const char * getMD5(){ return "40f44d8ec4380adc0b63713486eecb09"; };

  };

}
#endif