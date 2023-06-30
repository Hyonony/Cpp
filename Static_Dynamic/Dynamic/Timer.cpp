#include "StdAfx.h"
#include "Timer.h"
#include <time.h>

DYNAMIC_API CTimer::CTimer(double dCheckTime) 
	: m_dCheckTime(dCheckTime)
{
	startTimer();
}

DYNAMIC_API bool CTimer::checkOverTime() 
{

	// ���� �ð�(������)
	long lCurrent = clock();

	double dFollowTime = (double)(lCurrent - m_lStart) / 1000;

	// ���� �ð�(lCurrent)��� m_dCheckTime �ʰ� �귶�� �� ������ true
	if ( m_dCheckTime <= dFollowTime )
	{
		return true;
	}

	return false;
}
DYNAMIC_API void CTimer::startTimer()
{
	m_lStart = clock();
}
