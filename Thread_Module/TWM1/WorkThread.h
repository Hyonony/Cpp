#pragma once
#include <afxwin.h>


class CWorkThread 
{
	CWinThread* m_pThread;
public:
	enum _eWT_STATUS{ 
		eNONE = 0, 
		eSTART = 1,
		eSTOP = 2
	};

	CWorkThread(DWORD dwTimeout = 1000);
	~CWorkThread();

	int stop();
	int run();
	void setEnd();
	int getThreadStatus();

private:
	static UINT ThreadProc(LPVOID lpParam);
	virtual int sequence();

	LPVOID m_lpParam;
	DWORD m_dwTimeout;
	HANDLE m_hThread;
	int m_threadStatus;
	bool m_bEnd;
};