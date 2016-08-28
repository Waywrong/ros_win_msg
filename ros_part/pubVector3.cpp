#include "ros/ros.h"
#include "geometry_msgs/Vector3.h"
#include "std_msgs/String.h"
#include <sstream>

void cmdCallback(const geometry_msgs::Vector3::ConstPtr& _CMD)
{
  ROS_INFO("hi");
  
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pubVector3D");
  ros::NodeHandle nh;
  ros::Rate r(1);
  geometry_msgs::Vector3 pcl_msg;
  ros::Publisher pcl_obj_pub = nh.advertise<geometry_msgs::Vector3>("pcl_POS_msg", 1);
  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);
  ///pcl_POS_msg
  ros::Subscriber poseSub = nh.subscribe<geometry_msgs::Vector3>("/pcl_POS_msg", 1, &cmdCallback);
  
  int count=0;
  while(ros::ok())
  {
    static float kk=0.23;
    kk+=100;
    pcl_msg.x = 11.16;
    pcl_msg.y = kk;
    pcl_msg.z = 33.37;
    pcl_obj_pub.publish(pcl_msg);
    
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world "<<count++;
    msg.data = ss.str();
    chatter_pub.publish(msg);
    
    ros::spinOnce();
    r.sleep();
  }

  return 0;
}