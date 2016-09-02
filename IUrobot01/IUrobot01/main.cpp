#include "ros.h"
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include <windows.h>
#include <process.h>
#define CM_IRA		(WM_APP+200)

const  char* szAppName = "MyWndClass";

static UINT sBroadcastCommand = ::RegisterWindowMessage("iCeiRA_Message");
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = szAppName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "RegisterClassEx error!", "something wrong!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        szAppName,
        "IU_Robot",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 200,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Win32 create error!", "error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

	ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}

void pcl_pose_callback(const geometry_msgs::Vector3 & pose)
{
	//printf("Received pose %f, %f, %f\n", pose.x,pose.y,pose.z);
	::PostMessageA( (HWND)HWND_BROADCAST,sBroadcastCommand, 30 ,(pose.x*100) );
	::PostMessageA( (HWND)HWND_BROADCAST,sBroadcastCommand, 31 ,(pose.y*100) );
	::PostMessageA( (HWND)HWND_BROADCAST,sBroadcastCommand, 32 ,(pose.z*100) );
}

int speed_counter = 0;
double Time = 0;
double dX = 0;
double dY = 0;
double dTh = 0;
geometry_msgs::Vector3 pcl_cmd;
void thrROS(void* p)
{
	ros::NodeHandle nh;
	char *ros_master = "192.168.1.159";
	nh.initNode(ros_master);

	geometry_msgs::Twist twist_msg;
	//ros::Publisher cmd_vel_pub("asusbot_diff_diff_drive_controller/cmd_vel", &twist_msg);
	ros::Publisher cmd_vel_pub("r1/cmd_vel", &twist_msg);
	nh.advertise(cmd_vel_pub);
	ros::Subscriber <geometry_msgs::Vector3> poseSub("/pcl_POS_msg", &pcl_pose_callback);
	nh.subscribe(poseSub);
	//geometry_msgs::Vector3 pcl_cmd;
	ros::Publisher pcl_cmd_pub("/pcl_CMD", &pcl_cmd);
	nh.advertise(pcl_cmd_pub);

	while (1)
	{
		twist_msg.linear.x = dX;
		twist_msg.linear.y = dY;
		twist_msg.linear.z = 0;
		twist_msg.angular.x = 0;
		twist_msg.angular.y = 0;
		twist_msg.angular.z = dTh;
		cmd_vel_pub.publish(&twist_msg);
		if(speed_counter)
		{
			speed_counter--;
		}
		else
		{
			dX = 0;
			dTh = 0;
			Time = 0;
		}

		if(pcl_cmd.x!=0)
		{
			pcl_cmd_pub.publish(&pcl_cmd);
			pcl_cmd.x = 0;
			pcl_cmd.y = 0;
			pcl_cmd.z = 0;
		}
		nh.spinOnce();
		Sleep(100);
	}

	_endthread();
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if(msg == sBroadcastCommand)
	{
		if(wParam == 10)//motion
		{
			speed_counter = 10;
			switch(lParam)
			{
			case 1://up
				dX=.05;
			break;
			case 2://down
				//dX=-.05;
				dTh=0.314;
				speed_counter=10;
			break;
			case 3://left
				dTh=.05;
			break;
			case 4://right
				dTh=-.05;
			break;
			}
		}
		if(wParam == 20) //specify the time interval that user want the robot to arrive within
		{
			Time = (double)lParam/1000;  // unit: time: sec, lParam: msec.
			speed_counter = lParam/100;
		}
		if (Time)
		{
			dX = (wParam==21)  ?( (double)lParam / (Time*100) )  :dX;
			dY = (wParam==22)  ?( (double)lParam / (Time*100) )  :dY;
			dTh = (wParam==23) ?( (double)lParam / (Time*100) )  :dTh;
		}
		

		if(wParam == 99)//PCL cmd
		{
			switch(lParam)
			{
			case 1:
				pcl_cmd.x = 1.0;
				pcl_cmd.y = 22;
				pcl_cmd.z = 3;
			break;
			case 2:
				pcl_cmd.x = 10.0;
				pcl_cmd.y = 22;
				pcl_cmd.z = 3;
			break;
			}
		}
	}
    switch(msg)
    {
		case WM_CREATE:
            (HANDLE)_beginthread(thrROS, 0, NULL);
		break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}
