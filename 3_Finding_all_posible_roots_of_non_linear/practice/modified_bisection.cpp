#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return (((x * x * x) - (7 * x * x) + (15 * x) - 9));
}
double horners(vector<int> v, double x)
{
    int n = v.size() - 1;
    double res = v[n];

    for (int i = n - 1; i >= 0; i--)
    {
        res = (res * x) + v[i];
    }

    return res;
}
int main()
{
    double a = 2;
    double b = 5;
    double err = .0001;
    vector<int> v = {-9, 15, -7, 1};
    double x2, x1;

    do
    {

        x1 = (a + b) / 2.0;

        if (f(x1) * f(a) > 0)
        {
              a = x1;
        }
        else
        {
              b = x1;
        }
        cout << "The root is " << x1 << endl;

    } while (fabs(b - a / b) >= err);
    cout << "The root is " << x1 << endl;
}