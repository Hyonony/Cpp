#include "stdafx.h"
#include "Progress2Thread.h"

CProgress2Thread::CProgress2Thread(CProgressCtrl& progress)
	: m_Progress(progress)
{
	// TODO: ���⿡ �ʿ��� �ʱ�ȭ �ڵ� �߰�
	m_CurrentPos = 0;
}

CProgress2Thread::~CProgress2Thread()
{
	// TODO: ���⿡ �ʿ��� ���� �ڵ� �߰�
}

int CProgress2Thread::sequence()
{
	// TODO: ����
	Sleep(1);

	m_Progress.SetPos(m_CurrentPos);
	m_CurrentPos++;

	if (100 < m_CurrentPos)
	{
		m_CurrentPos = 0;
	}

	return 0;
}
