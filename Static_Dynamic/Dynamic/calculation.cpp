#include "StdAfx.h"
#include "calculation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern "C" DYNAMIC_API int additon(int _a, int _b)
{
	return _a + _b;
}
extern "C" DYNAMIC_API int subraction(int _a, int _b)
{
	return _a - _b;
}
extern "C" DYNAMIC_API int multiplication(int _a, int _b)
{ 
	return _a * _b;
}
extern "C" DYNAMIC_API int division(int _a, int _b)
{
	return _a / _b;
}