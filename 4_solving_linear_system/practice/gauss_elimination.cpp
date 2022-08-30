#include <bits/stdc++.h>
using namespace std;
#define SIZE 100

vector<double> co_eff[SIZE];
vector<double>
void take_input(int n)
{

    for (int i = 1; i <= n; i++)
    {
        int temp;
        for (int j = 1; j <= n + 1; j++)
        {
            // cout << "Co-efficient of a " << i << " " << j << endl;
            cin >> temp;

            co_eff[i].push_back(temp);
        }
    }

    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cout << co_eff[i][j - 1] << " ";
        }
        cout << endl;
    }
}

void gauss_elimination(int n)
{

    double factor;
    for (int k = 1; k <= n - 1; k++)
    {
        for (int i = k + 1 ; i  <= n; i++)
        {
            factor = co_eff[i][k - 1] / co_eff[k][k - 1];
            for (int j = k; j <= n + 1; j++)
            {
                co_eff[i][j - 1] = co_eff[i][j-1] - factor * co_eff[k][j-1];
            }
        }
    }
}

int main()
{
    cout << "Enter the order of the matrix " << endl;
    int n;
    cin >> n;
    take_input(n);

    gauss_elimination(n);
}