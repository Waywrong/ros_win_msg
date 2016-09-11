#include "StdAfx.h"
#include "TCP_Ser.h"
static UINT sBroadcastCommand = ::RegisterWindowMessage("iCeiRA_Message");
UINT threadSer(LPVOID p)
{
	TCP_Ser *mSer=(TCP_Ser*)p;
	char buff[MR_PackageSize];
	int s=1;
	int msgcount;
	int loop=1;
	msgcount=mSer->GetUnusedConnectNum();
	if (msgcount==-1)
		loop=0;
	if(loop)
	{
		s=1;
		mSer->msgSock[msgcount]=
			accept(mSer->serSock,(sockaddr*)&(mSer->stAddr),&(mSer->addlen));
		if (mSer->msgSock[msgcount]==INVALID_SOCKET)
		{
			_cprintf("Accept Error\n");
		}
		else
		{
			_cprintf("Connected\n");
			AfxBeginThread(threadSer,p);
			_beginthread(TCP_Ser::thrMessageCenter, 0, p);
		}
	}
	AfxEndThread(0);
	return 0;
}
	

TCP_Ser::TCP_Ser(int iPort,void* pCWnd)
{
	InitializeAll();
	//get the dialog CWnd pointer
	pUI = (CWnd*)pCWnd;
	stAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	stAddr.sin_family=AF_INET;
	stAddr.sin_port=htons(iPort);
	addlen=sizeof(stAddr);

	serSock=socket(AF_INET,SOCK_STREAM,0);
	if (bind(serSock,(sockaddr*)&stAddr,addlen))
	{
		_cprintf("Bind Error\n");
	}
	else
	{
		listen(serSock,/*backlog 1~5*/5);
		_cprintf("listen...\n");
		//if request connect > backlog at the same time, then client will recv. WSAECONNREFUSED error
		AfxBeginThread(&threadSer,this);
	}
}

TCP_Ser::~TCP_Ser(void)
{
	_thr_msg_loop=0;
	closesocket(msgSock[0]);
	WSACleanup();
}

void TCP_Ser::InitializeAll(void)
{
	AfxSocketInit();
	for (int i=0;i<50;i++)
		msgSock[i]=NULL;
	IsReadSensorMode=1;
	//GetSensorData(byte *myBufferBytes)
	memset(iSensor,0,sizeof(int)*3);
	iSensorIndex=0;
	//GetSensorData(byte *myBufferBytes)
}

int TCP_Ser::GetUnusedConnectNum(void)//查出可用的連線編號
{
	for (int i=0;i<50;i++)
		if (msgSock[i]==NULL)
			return i;
	return -1;
}

int TCP_Ser::GetSensorData(byte *myBufferBytes)
{
	char buffer[MR_PackageSize];
	int iBufferCheckCount=0;
	int i,j;
	memcpy(&buffer,myBufferBytes,MR_PackageSize);
	//_cprintf("%s\n",buffer);
	iSensor[0]=0;
	for(i=0,iSensorIndex=0;buffer[i]!='-';i++)
	{
		if(buffer[i]!=124)//'|'
		{
			if(buffer[i]!=45)//'-'
				iSensor[iSensorIndex]=iSensor[iSensorIndex]*10+(buffer[i]-48);
			/*else
			{
				i+=3;
				iSensorIndex=0;
				iSensor[iSensorIndex]=0;
			}*/
		}
		else
		{
			//i++;
			iSensorIndex++;
			iSensor[iSensorIndex]=0;
		}
	}
	//::PostMessage( (HWND)HWND_BROADCAST,CM_SOCK, 1,1 );
	pUI->PostMessage(CM_SOCK,(WPARAM)0,(LPARAM)0);
	_cprintf("Sonar:%d,%d,%d,%d,%d,%d,%d,%d\n",iSensor[0],iSensor[1],iSensor[2],iSensor[3]
											  ,iSensor[4],iSensor[5],iSensor[6],iSensor[7]);
	return 1;
}

void TCP_Ser::SendCMD(char* szCMD)
{
	send( msgSock[0], szCMD, strlen(szCMD), 0 );
	//recv( msgSock[0], szCMD, 32, 0 );
}

int TCP_Ser::RecvData(char* buff)
{
	int s=1;
	s=recv(msgSock[0],buff,MR_PackageSize,0);

	if (s!=SOCKET_ERROR )
	{
		//send( msgSock[0], "", strlen(""), 0 );
		return 1;
	}
	else 
		return 0;
}

void TCP_Ser::thrMessageCenter(void* p)
{
	TCP_Ser* pp = (TCP_Ser*)p;
	char buff[MR_PackageSize];
	pp->_thr_msg_loop=1;
	while(pp->_thr_msg_loop)
	{
		if(pp->RecvData(buff))
		{
			switch(buff[0])
			{
			case 'l'://left part
				::PostMessageA( (HWND)HWND_BROADCAST,sBroadcastCommand, 291, 0 );
				break;
			case 'r'://right part
				::PostMessageA( (HWND)HWND_BROADCAST,sBroadcastCommand, 292, 0 );
				break;
			default:
				break;
			}
		}
	}
	_endthread();
}