#pragma once
#include "WorkThread.h"
#include <Windows.h>

class CProgress2Thread :
	public CWorkThread
{
	CProgressCtrl& m_Progress;
	int m_CurrentPos;
public:
	CProgress2Thread(CProgressCtrl& progress);
	~CProgress2Thread();



private:
	int sequence();

};

