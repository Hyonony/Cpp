#include "GetString.h"

CMyString IntegerTo(int nValue)
{
	CMyString strValue;
	strValue.Format("%d", nValue);
	return strValue;
}

CMyString UnsignedInt(unsigned int nValue)
{
	CMyString UnsignValue;
	UnsignValue.Format("%d", nValue);
	return UnsignValue;
}

CMyString Double(double nValue)
{
	CMyString UnsignValue;
	UnsignValue.Format("%lf", nValue);
	return UnsignValue;
}

CMyString CurrentTime()
{
	time_t rawTime;
    struct tm TimeInfo;

    rawTime = time(NULL);
    localtime_s(&TimeInfo, &rawTime);

    CMyString formattedTime;
    formattedTime.Format("%02d:%02d:%02d", TimeInfo.tm_hour, TimeInfo.tm_min, TimeInfo.tm_sec);

    return formattedTime;
}

CMyString CurrentDate()
{
	time_t rawTime;
    struct tm TimeInfo;

    rawTime = time(NULL);
    localtime_s(&TimeInfo, &rawTime);

    CMyString formattedDate;
    formattedDate.Format("%04d-%02d-%02d", TimeInfo.tm_year + 1900, TimeInfo.tm_mon + 1, TimeInfo.tm_mday);

    return formattedDate;
}
