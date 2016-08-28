#ifndef _ROS_SERVICE_sentobject_h
#define _ROS_SERVICE_sentobject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace teleop_twist_keyboard
{

static const char SENTOBJECT[] = "teleop_twist_keyboard/sentobject";

  class sentobjectRequest : public ros::Msg
  {
    public:
      bool gotObject;
      geometry_msgs::PoseStamped pose;
      int8_t robot_id;

    sentobjectRequest():
      gotObject(0),
      pose(),
      robot_id(0)
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
      union {
        int8_t real;
        uint8_t base;
      } u_robot_id;
      u_robot_id.real = this->robot_id;
      *(outbuffer + offset + 0) = (u_robot_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->robot_id);
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
      union {
        int8_t real;
        uint8_t base;
      } u_robot_id;
      u_robot_id.base = 0;
      u_robot_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->robot_id = u_robot_id.real;
      offset += sizeof(this->robot_id);
     return offset;
    }

    const char * getType(){ return SENTOBJECT; };
    const char * getMD5(){ return "3dab4ab37712d27791a9be97a28175d3"; };

  };

  class sentobjectResponse : public ros::Msg
  {
    public:
      bool keepsearching;

    sentobjectResponse():
      keepsearching(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_keepsearching;
      u_keepsearching.real = this->keepsearching;
      *(outbuffer + offset + 0) = (u_keepsearching.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->keepsearching);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_keepsearching;
      u_keepsearching.base = 0;
      u_keepsearching.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->keepsearching = u_keepsearching.real;
      offset += sizeof(this->keepsearching);
     return offset;
    }

    const char * getType(){ return SENTOBJECT; };
    const char * getMD5(){ return "2b80b70c1643be948c273b8d88e1d0dc"; };

  };

  class sentobject {
    public:
    typedef sentobjectRequest Request;
    typedef sentobjectResponse Response;
  };

}
#endif
