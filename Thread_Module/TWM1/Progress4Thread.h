#pragma once
#include "WorkThread.h"
#include <Windows.h>

class CProgress4Thread :
	public CWorkThread
{
	CProgressCtrl& m_Progress;
	int m_CurrentPos;
public:
	CProgress4Thread(CProgressCtrl& progress);
	~CProgress4Thread();



private:
	int sequence();

};

