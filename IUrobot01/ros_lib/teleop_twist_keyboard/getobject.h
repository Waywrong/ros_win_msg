#ifndef _ROS_SERVICE_getobject_h
#define _ROS_SERVICE_getobject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace teleop_twist_keyboard
{

static const char GETOBJECT[] = "teleop_twist_keyboard/getobject";

  class getobjectRequest : public ros::Msg
  {
    public:
      bool ask;

    getobjectRequest():
      ask(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ask;
      u_ask.real = this->ask;
      *(outbuffer + offset + 0) = (u_ask.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ask);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ask;
      u_ask.base = 0;
      u_ask.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ask = u_ask.real;
      offset += sizeof(this->ask);
     return offset;
    }

    const char * getType(){ return GETOBJECT; };
    const char * getMD5(){ return "fbe9700edfca44c5eefb040d9b60f6d6"; };

  };

  class getobjectResponse : public ros::Msg
  {
    public:
      bool gotObject;
      geometry_msgs::PoseStamped pose;
      const char* who;

    getobjectResponse():
      gotObject(0),
      pose(),
      who("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_gotObject;
      u_gotObject.real = this->gotObject;
      *(outbuffer + offset + 0) = (u_gotObject.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gotObject);
      offset += this->pose.serialize(outbuffer + offset);
      uint32_t length_who = strlen(this->who);
      memcpy(outbuffer + offset, &length_who, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->who, length_who);
      offset += length_who;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_gotObject;
      u_gotObject.base = 0;
      u_gotObject.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gotObject = u_gotObject.real;
      offset += sizeof(this->gotObject);
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t length_who;
      memcpy(&length_who, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_who; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_who-1]=0;
      this->who = (char *)(inbuffer + offset-1);
      offset += length_who;
     return offset;
    }

    const char * getType(){ return GETOBJECT; };
    const char * getMD5(){ return "0ef134f4e016a1ca5eadbb70fa24d8c2"; };

  };

  class getobject {
    public:
    typedef getobjectRequest Request;
    typedef getobjectResponse Response;
  };

}
#endif
