#include "stdafx.h"
#include "Progress4Thread.h"

CProgress4Thread::CProgress4Thread(CProgressCtrl& progress)
	: m_Progress(progress)
{
	m_CurrentPos = 0;
	// TODO: ���⿡ �ʿ��� �ʱ�ȭ �ڵ� �߰�
}

CProgress4Thread::~CProgress4Thread()
{
	// TODO: ���⿡ �ʿ��� ���� �ڵ� �߰�
}

int CProgress4Thread::sequence()
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
