
// armMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "armMFC.h"
#include "armMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static UINT sBroadcastCommand = ::RegisterWindowMessage("iCeiRA_Message");
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CarmMFCDlg dialog




CarmMFCDlg::CarmMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CarmMFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CarmMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edMsg);
}

BEGIN_MESSAGE_MAP(CarmMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_START, &CarmMFCDlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_EXIT, &CarmMFCDlg::OnBnClickedBtnExit)
	ON_BN_CLICKED(IDC_BTN_M1, &CarmMFCDlg::OnBnClickedBtnM1)
	ON_BN_CLICKED(IDC_BTN_UP, &CarmMFCDlg::OnBnClickedBtnUp)
	ON_BN_CLICKED(IDC_BTN_DOWN, &CarmMFCDlg::OnBnClickedBtnDown)
	ON_BN_CLICKED(IDC_BTN_LEFT, &CarmMFCDlg::OnBnClickedBtnLeft)
	ON_BN_CLICKED(IDC_BTN_RIGHT, &CarmMFCDlg::OnBnClickedBtnRight)
	ON_REGISTERED_MESSAGE( sBroadcastCommand, CarmMFCDlg::onBroadcastCommand )
	ON_BN_CLICKED(IDC_BTN_PCL, &CarmMFCDlg::OnBnClickedBtnPcl)
END_MESSAGE_MAP()


// CarmMFCDlg message handlers

BOOL CarmMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CarmMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CarmMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CarmMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CarmMFCDlg::OnBnClickedBtnStart()//servo On
{
	// TODO: 在此加入控制項告知處理常式程式碼
}


void CarmMFCDlg::OnBnClickedBtnExit()
{
	CDialogEx::OnCancel();
}


void CarmMFCDlg::OnBnClickedBtnM1()//Left Arm Demo
{
	edMsg.SetWindowText("Left Arm");
}


void CarmMFCDlg::OnBnClickedBtnUp()
{
	::PostMessageA( (HWND)HWND_BROADCAST,sBroadcastCommand, 10 ,1 );
}


void CarmMFCDlg::OnBnClickedBtnDown()
{
	::PostMessageA( (HWND)HWND_BROADCAST,sBroadcastCommand, 10 ,2 );
}


void CarmMFCDlg::OnBnClickedBtnLeft()
{
	::PostMessageA( (HWND)HWND_BROADCAST,sBroadcastCommand, 10 ,3 );
}


void CarmMFCDlg::OnBnClickedBtnRight()
{
	::PostMessageA( (HWND)HWND_BROADCAST,sBroadcastCommand, 10 ,4 );
}



LRESULT CarmMFCDlg::onBroadcastCommand( UINT uID, LPARAM lCmd )
{
	static float fPos[3];
	switch(uID)
	{
	case 20:
		fPos[0]=((float)lCmd)/100.;
		break;
	case 21:
		fPos[1]=((float)lCmd)/100.;
		break;
	case 22:
		fPos[2]=((float)lCmd)/100.;
		break;
	//case 1://connect
	//	this->OnBnClickedBtnClient();
	//	break;
	}
	CString strMsg;
	strMsg.Format("pos:%4.2f, %4.2f, %4.2f",fPos[0],fPos[1],fPos[2]);
	edMsg.SetWindowText(strMsg);
	return 0;
}

void CarmMFCDlg::OnBnClickedBtnPcl()
{
	::PostMessageA( (HWND)HWND_BROADCAST,sBroadcastCommand, 99 ,1 );
}
