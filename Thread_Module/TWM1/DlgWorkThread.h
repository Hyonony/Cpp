#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "WorkThread.h"
#include "Progress1Thread.h"
#include "Progress2Thread.h"
#include "Progress3Thread.h"
#include "Progress4Thread.h"

// CDlgWorkThread 대화 상자입니다.

class CDlgWorkThread : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgWorkThread)

	CProgress1Thread m_PThread1;
	CProgress1Thread m_PThread2;
	CProgress1Thread m_PThread3;
	CProgress1Thread m_PThread4;



public:
	CDlgWorkThread(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgWorkThread();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WORKTHREAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	
	
	
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CProgressCtrl m_ProgressCtrl1;
	CProgressCtrl m_ProgressCtrl2;
	CProgressCtrl m_ProgressCtrl3;
	CProgressCtrl m_ProgressCtrl4;
	CButton m_Button1;
	CButton m_Button2;
	CButton m_Button3;
	CButton m_Button4;
};
