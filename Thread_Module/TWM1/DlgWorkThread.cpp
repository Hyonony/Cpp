// DlgWorkThread.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TWM1.h"
#include "DlgWorkThread.h"
#include "afxdialogex.h"
#include "WorkThread.h"
#include "Progress1Thread.h"
#include "Progress2Thread.h"
#include "Progress3Thread.h"
#include "Progress4Thread.h"


// CDlgWorkThread ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgWorkThread, CDialogEx)


CDlgWorkThread::CDlgWorkThread(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WORKTHREAD, pParent)
	, m_PThread1(m_ProgressCtrl1)
	, m_PThread2(m_ProgressCtrl2)
	, m_PThread3(m_ProgressCtrl3)
	, m_PThread4(m_ProgressCtrl4)
{

}

CDlgWorkThread::~CDlgWorkThread()
{
	

	MSG msg;
	while (::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
	{
		Sleep(10);
		if (!AfxGetApp()->PumpMessage()) {
			::PostQuitMessage(0);
			break;
		}
	}
}

void CDlgWorkThread::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgressCtrl1);
	DDX_Control(pDX, IDC_BUTTON1, m_Button1);
	DDX_Control(pDX, IDC_PROGRESS2, m_ProgressCtrl2);
	DDX_Control(pDX, IDC_PROGRESS3, m_ProgressCtrl3);
	DDX_Control(pDX, IDC_PROGRESS4, m_ProgressCtrl4);
	DDX_Control(pDX, IDC_BUTTON2, m_Button2);
	DDX_Control(pDX, IDC_BUTTON3, m_Button3);
	DDX_Control(pDX, IDC_BUTTON4, m_Button4);
}


BEGIN_MESSAGE_MAP(CDlgWorkThread, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgWorkThread::OnBnClickedButton1)

	ON_BN_CLICKED(IDC_BUTTON2, &CDlgWorkThread::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgWorkThread::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgWorkThread::OnBnClickedButton4)

END_MESSAGE_MAP()


// CDlgWorkThread �޽��� ó�����Դϴ�.


BOOL CDlgWorkThread::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlgWorkThread::OnBnClickedButton1()
{
	if (m_PThread1.getThreadStatus() != CWorkThread::eSTART)
	{
		m_PThread1.run();
		m_Button1.SetWindowTextW(L"������ ����");
	}
	else
	{
		m_PThread1.stop();
		m_Button1.SetWindowTextW(L"������ ����");
	}
}


void CDlgWorkThread::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_PThread2.getThreadStatus() != CWorkThread::eSTART)
	{
		m_PThread2.run();
		m_Button2.SetWindowTextW(L"������ ����");
	}
	else
	{
		m_PThread2.stop();
		m_Button2.SetWindowTextW(L"������ ����");
	}
}


void CDlgWorkThread::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_PThread3.getThreadStatus() != CWorkThread::eSTART)
	{
		m_PThread3.run();
		m_Button3.SetWindowTextW(L"������ ����");
	}
	else
	{
		m_PThread3.stop();
		m_Button3.SetWindowTextW(L"������ ����");
	}
}


void CDlgWorkThread::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_PThread4.getThreadStatus() != CWorkThread::eSTART)
	{
		m_PThread4.run();
		m_Button4.SetWindowTextW(L"������ ����");
	}
	else
	{
		m_PThread4.stop();
		m_Button4.SetWindowTextW(L"������ ����");
	}
}
