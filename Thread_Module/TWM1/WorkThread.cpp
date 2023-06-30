#include "stdafx.h"
#include "WorkThread.h"

CWorkThread::CWorkThread(DWORD dwTimeout)
	: m_dwTimeout(dwTimeout), m_bEnd(false), m_threadStatus(eNONE)
{

	// TODO: ���⿡ �ʿ��� �ʱ�ȭ �ڵ带 �߰��Ͻʽÿ�.
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
		DWORD dwResult = ::WaitForSingleObject(m_hThread, m_dwTimeout); // ��� �ð��� �ݴϴ�.
		if (WAIT_OBJECT_0 == dwResult)
		{
			Sleep(1);
		}
		else if (WAIT_TIMEOUT == dwResult)
		{
			::TerminateThread(m_hThread, 0); // ��� �ð� �ʰ��� �����带 �����մϴ�.
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

int CWorkThread::getThreadStatus() //Thread ���� �� ����
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