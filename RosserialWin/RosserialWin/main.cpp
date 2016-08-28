#include <string>
#include <stdio.h>
#include "ros.h"
#include <geometry_msgs/Twist.h>
#include <windows.h>
#include <conio.h>    
#include <iostream>
#include <process.h>

using std::string;
using namespace std;

double dX = 0;
double dTh = 0;

void MotionFromKeyboard(void* p)
{
	int iCmd = 0;
	while (1)
	{
		iCmd = _getch();
		iCmd = tolower(iCmd);

		switch (iCmd)
		{
		case 'w'://forward
			dX = 0.1;
			dTh = 0;
			printf("(w) forward\n");
			break;
		case 'd'://turn right 90 degree
			dX = 0;
			dTh = -0.1;
			printf("(d) right\n");
			break;
		case 'a'://turn left 90 degree
			dX = 0;
			dTh = 0.1;
			printf("(a) left\n");
			break;
		case 'x'://backward
			dX = -0.1;
			dTh = 0;
			printf("(x) backward\n");
			break;
		case 's'://stop
			dX = 0;
			dTh = 0;
			printf("(s) stop\n");
			break;
		default:
			dX = 0;
			dTh = 0;
			printf("%d ", iCmd);
			break;
		}
	}
	_endthread();
}

int main()
{
	ros::NodeHandle nh;
	char *ros_master = "192.168.43.106";
	printf("Connecting to server at %s\n", ros_master);
	nh.initNode(ros_master);

	printf("Advertising cmd_vel message\n");
	geometry_msgs::Twist twist_msg;
	ros::Publisher cmd_vel_pub("r1/cmd_vel", &twist_msg);
	nh.advertise(cmd_vel_pub);

	printf("Go robot go!\n");
	HANDLE _hThread_joy = (HANDLE)_beginthread(MotionFromKeyboard, 0, NULL);
	while (1)
	{
		twist_msg.linear.x = dX;
		twist_msg.linear.y = 0;
		twist_msg.linear.z = 0;
		twist_msg.angular.x = 0;
		twist_msg.angular.y = 0;
		twist_msg.angular.z = dTh;
		cmd_vel_pub.publish(&twist_msg);
		dX = 0;
		dTh = 0;
		nh.spinOnce();
		Sleep(100);
	}
	printf("All done!\n");
	return 0;
}