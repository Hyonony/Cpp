#include "stdafx.h"
#include "Progress3Thread.h"

CProgress3Thread::CProgress3Thread(CProgressCtrl& progress)
	: m_Progress(progress)
{
	m_CurrentPos = 0;
	// TODO: ���⿡ �ʿ��� �ʱ�ȭ �ڵ� �߰�
}

CProgress3Thread::~CProgress3Thread()
{
	// TODO: ���⿡ �ʿ��� ���� �ڵ� �߰�
}

int CProgress3Thread::sequence()
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
