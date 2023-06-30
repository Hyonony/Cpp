#include "StdAfx.h"
#include "Log.h"

#include <time.h>
#include <fstream>

using namespace std;

DYNAMIC_API CLog::CLog(CMyString strExtension)
{
	m_strExtenstion = strExtension;
}

DYNAMIC_API int CLog::write(CMyString strMessage)
{
	time_t rawTime;
	struct tm TimeInfo;

	rawTime = time(NULL);
	localtime_s(&TimeInfo, &rawTime);

	//2022 7 6.log
	CMyString strFileName;
	strFileName.Format("%4d%02d%02d.%s", TimeInfo.tm_year+1900, TimeInfo.tm_mon+1, TimeInfo.tm_mday, (char*)m_strExtenstion);

	ofstream writeFile;

	// ���� ����� ����, �ִٸ� �� �ڿ� ����
	writeFile.open(strFileName, ios::app);

	if (writeFile.is_open())
	{
		//10:56:20->pcMessage
		CMyString strDate;
		strDate.Format("%2d:%02d:%02d->%s", TimeInfo.tm_hour, TimeInfo.tm_min, TimeInfo.tm_sec, (char*)strMessage);

		writeFile << strDate << endl;

		// ���� �ݱ�
		writeFile.close();
	}
	
	return 0;
}
