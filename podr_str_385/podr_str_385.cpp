#include <iostream>

using namespace std;

float calculateFunction(float x)
{
    return (3 * x * x + x - 2);
}

bool zeroN(float a, float b, float& x)
{
    x = (a + b) / 2;
    if (calculateFunction(x) != 0)
    {
        if (signbit(calculateFunction(a)) != signbit(calculateFunction(x)))
        {
            zeroN(a, x, x);
        }
        else if (signbit(calculateFunction(x)) != signbit(calculateFunction(b)))
        {
            zeroN(x, b, x);
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
    float x;
    float a = 0;
    float b = 0.9;
    zeroN(a, b, x);
    cout << x << endl;
    if (zeroN(a, b, x))
    {
        cout << "jest " << x << endl;
    }
    else
    {
        cout << "nie ma" << endl;
    }
    return 0;
}