#include <bits/stdc++.h>
using namespace std;

int arr[100], degree;

double horners(int *brr, int n, double x)
{
    int j = n;
    double b[n];

    b[j] = brr[j];
    while (j > 0)
    {
        b[j - 1] = brr[j - 1] + (b[j] * x);
        j--;
    }
    return b[0];
}

void newton_raphson()
{

    cout << "\nEnter the initial guess" << endl;
    double initial_guess;
    cin >> initial_guess;

    double x1 = initial_guess;

    double e = .000000000000001;
    cout << fixed << setprecision(6);
    double x2;
    int i = 1;

    cout << "Finding the root using Newton Raphson Method " << endl;

    cout << "**********************************************************************" << endl;
    cout << " Iteration\t x1\t\t F(x1)\t\tF'(x1)" << endl;
    cout << "**********************************************************************" << endl;

    double old_x, new_x;

    int first_der[3] = {-1, 0, 3};

    do
    {

        x2 = x1 - (horners(arr, degree, x1) / horners(first_der, degree - 1, x1));

        cout << i << setw(12) << "" << setw(10) << x1 << "" << setw(17) << horners(arr, degree, x1) << setw(15) << horners(first_der, degree - 1, x1) << endl;

        x1 = x2;
        i++;
        // if (i==5 )break;

    } while (fabs(horners(arr, degree, x1)) > e);
}

void secant()
{
    cout << "Finding the root using Secant Method " << endl;
    double x0, x1;

    cout << "\nEnter the lower initial guess" << endl;
    cin >> x0;
    cout << "\nEnter the upper initial guess" << endl;
    cin >> x1;

    double e = .000000000000001;
    cout << fixed << setprecision(4);

    double x2;

    cout << "**********************************************************************" << endl;
    cout << "iteration" << setw(5) << "" << setw(7) << "x0"
         << "" << setw(17) << "x1"
         << "" << setw(17) << "x2"
         << "" << setw(17) << "f(x0)" << setw(15) << "f(x1)" << setw(15) << "f(x2)" << endl;
    cout << "**********************************************************************" << endl;

    int i = 1;

    do
    {

        x2 = x1 - (horners(arr,degree,x1) * ((x1 - x0) / (horners(arr,degree,x1) - horners(arr,degree,x0))));

        cout << i << setw(12) << "" << setw(10) << x0 << "" << setw(17) << x1 << "" << setw(17) << x2 << "" << setw(17) << horners(arr,degree,x0) << setw(15) << horners(arr,degree,x1) << setw(15) << horners(arr,degree,x2) << endl;

        x0 = x1;
        x1 = x2;
        i++;

    } while (fabs(horners(arr,degree,x1)) > e);
}

int main()
{

    int n;
    cout << "Enter the total no of power" << endl;
    cin >> degree;
    int i = 0;
    cout << "Enter values of coefficients:" << endl;
    while (i <= degree)
    {
        cout << "x^" << i << "::";
        cin >> arr[i];
        cout << endl;
        i++;
    }
    i--;

    cout << "The polynomial is" << endl;
    while (i >= 0)
    {
        cout << arr[i] << "x^" << i << " + ";
        i--;
    }

    // newton_raphson();
    //secant();
    //fixed_point
}