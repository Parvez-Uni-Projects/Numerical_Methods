#include <bits/stdc++.h>

using namespace std;

float f(float x)
{
    return ((x * x * x) - x - 1);
}

int main()
{
    float a = 1;
    float b = 2;
    float e = .000001;
    float x;

    cout << fixed << setprecision(10);

    do
    {
        //x = ((a + b) / 2.0);

        x= a- ((f(a)* (b-a)) / (f(b)-f(a)));

        if (f(x) * f(a) < 0)
        {
            b = x;
        }
        else
        {
            a = x;
        }
    } while (fabs(f(x)) > e);

    cout << x;
}