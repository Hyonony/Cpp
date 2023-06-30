#pragma once
#include "WorkThread.h"
#include <Windows.h>

class CProgress1Thread :
	public CWorkThread
{
	CProgressCtrl& m_Progress;
	int m_CurrentPos;
public:
	CProgress1Thread(CProgressCtrl& progress);
	~CProgress1Thread();


private:
	int sequence();

};

