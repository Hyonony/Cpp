// StaticTest.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "calculation.h"
#include "GetString.h"


int main()
{
	printf("��Ģ����\n\n");
	int ia = 8, ib = 4;

	printf("%d + %d = %d \r\n", ia, ib, additon(ia, ib));
	printf("%d - %d = %d \r\n", ia, ib, subraction(ia, ib));
	printf("%d * %d = %d \r\n", ia, ib, multiplication(ia, ib));
	printf("%d / %d = %d \r\n", ia, ib, division(ia, ib));
	getchar();

	printf("\n\n");

	int integerValue = 42;
    unsigned int unsignedValue = 42;
    double doubleValue = 42.42;

    cout << "Integer value: " << IntegerTo(integerValue) << endl;
    cout << "Unsigned integer value: " << UnsignedInt(unsignedValue) << endl;
    cout << "Double value: " << Double(doubleValue) << endl;
    cout << "Current time: " << CurrentTime() << endl;
    cout << "Current date: " << CurrentDate() << endl;

    return 0;
}

