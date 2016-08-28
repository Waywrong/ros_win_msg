#ifndef _ROS_SERVICE_lifting_h
#define _ROS_SERVICE_lifting_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace teleop_twist_keyboard
{

static const char LIFTING[] = "teleop_twist_keyboard/lifting";

  class liftingRequest : public ros::Msg
  {
    public:
      const char* way;

    liftingRequest():
      way("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_way = strlen(this->way);
      memcpy(outbuffer + offset, &length_way, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->way, length_way);
      offset += length_way;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_way;
      memcpy(&length_way, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_way; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_way-1]=0;
      this->way = (char *)(inbuffer + offset-1);
      offset += length_way;
     return offset;
    }

    const char * getType(){ return LIFTING; };
    const char * getMD5(){ return "49a73a1b90ce0c78095b0c677927ce90"; };

  };

  class liftingResponse : public ros::Msg
  {
    public:
      bool answer;

    liftingResponse():
      answer(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_answer;
      u_answer.real = this->answer;
      *(outbuffer + offset + 0) = (u_answer.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->answer);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_answer;
      u_answer.base = 0;
      u_answer.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->answer = u_answer.real;
      offset += sizeof(this->answer);
     return offset;
    }

    const char * getType(){ return LIFTING; };
    const char * getMD5(){ return "00a50c1bd863054691f197c515f4e922"; };

  };

  class lifting {
    public:
    typedef liftingRequest Request;
    typedef liftingResponse Response;
  };

}
#endif
