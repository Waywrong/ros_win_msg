#include <string>
#include <stdio.h>
#include "ros.h"
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Vector3.h>
#include <windows.h>
#include <std_msgs/String.h>

using std::string;

void estimated_pose_callback(const geometry_msgs::PoseWithCovarianceStamped & pose)
{
	printf("Received pose %f, %f, %f\n", pose.pose.pose.position.x,
		pose.pose.pose.position.y, pose.pose.pose.position.z);
}

void nav_pose_callback(const nav_msgs::Odometry & pose)
{
	printf("Received pose %f, %f, %f\n", pose.pose.pose.position.x,
		pose.pose.pose.position.y, pose.pose.pose.position.z);
}

void pcl_pose_callback(const geometry_msgs::Vector3 & pose)
{
	printf("Received pose %f, %f, %f\n", pose.x,pose.y,pose.z);
}

void chatter_pose_callback(const std_msgs::String & pose)
{
	printf("Received pose");
}
int main()
{
	ros::NodeHandle nh;
	char *ros_master = "192.168.43.106";

	printf("Connecting to server at %s\n", ros_master);
	nh.initNode(ros_master);

	//ros::Subscriber < geometry_msgs::PoseWithCovarianceStamped > poseCovSub("estimated_pose", &estimated_pose_callback);
	//ros::Subscriber <  nav_msgs::Odometry > poseNavSub("estimated_pose", &nav_pose_callback);
	ros::Subscriber < geometry_msgs::Vector3> poseSub("/pcl_POS_msg", &pcl_pose_callback);
	//ros::Subscriber < std_msgs::String> poseSS_Sub("chatter", &chatter_pose_callback);
	nh.subscribe(poseSub);

	printf("Waiting to receive messages\n");
	while (1)
	{
		nh.spinOnce();
		Sleep(100);
	}

	printf("All done!\n");
	return 0;
}