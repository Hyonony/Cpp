
#include "Timer.h"
#include <time.h>

CTimer::CTimer(double dCheckTime) 
	: m_dCheckTime(dCheckTime)
{
	startTimer();
}

bool CTimer::checkOverTime() 
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
void CTimer::startTimer()
{
	m_lStart = clock();
}
