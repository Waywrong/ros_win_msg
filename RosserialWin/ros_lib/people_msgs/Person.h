#ifndef _ROS_people_msgs_Person_h
#define _ROS_people_msgs_Person_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace people_msgs
{

  class Person : public ros::Msg
  {
    public:
      const char* name;
      geometry_msgs::Point position;
      geometry_msgs::Point velocity;
      double reliability;
      uint8_t tagnames_length;
      char* st_tagnames;
      char* * tagnames;
      uint8_t tags_length;
      char* st_tags;
      char* * tags;

    Person():
      name(""),
      position(),
      velocity(),
      reliability(0),
      tagnames_length(0), tagnames(NULL),
      tags_length(0), tags(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_reliability;
      u_reliability.real = this->reliability;
      *(outbuffer + offset + 0) = (u_reliability.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reliability.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reliability.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reliability.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_reliability.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_reliability.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_reliability.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_reliability.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->reliability);
      *(outbuffer + offset++) = tagnames_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tagnames_length; i++){
      uint32_t length_tagnamesi = strlen(this->tagnames[i]);
      memcpy(outbuffer + offset, &length_tagnamesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->tagnames[i], length_tagnamesi);
      offset += length_tagnamesi;
      }
      *(outbuffer + offset++) = tags_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tags_length; i++){
      uint32_t length_tagsi = strlen(this->tags[i]);
      memcpy(outbuffer + offset, &length_tagsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->tags[i], length_tagsi);
      offset += length_tagsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_reliability;
      u_reliability.base = 0;
      u_reliability.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reliability.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reliability.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reliability.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_reliability.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_reliability.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_reliability.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_reliability.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->reliability = u_reliability.real;
      offset += sizeof(this->reliability);
      uint8_t tagnames_lengthT = *(inbuffer + offset++);
      if(tagnames_lengthT > tagnames_length)
        this->tagnames = (char**)realloc(this->tagnames, tagnames_lengthT * sizeof(char*));
      offset += 3;
      tagnames_length = tagnames_lengthT;
      for( uint8_t i = 0; i < tagnames_length; i++){
      uint32_t length_st_tagnames;
      memcpy(&length_st_tagnames, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_tagnames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_tagnames-1]=0;
      this->st_tagnames = (char *)(inbuffer + offset-1);
      offset += length_st_tagnames;
        memcpy( &(this->tagnames[i]), &(this->st_tagnames), sizeof(char*));
      }
      uint8_t tags_lengthT = *(inbuffer + offset++);
      if(tags_lengthT > tags_length)
        this->tags = (char**)realloc(this->tags, tags_lengthT * sizeof(char*));
      offset += 3;
      tags_length = tags_lengthT;
      for( uint8_t i = 0; i < tags_length; i++){
      uint32_t length_st_tags;
      memcpy(&length_st_tags, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_tags; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_tags-1]=0;
      this->st_tags = (char *)(inbuffer + offset-1);
      offset += length_st_tags;
        memcpy( &(this->tags[i]), &(this->st_tags), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "people_msgs/Person"; };
    const char * getMD5(){ return "0b7c0818b76476f3863bd13f4d59f8df"; };

  };

}
#endif