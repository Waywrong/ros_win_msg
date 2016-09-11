#pragma once
#define	CM_SOCK	(WM_APP+312)
#include <afxsock.h>
#define MR_PackageSize 100

class TCP_Ser
{
public:
	TCP_Ser(int iPort,void* pCWnd);
	~TCP_Ser(void);
	void InitializeAll(void);
	int  GetUnusedConnectNum(void);
	int	 GetSensorData(byte *myBufferBytes);
	void SendCMD(char* szCMD);
	int RecvData(char* buff);
	static  void thrMessageCenter(void* p);
	CWnd*				pUI;//get the dialog CWnd pointer
	SOCKET				serSock;
	SOCKET				msgSock[50];
	sockaddr_in			stAddr;
	int					addlen;
	int iSensor[8];
	int iSensorIndex;
	bool IsReadSensorMode;//1:sensor mode, 0:Command mode
protected:
	bool _thr_msg_loop;
};
