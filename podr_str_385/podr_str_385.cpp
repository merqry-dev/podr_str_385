#include <iostream>

using namespace std;

float calculateFunction(float x)
{
    return 3 * x * x + x - 2;
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
    return true;
}

bool zeroDelta2(float a, float b, float delta, float& x)
{
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
    return 0;
}