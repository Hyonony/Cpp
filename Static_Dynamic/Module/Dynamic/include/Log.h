#pragma once
#include "MyString.h"
#include "Dynamic.h"

#define EXTENSION_SIZE (3)
 

class DYNAMIC_API CLog
{
private:
	CMyString m_strExtenstion;

public:
	CLog(CMyString strExtension = "txt");
	virtual ~CLog() {}

	int write(CMyString strMessage);
};
