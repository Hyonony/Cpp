#pragma once

class CTimer
{
private:
	double m_dCheckTime;
	long m_lStart;

public:
	CTimer(double m_dCheckTime);
	bool checkOverTime();
	void startTimer();

};

