#include "stdafx.h"
#include "Progress2Thread.h"

CProgress2Thread::CProgress2Thread(CProgressCtrl& progress)
	: m_Progress(progress)
{
	// TODO: 여기에 필요한 초기화 코드 추가
	m_CurrentPos = 0;
}

CProgress2Thread::~CProgress2Thread()
{
	// TODO: 여기에 필요한 정리 코드 추가
}

int CProgress2Thread::sequence()
{
	// TODO: 구현
	Sleep(1);

	m_Progress.SetPos(m_CurrentPos);
	m_CurrentPos++;

	if (100 < m_CurrentPos)
	{
		m_CurrentPos = 0;
	}

	return 0;
}
