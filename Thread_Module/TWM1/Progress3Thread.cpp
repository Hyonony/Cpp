#include "stdafx.h"
#include "Progress3Thread.h"

CProgress3Thread::CProgress3Thread(CProgressCtrl& progress)
	: m_Progress(progress)
{
	m_CurrentPos = 0;
	// TODO: 여기에 필요한 초기화 코드 추가
}

CProgress3Thread::~CProgress3Thread()
{
	// TODO: 여기에 필요한 정리 코드 추가
}

int CProgress3Thread::sequence()
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
