#include "stdafx.h"
#include "WorkThread.h"

CWorkThread::CWorkThread(DWORD dwTimeout)
	: m_dwTimeout(dwTimeout), m_bEnd(false), m_threadStatus(eNONE)
{

	// TODO: 여기에 필요한 초기화 코드를 추가하십시오.
	m_hThread = 0;
}

CWorkThread::~CWorkThread()
{
	if (m_threadStatus == eNONE)
		return;

	setEnd();

	Sleep(10);


	if (GetExitCodeThread(m_hThread, &m_dwTimeout) && m_dwTimeout == STILL_ACTIVE)
	{
		DWORD dwResult = ::WaitForSingleObject(m_hThread, m_dwTimeout); // 대기 시간을 줍니다.
		if (WAIT_OBJECT_0 == dwResult)
		{
			Sleep(1);
		}
		else if (WAIT_TIMEOUT == dwResult)
		{
			::TerminateThread(m_hThread, 0); // 대기 시간 초과된 스레드를 종료합니다.
		}
	}

}

int CWorkThread::stop()
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

		m_hThread = m_pThread->m_hThread;
		m_threadStatus = eSTART;
	}

	if (m_threadStatus != eSTOP)
	{
		m_pThread->ResumeThread();
		m_threadStatus = eSTOP;
	}

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

		m_hThread = m_pThread->m_hThread;
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