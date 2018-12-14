#include "ctest.h"

CTest::CTest(callbackpro callback)
{
    m_callback =callback;
}

void CTest::startExec()
{
    int num = 10;
    m_callback(&num);
}
