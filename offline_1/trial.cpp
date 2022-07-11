#include <bits/stdc++.h>
using namespace std;

double FunctionEvaluate(double x)
{
    return ((x * x * x) - x - 1);
}

int main()
{
    float a = 1;
    float b = 2;
    float e = .000001;
    float x = 0;
    float old_x = 0;

    int i = 1;

    cout << fixed << setprecision(10);
    cout << "No of iteration \t\tApproximate Root\t\tAbsolute Error \t\tRelative Error" << endl;
    do
    {
        x = (a + b) / 2.0; // for bisection method
        //x = a - ((FunctionEvaluate(a) * (b - a)) / (FunctionEvaluate(b) - FunctionEvaluate(a)));
        if (FunctionEvaluate(x) * FunctionEvaluate(a) < 0)

            b = x;

        else
            a = x;

        // cout << fabs(FunctionEvaluate(x)) << endl;
        cout << i << "\t\t\t\t" << x << "\t\t\t" << fabs(x - old_x) << "\t\t" << fabs((x - old_x) / x) << endl;

        old_x = x;
        i++;

    } while (fabs(FunctionEvaluate(x)) >= e);

    cout << "Ther root is " << x;
}