#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <memory>
#include "Dynamic.h"

using namespace std;

#define INPUT_SIZE (512)

class DYNAMIC_API CMyString
{
	unique_ptr<char[]> m_upBuffer;

	int setString(char* pcString);
public:
	CMyString(char* pcString = NULL);
	CMyString(CMyString& rString);
	virtual ~CMyString(void) {}

	CMyString operator+(CMyString& rString);
	CMyString& operator+=(CMyString& rString);
	CMyString& operator=(CMyString& rString);
	CMyString& operator=(char* pData);
	int operator==(CMyString& rString);
	CMyString& Format(const char* pcFormat, ...);
	
	operator char*();
	friend DYNAMIC_API ostream& operator<<(ostream& OutputStream, CMyString& rString);
	friend DYNAMIC_API istream& operator>>(istream& InputStream, CMyString& rString);
	
	int getSize();
};