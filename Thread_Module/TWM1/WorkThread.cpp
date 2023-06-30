#include "stdafx.h"
#include "WorkThread.h"

CWorkThread::CWorkThread(DWORD dwTimeout)
	: m_dwTimeout(dwTimeout), m_bEnd(false), m_threadStatus(eNONE)
{
	// TODO: 여기에 필요한 초기화 코드를 추가하십시오.
}

CWorkThread::~CWorkThread()
{
	if (m_pThread != nullptr)
	{
		if (m_threadStatus == eSTART)
		{
			m_bEnd = true;
			WaitForSingleObject(m_pThread->m_hThread, INFINITE);
		}

		delete m_pThread;
		m_pThread = nullptr;
	}
}

int CWorkThread::stop()
{
	if (m_pThread != nullptr)
	{
		m_pThread->SuspendThread();
		m_threadStatus = eSTOP;
	};
	// m_threadStatus = eSTART;

	return 0;
}
int CWorkThread::run()
{
	if (m_threadStatus == eNONE)
	{
		m_pThread = ::AfxBeginThread(
			ThreadProc,
			this,
			THREAD_PRIORITY_NORMAL,
			0,
			CREATE_SUSPENDED,
			NULL);
		m_threadStatus = eSTOP;
	}

	if (m_threadStatus != eSTART)
	{
		m_pThread->ResumeThread();
		m_threadStatus = eSTART;
	}
	return 0;
}

void CWorkThread::setEnd()
{
	m_bEnd = true;
}

int CWorkThread::getThreadStatus() //Thread 상태 값 구현
{
	return m_threadStatus;
}

UINT CWorkThread::ThreadProc(LPVOID lpParam)
{
	CWorkThread* pObject = (CWorkThread*)lpParam;

	while (!pObject->m_bEnd)
	{
		Sleep(1);
		pObject->sequence();
	}
	return 0;
}
int CWorkThread::sequence()
{
	// TODO: 구현

	return 0;
}