// DynamicTest.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include "calculation.h"
#include "GetString.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int ia = 8, ib = 4;
	int integerValue = 42;
    unsigned int unsignedValue = 42;
    double doubleValue = 42.42;

	printf("%d + %d = %d \r\n", ia, ib, additon(ia, ib));
	printf("%d + %d = %d \r\n", ia, ib, subraction(ia, ib));
	printf("%d + %d = %d \r\n", ia, ib, multiplication(ia, ib));
	printf("%d + %d = %d \r\n", ia, ib, division(ia, ib));

	cout << "Integer value: " << IntegerTo(integerValue) << endl;
    cout << "Unsigned integer value: " << UnsignedInt(unsignedValue) << endl;
    cout << "Double value: " << Double(doubleValue) << endl;
    cout << "Current time: " << CurrentTime() << endl;
    cout << "Current date: " << CurrentDate() << endl;
	getchar();
    return 0;
}
