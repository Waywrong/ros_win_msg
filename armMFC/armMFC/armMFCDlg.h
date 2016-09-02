
// armMFCDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include <Mmsystem.h>
#pragma   comment(lib,"winmm.lib")

#define CM_IRA		(WM_APP+200)

// CarmMFCDlg dialog
class CarmMFCDlg : public CDialogEx
{
// Construction
public:
	CarmMFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ARMMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnStart();
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnBnClickedBtnM1();
	CEdit edMsg;
	afx_msg LRESULT onBroadcastCommand( UINT aMsg, LPARAM lParam );
	afx_msg void OnBnClickedBtnUp();
	afx_msg void OnBnClickedBtnDown();
	afx_msg void OnBnClickedBtnLeft();
	afx_msg void OnBnClickedBtnRight();
	afx_msg void OnBnClickedBtnPcl();
	afx_msg void OnBnClickedBtnSound();
};
