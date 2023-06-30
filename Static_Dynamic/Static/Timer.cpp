
#include "Timer.h"
#include <time.h>

CTimer::CTimer(double dCheckTime) 
	: m_dCheckTime(dCheckTime)
{
	startTimer();
}

bool CTimer::checkOverTime() 
{

	// 현재 시간(세컨드)
	long lCurrent = clock();

	double dFollowTime = (double)(lCurrent - m_lStart) / 1000;

	// 현재 시간(lCurrent)대비 m_dCheckTime 초간 흘렀을 때 같으면 true
	if ( m_dCheckTime <= dFollowTime )
	{
		return true;
	}

	return false;
}
void CTimer::startTimer()
{
	m_lStart = clock();
}
