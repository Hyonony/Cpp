#pragma once
#include "MyString.h"
#include <ctime>
#include <iomanip>
#include <sstream>

CMyString IntegerTo(int nValue);
CMyString UnsignedInt(unsigned int nValue);
CMyString Double(double nValue);
CMyString CurrentTime();
CMyString CurrentDate();