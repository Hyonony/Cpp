#include "stdafx.h"
#include "Progress1Thread.h"

CProgress1Thread::CProgress1Thread(CProgressCtrl& progress)
	: m_Progress(progress)
{
	// TODO: ���⿡ �ʿ��� �ʱ�ȭ �ڵ� �߰�
	m_CurrentPos = 0;
}

CProgress1Thread::~CProgress1Thread()
{
	// TODO: ���⿡ �ʿ��� ���� �ڵ� �߰�
}

int CProgress1Thread::sequence()
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
