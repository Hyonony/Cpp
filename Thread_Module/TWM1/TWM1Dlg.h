
// TWM1Dlg.h : ��� ����
//

#pragma once


// CTWM1Dlg ��ȭ ����
class CTWM1Dlg : public CDialogEx
{
	CDialog* m_pDlgChild;
// �����Դϴ�.
public:
	CTWM1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	~CTWM1Dlg();
// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TWM1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnWorkthread();
};
