#pragma once
#include "MyString.h"

#define EXTENSION_SIZE (3)

class CLog
{
private:
	CMyString m_strExtenstion;

public:
	CLog(CMyString strExtension = "txt");
	virtual ~CLog() {}

	int write(CMyString strMessage);
};
