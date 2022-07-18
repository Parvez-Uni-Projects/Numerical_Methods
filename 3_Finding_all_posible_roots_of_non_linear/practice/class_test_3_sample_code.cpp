#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return (((x * x * x) - (7 * x * x) + (15 * x) - 9));
}
void vector_print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

double horner(vector<int> v, int x)
{
    int size = v.size() - 1;
    double res = v[size];
    for (int i = size - 1; i >= 0; i--)
        res = (res * x) + v[i];

    return res;
}

double def_horner(vector<int> v, int x)
{
    int size = v.size() - 1;
    for (int i = 0; i < v.size(); i++)
    {
        v[i] *= i;
    }
    vector_print(v);
    return horner(v, x);
}
void multiple_root_using_bisection(vector<int> v)
{

    double a = 0;
    double b = 5;
    float ds = .5;
    float x1 = a;
    float x2 = x1 + ds;
    float error = .00001;
    float xr;
    int i = 0;

    while (x2 < b)
    {
        x1 = a;
        x2 = x1 + ds;

        if (horner(v, x1) * horner(v, x2) > 0)
        {
            cout << "Wrong gues kiddo " << endl;
        }
        else
        {

            float err;

            do
            {
                xr = (x1 + x2) / 2.0;

                if (horner(v, x1) * horner(v, xr) < 0)
                {
                    x2 = xr;
                }
                else
                    x1 = xr;

            } while (fabs((x2 - x1) / x2) >= error);

            cout << "The root is " << xr << endl;

            if (x2 > b)
            {
                break;
            }
        }

        a = x2;
    }
}

void multiple_root_using_newton(vector<int> v)
{
    
}
int main()
{
    cout << f(1);
    cout << endl;
    vector<int> v = {-9, 15, -7, 1};
    vector_print(v);
    cout << endl;
    cout << horner(v, 1) << endl;
    cout << "\nfrom differentiation " << def_horner(v, 1) << endl;

    multiple_root_using_bisection(v);
    multiple_root_using_newton(v);

    return 0;
}