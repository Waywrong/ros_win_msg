#ifndef _ROS_SERVICE_model_h
#define _ROS_SERVICE_model_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace simulation_tobot
{

static const char MODEL[] = "simulation_tobot/model";

  class modelRequest : public ros::Msg
  {
    public:
      const char* order;
      const char* model;

    modelRequest():
      order(""),
      model("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_order = strlen(this->order);
      memcpy(outbuffer + offset, &length_order, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->order, length_order);
      offset += length_order;
      uint32_t length_model = strlen(this->model);
      memcpy(outbuffer + offset, &length_model, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_order;
      memcpy(&length_order, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_order; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_order-1]=0;
      this->order = (char *)(inbuffer + offset-1);
      offset += length_order;
      uint32_t length_model;
      memcpy(&length_model, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model-1]=0;
      this->model = (char *)(inbuffer + offset-1);
      offset += length_model;
     return offset;
    }

    const char * getType(){ return MODEL; };
    const char * getMD5(){ return "100e7ada7fef6c83cab6fbf1896d57d2"; };

  };

  class modelResponse : public ros::Msg
  {
    public:
      const char* answer;

    modelResponse():
      answer("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_answer = strlen(this->answer);
      memcpy(outbuffer + offset, &length_answer, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->answer, length_answer);
      offset += length_answer;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_answer;
      memcpy(&length_answer, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_answer; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_answer-1]=0;
      this->answer = (char *)(inbuffer + offset-1);
      offset += length_answer;
     return offset;
    }

    const char * getType(){ return MODEL; };
    const char * getMD5(){ return "d7e708f879c94bb931716d8f4f130f30"; };

  };

  class model {
    public:
    typedef modelRequest Request;
    typedef modelResponse Response;
  };

}
#endif
