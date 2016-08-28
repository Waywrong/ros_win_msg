#ifndef _ROS_ethercat_hardware_MotorTraceSample_h
#define _ROS_ethercat_hardware_MotorTraceSample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ethercat_hardware
{

  class MotorTraceSample : public ros::Msg
  {
    public:
      double timestamp;
      bool enabled;
      double supply_voltage;
      double measured_motor_voltage;
      double programmed_pwm;
      double executed_current;
      double measured_current;
      double velocity;
      double encoder_position;
      uint32_t encoder_error_count;
      double motor_voltage_error_limit;
      double filtered_motor_voltage_error;
      double filtered_abs_motor_voltage_error;
      double filtered_measured_voltage_error;
      double filtered_abs_measured_voltage_error;
      double filtered_current_error;
      double filtered_abs_current_error;

    MotorTraceSample():
      timestamp(0),
      enabled(0),
      supply_voltage(0),
      measured_motor_voltage(0),
      programmed_pwm(0),
      executed_current(0),
      measured_current(0),
      velocity(0),
      encoder_position(0),
      encoder_error_count(0),
      motor_voltage_error_limit(0),
      filtered_motor_voltage_error(0),
      filtered_abs_motor_voltage_error(0),
      filtered_measured_voltage_error(0),
      filtered_abs_measured_voltage_error(0),
      filtered_current_error(0),
      filtered_abs_current_error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_timestamp;
      u_timestamp.real = this->timestamp;
      *(outbuffer + offset + 0) = (u_timestamp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timestamp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timestamp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timestamp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_timestamp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_timestamp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_timestamp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_timestamp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->timestamp);
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.real = this->enabled;
      *(outbuffer + offset + 0) = (u_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enabled);
      union {
        double real;
        uint64_t base;
      } u_supply_voltage;
      u_supply_voltage.real = this->supply_voltage;
      *(outbuffer + offset + 0) = (u_supply_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_supply_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_supply_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_supply_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_supply_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_supply_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_supply_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_supply_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->supply_voltage);
      union {
        double real;
        uint64_t base;
      } u_measured_motor_voltage;
      u_measured_motor_voltage.real = this->measured_motor_voltage;
      *(outbuffer + offset + 0) = (u_measured_motor_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measured_motor_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measured_motor_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measured_motor_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_measured_motor_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_measured_motor_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_measured_motor_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_measured_motor_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->measured_motor_voltage);
      union {
        double real;
        uint64_t base;
      } u_programmed_pwm;
      u_programmed_pwm.real = this->programmed_pwm;
      *(outbuffer + offset + 0) = (u_programmed_pwm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_programmed_pwm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_programmed_pwm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_programmed_pwm.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_programmed_pwm.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_programmed_pwm.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_programmed_pwm.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_programmed_pwm.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->programmed_pwm);
      union {
        double real;
        uint64_t base;
      } u_executed_current;
      u_executed_current.real = this->executed_current;
      *(outbuffer + offset + 0) = (u_executed_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_executed_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_executed_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_executed_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_executed_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_executed_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_executed_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_executed_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->executed_current);
      union {
        double real;
        uint64_t base;
      } u_measured_current;
      u_measured_current.real = this->measured_current;
      *(outbuffer + offset + 0) = (u_measured_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measured_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measured_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measured_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_measured_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_measured_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_measured_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_measured_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->measured_current);
      union {
        double real;
        uint64_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        double real;
        uint64_t base;
      } u_encoder_position;
      u_encoder_position.real = this->encoder_position;
      *(outbuffer + offset + 0) = (u_encoder_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_encoder_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_encoder_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_encoder_position.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_encoder_position.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_encoder_position.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_encoder_position.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_encoder_position.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->encoder_position);
      *(outbuffer + offset + 0) = (this->encoder_error_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->encoder_error_count >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->encoder_error_count >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->encoder_error_count >> (8 * 3)) & 0xFF;
      offset += sizeof(this->encoder_error_count);
      union {
        double real;
        uint64_t base;
      } u_motor_voltage_error_limit;
      u_motor_voltage_error_limit.real = this->motor_voltage_error_limit;
      *(outbuffer + offset + 0) = (u_motor_voltage_error_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_voltage_error_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_voltage_error_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_voltage_error_limit.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_motor_voltage_error_limit.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_motor_voltage_error_limit.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_motor_voltage_error_limit.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_motor_voltage_error_limit.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->motor_voltage_error_limit);
      union {
        double real;
        uint64_t base;
      } u_filtered_motor_voltage_error;
      u_filtered_motor_voltage_error.real = this->filtered_motor_voltage_error;
      *(outbuffer + offset + 0) = (u_filtered_motor_voltage_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_motor_voltage_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_motor_voltage_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_motor_voltage_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_motor_voltage_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_motor_voltage_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_motor_voltage_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_motor_voltage_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_motor_voltage_error);
      union {
        double real;
        uint64_t base;
      } u_filtered_abs_motor_voltage_error;
      u_filtered_abs_motor_voltage_error.real = this->filtered_abs_motor_voltage_error;
      *(outbuffer + offset + 0) = (u_filtered_abs_motor_voltage_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_abs_motor_voltage_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_abs_motor_voltage_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_abs_motor_voltage_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_abs_motor_voltage_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_abs_motor_voltage_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_abs_motor_voltage_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_abs_motor_voltage_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_abs_motor_voltage_error);
      union {
        double real;
        uint64_t base;
      } u_filtered_measured_voltage_error;
      u_filtered_measured_voltage_error.real = this->filtered_measured_voltage_error;
      *(outbuffer + offset + 0) = (u_filtered_measured_voltage_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_measured_voltage_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_measured_voltage_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_measured_voltage_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_measured_voltage_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_measured_voltage_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_measured_voltage_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_measured_voltage_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_measured_voltage_error);
      union {
        double real;
        uint64_t base;
      } u_filtered_abs_measured_voltage_error;
      u_filtered_abs_measured_voltage_error.real = this->filtered_abs_measured_voltage_error;
      *(outbuffer + offset + 0) = (u_filtered_abs_measured_voltage_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_abs_measured_voltage_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_abs_measured_voltage_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_abs_measured_voltage_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_abs_measured_voltage_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_abs_measured_voltage_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_abs_measured_voltage_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_abs_measured_voltage_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_abs_measured_voltage_error);
      union {
        double real;
        uint64_t base;
      } u_filtered_current_error;
      u_filtered_current_error.real = this->filtered_current_error;
      *(outbuffer + offset + 0) = (u_filtered_current_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_current_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_current_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_current_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_current_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_current_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_current_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_current_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_current_error);
      union {
        double real;
        uint64_t base;
      } u_filtered_abs_current_error;
      u_filtered_abs_current_error.real = this->filtered_abs_current_error;
      *(outbuffer + offset + 0) = (u_filtered_abs_current_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_abs_current_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_abs_current_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_abs_current_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_abs_current_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_abs_current_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_abs_current_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_abs_current_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_abs_current_error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_timestamp;
      u_timestamp.base = 0;
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->timestamp = u_timestamp.real;
      offset += sizeof(this->timestamp);
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.base = 0;
      u_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enabled = u_enabled.real;
      offset += sizeof(this->enabled);
      union {
        double real;
        uint64_t base;
      } u_supply_voltage;
      u_supply_voltage.base = 0;
      u_supply_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_supply_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_supply_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_supply_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_supply_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_supply_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_supply_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_supply_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->supply_voltage = u_supply_voltage.real;
      offset += sizeof(this->supply_voltage);
      union {
        double real;
        uint64_t base;
      } u_measured_motor_voltage;
      u_measured_motor_voltage.base = 0;
      u_measured_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measured_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measured_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measured_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_measured_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_measured_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_measured_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_measured_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->measured_motor_voltage = u_measured_motor_voltage.real;
      offset += sizeof(this->measured_motor_voltage);
      union {
        double real;
        uint64_t base;
      } u_programmed_pwm;
      u_programmed_pwm.base = 0;
      u_programmed_pwm.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_programmed_pwm.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_programmed_pwm.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_programmed_pwm.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_programmed_pwm.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_programmed_pwm.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_programmed_pwm.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_programmed_pwm.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->programmed_pwm = u_programmed_pwm.real;
      offset += sizeof(this->programmed_pwm);
      union {
        double real;
        uint64_t base;
      } u_executed_current;
      u_executed_current.base = 0;
      u_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->executed_current = u_executed_current.real;
      offset += sizeof(this->executed_current);
      union {
        double real;
        uint64_t base;
      } u_measured_current;
      u_measured_current.base = 0;
      u_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->measured_current = u_measured_current.real;
      offset += sizeof(this->measured_current);
      union {
        double real;
        uint64_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        double real;
        uint64_t base;
      } u_encoder_position;
      u_encoder_position.base = 0;
      u_encoder_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_encoder_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_encoder_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_encoder_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_encoder_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_encoder_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_encoder_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_encoder_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->encoder_position = u_encoder_position.real;
      offset += sizeof(this->encoder_position);
      this->encoder_error_count =  ((uint32_t) (*(inbuffer + offset)));
      this->encoder_error_count |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->encoder_error_count |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->encoder_error_count |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->encoder_error_count);
      union {
        double real;
        uint64_t base;
      } u_motor_voltage_error_limit;
      u_motor_voltage_error_limit.base = 0;
      u_motor_voltage_error_limit.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_voltage_error_limit.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_voltage_error_limit.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_voltage_error_limit.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_motor_voltage_error_limit.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_motor_voltage_error_limit.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_motor_voltage_error_limit.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_motor_voltage_error_limit.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->motor_voltage_error_limit = u_motor_voltage_error_limit.real;
      offset += sizeof(this->motor_voltage_error_limit);
      union {
        double real;
        uint64_t base;
      } u_filtered_motor_voltage_error;
      u_filtered_motor_voltage_error.base = 0;
      u_filtered_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_motor_voltage_error = u_filtered_motor_voltage_error.real;
      offset += sizeof(this->filtered_motor_voltage_error);
      union {
        double real;
        uint64_t base;
      } u_filtered_abs_motor_voltage_error;
      u_filtered_abs_motor_voltage_error.base = 0;
      u_filtered_abs_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_abs_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_abs_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_abs_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_abs_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_abs_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_abs_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_abs_motor_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_abs_motor_voltage_error = u_filtered_abs_motor_voltage_error.real;
      offset += sizeof(this->filtered_abs_motor_voltage_error);
      union {
        double real;
        uint64_t base;
      } u_filtered_measured_voltage_error;
      u_filtered_measured_voltage_error.base = 0;
      u_filtered_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_measured_voltage_error = u_filtered_measured_voltage_error.real;
      offset += sizeof(this->filtered_measured_voltage_error);
      union {
        double real;
        uint64_t base;
      } u_filtered_abs_measured_voltage_error;
      u_filtered_abs_measured_voltage_error.base = 0;
      u_filtered_abs_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_abs_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_abs_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_abs_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_abs_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_abs_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_abs_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_abs_measured_voltage_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_abs_measured_voltage_error = u_filtered_abs_measured_voltage_error.real;
      offset += sizeof(this->filtered_abs_measured_voltage_error);
      union {
        double real;
        uint64_t base;
      } u_filtered_current_error;
      u_filtered_current_error.base = 0;
      u_filtered_current_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_current_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_current_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_current_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_current_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_current_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_current_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_current_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_current_error = u_filtered_current_error.real;
      offset += sizeof(this->filtered_current_error);
      union {
        double real;
        uint64_t base;
      } u_filtered_abs_current_error;
      u_filtered_abs_current_error.base = 0;
      u_filtered_abs_current_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_abs_current_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_abs_current_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_abs_current_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_abs_current_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_abs_current_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_abs_current_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_abs_current_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_abs_current_error = u_filtered_abs_current_error.real;
      offset += sizeof(this->filtered_abs_current_error);
     return offset;
    }

    const char * getType(){ return "ethercat_hardware/MotorTraceSample"; };
    const char * getMD5(){ return "3734a66334bc2033448f9c561d39c5e0"; };

  };

}
#endif