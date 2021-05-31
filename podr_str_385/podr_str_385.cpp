#include <iostream>

using namespace std;

float calculateFunction(float x)
{
    return 3 * x * x + x - 2;
}

float calculateFunction2(float x)
{
    return x * x * x + x * x - 2 * x;
}

float calculateFunction3(float x)
{
    return 3 * x*x*x - 2*x*x - 3*x + 2;
}

bool zeroN(float a, float b, int n, int j, float& x)
{
    j++;
    x = (a + b) / 2;
    if (calculateFunction(x) != 0 && j < n)
    {
        if (signbit(calculateFunction(a)) != signbit(calculateFunction(x)))
        {
            zeroN(a, x, n, j, x);
        }
        else if (signbit(calculateFunction(x)) != signbit(calculateFunction(b)))
        {
            zeroN(x, b, n, j, x);
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool zeroDelta1(float a, float b, float delta, float& x)
{
    x = (a + b) / 2;
    if (calculateFunction2(x) != 0 && fabs(calculateFunction2(x)) > delta)
    {
        if (signbit(calculateFunction2(a)) != signbit(calculateFunction2(x)))
        {
            zeroDelta1(a, x, delta, x);
        }
        else if (signbit(calculateFunction2(x)) != signbit(calculateFunction2(b)))
        {
            zeroDelta1(x, b, delta, x);
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool zeroDelta2(float a, float b, float delta, float& x)
{
    x = (a + b) / 2;
    if (calculateFunction3(x) != 0 && fabs(b - a) > delta)
    {
        if (signbit(calculateFunction3(a)) != signbit(calculateFunction3(x)))
        {
            zeroDelta2(a, x, delta, x);
        }
        else if (signbit(calculateFunction3(x)) != signbit(calculateFunction3(b)))
        {
            zeroDelta2(x, b, delta, x);
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int j, n;
    float x;
    float a = 0;
    float b = 0.9;
    n = 10;
    j = 0;
    if (zeroN(a, b, n, j, x))
    {
        cout << "jest " << x << endl;
    }
    else
    {
        cout << "nie ma" << endl;
    }

    //c
    a = -1;
    b = 0.5;
    float delta = 0.01;
    if (zeroDelta1(a, b, delta, x))
    {
        cout << "jest " << x << endl;
    }
    else
    {
        cout << "nie ma" << endl;
    }

    //d
    a = 0;
    b = 0.9;
    delta = 0.1;
    if (zeroDelta2(a, b, delta, x))
    {
        cout << "jest " << x << endl;
    }
    else
    {
        cout << "nie ma" << endl;
    }

    return 0;
}