#include "StdAfx.h"
#include "GetString.h"


extern "C" DYNAMIC_API CMyString IntegerTo(int nValue)
{
	CMyString strValue;
	strValue.Format("%d", nValue);
	return strValue;
}

extern "C" DYNAMIC_API CMyString UnsignedInt(unsigned int nValue)
{
	CMyString UnsignValue;
	UnsignValue.Format("%d", nValue);
	return UnsignValue;
}

extern "C" DYNAMIC_API CMyString Double(double nValue)
{
	CMyString UnsignValue;
	UnsignValue.Format("%lf", nValue);
	return UnsignValue;
}

extern "C" DYNAMIC_API CMyString CurrentTime()
{
	time_t rawTime;
    struct tm TimeInfo;

    rawTime = time(NULL);
    localtime_s(&TimeInfo, &rawTime);

    CMyString formattedTime;
    formattedTime.Format("%02d:%02d:%02d", TimeInfo.tm_hour, TimeInfo.tm_min, TimeInfo.tm_sec);

    return formattedTime;
}

extern "C" DYNAMIC_API CMyString CurrentDate()
{
	time_t rawTime;
    struct tm TimeInfo;

    rawTime = time(NULL);
    localtime_s(&TimeInfo, &rawTime);

    CMyString formattedDate;
    formattedDate.Format("%04d-%02d-%02d", TimeInfo.tm_year + 1900, TimeInfo.tm_mon + 1, TimeInfo.tm_mday);

    return formattedDate;
}
