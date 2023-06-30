#pragma once
#include <afxwin.h>


class CWorkThread 
{
	
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
	CWinThread* m_pThread;
	static UINT ThreadProc(LPVOID lpParam);
	virtual int sequence() = 0;

	DWORD m_dwTimeout;
	HANDLE m_hThread;
	int m_threadStatus;
	bool m_bEnd;
};