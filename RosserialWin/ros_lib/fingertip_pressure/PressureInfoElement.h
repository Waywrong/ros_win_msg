#ifndef _ROS_fingertip_pressure_PressureInfoElement_h
#define _ROS_fingertip_pressure_PressureInfoElement_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace fingertip_pressure
{

  class PressureInfoElement : public ros::Msg
  {
    public:
      const char* frame_id;
      uint8_t center_length;
      geometry_msgs::Vector3 st_center;
      geometry_msgs::Vector3 * center;
      uint8_t halfside1_length;
      geometry_msgs::Vector3 st_halfside1;
      geometry_msgs::Vector3 * halfside1;
      uint8_t halfside2_length;
      geometry_msgs::Vector3 st_halfside2;
      geometry_msgs::Vector3 * halfside2;
      uint8_t force_per_unit_length;
      double st_force_per_unit;
      double * force_per_unit;

    PressureInfoElement():
      frame_id(""),
      center_length(0), center(NULL),
      halfside1_length(0), halfside1(NULL),
      halfside2_length(0), halfside2(NULL),
      force_per_unit_length(0), force_per_unit(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_frame_id = strlen(this->frame_id);
      memcpy(outbuffer + offset, &length_frame_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      *(outbuffer + offset++) = center_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < center_length; i++){
      offset += this->center[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = halfside1_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < halfside1_length; i++){
      offset += this->halfside1[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = halfside2_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < halfside2_length; i++){
      offset += this->halfside2[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = force_per_unit_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < force_per_unit_length; i++){
      union {
        double real;
        uint64_t base;
      } u_force_per_uniti;
      u_force_per_uniti.real = this->force_per_unit[i];
      *(outbuffer + offset + 0) = (u_force_per_uniti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force_per_uniti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force_per_uniti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force_per_uniti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_force_per_uniti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_force_per_uniti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_force_per_uniti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_force_per_uniti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->force_per_unit[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_frame_id;
      memcpy(&length_frame_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      uint8_t center_lengthT = *(inbuffer + offset++);
      if(center_lengthT > center_length)
        this->center = (geometry_msgs::Vector3*)realloc(this->center, center_lengthT * sizeof(geometry_msgs::Vector3));
      offset += 3;
      center_length = center_lengthT;
      for( uint8_t i = 0; i < center_length; i++){
      offset += this->st_center.deserialize(inbuffer + offset);
        memcpy( &(this->center[i]), &(this->st_center), sizeof(geometry_msgs::Vector3));
      }
      uint8_t halfside1_lengthT = *(inbuffer + offset++);
      if(halfside1_lengthT > halfside1_length)
        this->halfside1 = (geometry_msgs::Vector3*)realloc(this->halfside1, halfside1_lengthT * sizeof(geometry_msgs::Vector3));
      offset += 3;
      halfside1_length = halfside1_lengthT;
      for( uint8_t i = 0; i < halfside1_length; i++){
      offset += this->st_halfside1.deserialize(inbuffer + offset);
        memcpy( &(this->halfside1[i]), &(this->st_halfside1), sizeof(geometry_msgs::Vector3));
      }
      uint8_t halfside2_lengthT = *(inbuffer + offset++);
      if(halfside2_lengthT > halfside2_length)
        this->halfside2 = (geometry_msgs::Vector3*)realloc(this->halfside2, halfside2_lengthT * sizeof(geometry_msgs::Vector3));
      offset += 3;
      halfside2_length = halfside2_lengthT;
      for( uint8_t i = 0; i < halfside2_length; i++){
      offset += this->st_halfside2.deserialize(inbuffer + offset);
        memcpy( &(this->halfside2[i]), &(this->st_halfside2), sizeof(geometry_msgs::Vector3));
      }
      uint8_t force_per_unit_lengthT = *(inbuffer + offset++);
      if(force_per_unit_lengthT > force_per_unit_length)
        this->force_per_unit = (double*)realloc(this->force_per_unit, force_per_unit_lengthT * sizeof(double));
      offset += 3;
      force_per_unit_length = force_per_unit_lengthT;
      for( uint8_t i = 0; i < force_per_unit_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_force_per_unit;
      u_st_force_per_unit.base = 0;
      u_st_force_per_unit.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_force_per_unit.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_force_per_unit.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_force_per_unit.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_force_per_unit.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_force_per_unit.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_force_per_unit.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_force_per_unit.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_force_per_unit = u_st_force_per_unit.real;
      offset += sizeof(this->st_force_per_unit);
        memcpy( &(this->force_per_unit[i]), &(this->st_force_per_unit), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "fingertip_pressure/PressureInfoElement"; };
    const char * getMD5(){ return "1cb486bb542ab85e1ff8d84fe9cc899f"; };

  };

}
#endif