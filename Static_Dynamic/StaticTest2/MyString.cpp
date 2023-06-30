
#include "MyString.h"

CMyString::CMyString(CMyString& rString)
{
	setString(rString.m_upBuffer.get());
}

CMyString::CMyString(char* pcString) 
{
	setString(pcString);
}

int CMyString::setString(char* pcString)
{
	if (NULL == pcString)
	{
		m_upBuffer.reset(new char);
		m_upBuffer.get()[0] = '\0';
	}
	else
	{
		int nLength = strlen(pcString) + 1;
		m_upBuffer.reset(new char[nLength]);
		strcpy_s(m_upBuffer.get(), nLength, pcString);
	}

	return getSize();
}

CMyString CMyString::operator+(CMyString& rString)
{
    int nLength = getSize() + rString.getSize() + 1;

    std::auto_ptr<char> upBuffer(new char[nLength]);
    strcpy_s(upBuffer.get(), nLength, m_upBuffer.get());
    strcat_s(upBuffer.get(), nLength, rString.m_upBuffer.get());

    CMyString strReturn(upBuffer.get());

    return strReturn;
}

CMyString& CMyString::operator+=(CMyString& rString)
{
	return *this = *this + rString;
}

CMyString& CMyString::operator=(CMyString& rString)
{
	setString(rString.m_upBuffer.get());
	return *this;
}

CMyString& CMyString::operator=(char* pData)
{
	setString(pData);
	return *this;
}

int CMyString::operator==(CMyString& rString)
{
	return !strcmp(m_upBuffer.get(), rString.m_upBuffer.get());
}

CMyString::operator char*()
{
	return m_upBuffer.get();
}

ostream& operator<<(ostream& OutputStream, CMyString& rString)
{
	OutputStream << rString.m_upBuffer.get();
	return OutputStream;
}

istream& operator>>(istream& InputStream, CMyString& rString)
{
	char szString[INPUT_SIZE];
	InputStream >> szString;
	rString = szString;
	return InputStream;
}

int CMyString::getSize()
{
	return strlen(m_upBuffer.get());
}

CMyString& CMyString::Format(const char* pcFormat, ...)
{
	va_list Args;
	va_start(Args, pcFormat); //Args 포인터가 pkcFormat만큼 가변 변수들을 차례로 가리킴

	int nLength = _vscprintf(pcFormat, Args) + 1; // 가변인자로 이루어진 문자열의 크기를 구한다.
	
	m_upBuffer.reset(new char[nLength]);

	vsnprintf(m_upBuffer.get(), nLength, pcFormat, Args); //출력	
	va_end(Args);

	return *this;
}

