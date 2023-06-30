// DynamicTest.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include <windows.h>
#include "Log.h"
#include "Timer.h"
#include "MyString.h"

#pragma comment(lib, "Dynamic.lib")

int main(int argc, _TCHAR*argv[])
{
	HINSTANCE hinst; //LoadLibary로 얻을 핸들
	int(*pFunc)(int, int); //함수로 얻어올 함수포인터
	CMyString(*pFunc2)(int);
	CMyString(*pFuncU)(unsigned int);
	CMyString(*pFuncD)(double);
	CMyString(*pFuncDate)();
	CMyString(*pFuncTime)();

	int integerValue = 42;
    unsigned int unsignedValue = 42;
    double doubleValue = 42.42;
	int ia = 12, ib = 4;
	
	//DLL을 로드한다.
	if ((hinst = LoadLibrary(_T("Dynamic.dll"))) == NULL)
	{
		return 0;
	}

	if ((pFunc = (int(*)(int, int))GetProcAddress(hinst, "additon")) == NULL)
	{
		return 0;
	}
	printf("%d + %d = %d \r\n", ia, ib, pFunc(ia, ib));
	if ((pFunc = (int(*)(int, int))GetProcAddress(hinst, "subraction")) == NULL)
	{
		return 0;
	}
	printf("%d - %d = %d \r\n", ia, ib, pFunc(ia, ib));
	if ((pFunc = (int(*)(int, int))GetProcAddress(hinst, "multiplication")) == NULL)
	{
		return 0;
	}
	printf("%d * %d = %d \r\n", ia, ib, pFunc(ia, ib));
	if ((pFunc = (int(*)(int, int))GetProcAddress(hinst, "division")) == NULL)
	{
		return 0;
	}
	printf("%d / %d = %d \r\n", ia, ib, pFunc(ia, ib));

	if ((pFunc2 = (CMyString(*)(int))GetProcAddress(hinst, "IntegerTo")) == NULL)
	{
		return 0;
	}
	cout << "Integer value: " << pFunc2(integerValue) << endl;

	if ((pFuncU = (CMyString(*)(unsigned int))GetProcAddress(hinst, "UnsignedInt")) == NULL)
	{
		return 0;
	}
    cout << "Unsigned integer value: " << pFuncU(unsignedValue) << endl;

	if ((pFuncD = (CMyString(*)(double))GetProcAddress(hinst, "Double")) == NULL)
	{
		return 0;
	}
    cout << "Double value: " << pFuncD(doubleValue) << endl;

	if ((pFuncTime = (CMyString(*)())GetProcAddress(hinst, "CurrentTime")) == NULL)
	{
		return 0;
	}
    cout << "Current time: " << pFuncTime() << endl;

	if ((pFuncDate = (CMyString(*)())GetProcAddress(hinst, "CurrentDate")) == NULL)
	{
		return 0;
	}
    cout << "Current date: " << pFuncDate() << endl;


	//메모리에서 제거
	FreeLibrary(hinst);

	getchar();

    return 0;
}

