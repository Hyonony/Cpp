#pragma once
#include "WorkThread.h"
#include <Windows.h>

class CProgress3Thread :
	public CWorkThread
{
	CProgressCtrl& m_Progress;
	int m_CurrentPos;
public:
	CProgress3Thread(CProgressCtrl& progress);
	~CProgress3Thread();



private:
	int sequence();

};

