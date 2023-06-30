#pragma once
#include "MyString.h"
#include "Dynamic.h"
#include <ctime>
#include <iomanip>
#include <sstream>

extern "C" DYNAMIC_API CMyString IntegerTo(int nValue);
extern "C" DYNAMIC_API CMyString UnsignedInt(unsigned int nValue);
extern "C" DYNAMIC_API CMyString Double(double nValue);
extern "C" DYNAMIC_API CMyString CurrentTime();
extern "C" DYNAMIC_API CMyString CurrentDate();