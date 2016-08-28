#ifndef _ROS_ethercat_hardware_MotorTemperature_h
#define _ROS_ethercat_hardware_MotorTemperature_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace ethercat_hardware
{

  class MotorTemperature : public ros::Msg
  {
    public:
      ros::Time stamp;
      double winding_temperature;
      double housing_temperature;
      double ambient_temperature;
      double heating_power;

    MotorTemperature():
      stamp(),
      winding_temperature(0),
      housing_temperature(0),
      ambient_temperature(0),
      heating_power(0)
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
      } u_winding_temperature;
      u_winding_temperature.real = this->winding_temperature;
      *(outbuffer + offset + 0) = (u_winding_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_winding_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_winding_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_winding_temperature.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_winding_temperature.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_winding_temperature.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_winding_temperature.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_winding_temperature.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->winding_temperature);
      union {
        double real;
        uint64_t base;
      } u_housing_temperature;
      u_housing_temperature.real = this->housing_temperature;
      *(outbuffer + offset + 0) = (u_housing_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_housing_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_housing_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_housing_temperature.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_housing_temperature.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_housing_temperature.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_housing_temperature.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_housing_temperature.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->housing_temperature);
      union {
        double real;
        uint64_t base;
      } u_ambient_temperature;
      u_ambient_temperature.real = this->ambient_temperature;
      *(outbuffer + offset + 0) = (u_ambient_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ambient_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ambient_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ambient_temperature.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ambient_temperature.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ambient_temperature.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ambient_temperature.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ambient_temperature.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ambient_temperature);
      union {
        double real;
        uint64_t base;
      } u_heating_power;
      u_heating_power.real = this->heating_power;
      *(outbuffer + offset + 0) = (u_heating_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heating_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heating_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heating_power.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heating_power.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heating_power.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heating_power.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heating_power.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->heating_power);
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
      } u_winding_temperature;
      u_winding_temperature.base = 0;
      u_winding_temperature.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_winding_temperature.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_winding_temperature.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_winding_temperature.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_winding_temperature.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_winding_temperature.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_winding_temperature.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_winding_temperature.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->winding_temperature = u_winding_temperature.real;
      offset += sizeof(this->winding_temperature);
      union {
        double real;
        uint64_t base;
      } u_housing_temperature;
      u_housing_temperature.base = 0;
      u_housing_temperature.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_housing_temperature.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_housing_temperature.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_housing_temperature.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_housing_temperature.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_housing_temperature.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_housing_temperature.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_housing_temperature.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->housing_temperature = u_housing_temperature.real;
      offset += sizeof(this->housing_temperature);
      union {
        double real;
        uint64_t base;
      } u_ambient_temperature;
      u_ambient_temperature.base = 0;
      u_ambient_temperature.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ambient_temperature.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ambient_temperature.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ambient_temperature.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ambient_temperature.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ambient_temperature.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ambient_temperature.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ambient_temperature.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ambient_temperature = u_ambient_temperature.real;
      offset += sizeof(this->ambient_temperature);
      union {
        double real;
        uint64_t base;
      } u_heating_power;
      u_heating_power.base = 0;
      u_heating_power.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heating_power.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heating_power.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heating_power.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_heating_power.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_heating_power.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_heating_power.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_heating_power.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->heating_power = u_heating_power.real;
      offset += sizeof(this->heating_power);
     return offset;
    }

    const char * getType(){ return "ethercat_hardware/MotorTemperature"; };
    const char * getMD5(){ return "d8c7239cd096d6f25b75bff6b63f2162"; };

  };

}
#endif