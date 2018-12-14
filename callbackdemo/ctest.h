#ifndef CTEST_H
#define CTEST_H

typedef void ( *callbackpro)(int *count);
class CTest
{
public:
    CTest(callbackpro callback);

    void startExec();

private:
    callbackpro m_callback;
};

#endif // CTEST_H
