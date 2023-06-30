// DynamicTest.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"
#include <windows.h>
#include "Log.h"
#include "Timer.h"
#include "MyString.h"

#pragma comment(lib, "Dynamic.lib")

int main(int argc, _TCHAR*argv[])
{
	HINSTANCE hinst; //LoadLibary�� ���� �ڵ�
	int(*pFunc)(int, int); //�Լ��� ���� �Լ�������
	CMyString(*pFunc2)(int);
	CMyString(*pFuncU)(unsigned int);
	CMyString(*pFuncD)(double);
	CMyString(*pFuncDate)();
	CMyString(*pFuncTime)();

	int integerValue = 42;
    unsigned int unsignedValue = 42;
    double doubleValue = 42.42;
	int ia = 12, ib = 4;
	
	//DLL�� �ε��Ѵ�.
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


	//�޸𸮿��� ����
	FreeLibrary(hinst);

	getchar();

    return 0;
}

