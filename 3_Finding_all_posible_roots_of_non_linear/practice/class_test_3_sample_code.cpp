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
    // vector_print(v);
    return horner(v, x);
}

// void deflat_equ(double x,double ar[])
// {
//     double b[n+1];
//     int i;
//     b[n]=0;
//     for(i=n-1;i>=0;i--)
//         b[i]=ar[i+1]+x*b[i+1];
//     for(i=n-1;i>=0;i--)
//         ar[i]=b[i];
//     n--;
// }
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

    double x1 = 1.0, f, fd;
    int i = 0;
    double x = 7;
    int n = 4;
    double next = 1.0;

    while (n > 1)
    {
             cout << next << endl;
        do
        {
           
            x1 = x - (horner(v, x) / def_horner(v, x));


            next = x;
            x= x1;

        } while (fabs(horner(v, x1)) > 0.0000001);
        // deflat_equ((x1+x)/2.0,ar);
        cout << "The root is " << x1 << " " << next << endl;

         x= (x1+ next) /2.0;
    
        n--;
    }

    // printf("Root %d: %lf",++i,-(ar[0]/ar[1]));
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

    cout << "\n\n Root using newton" << endl;
    multiple_root_using_newton(v);

    return 0;
}

// sirs code
// while(n>1)
//     {
//         while(fabs((x1-x)/x1)>=0.00000000001)
//         {
//             x=x1;
//             f=horner_equ(x,ar);
//             fd=derive_equ(x,ar);
//             x1=x-(f/fd);
//         }
//         deflat_equ((x1+x)/2.0,ar);
//         printf("Root %d: %lf\n",++i,(x1+x)/2.0);
//         x=(x1+x)/2.0;
//     }
//     printf("Root %d: %lf",++i,-(ar[0]/ar[1]));