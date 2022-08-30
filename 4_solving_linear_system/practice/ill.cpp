#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

float a[SIZE][SIZE], x[SIZE], b[SIZE][SIZE], ab[SIZE][SIZE], pivot = 0;
float B[20][20];
int i, j, k, n, cont = 0, cont2 = 0;
double sum, x1 = 1;

float checkIllCondition(float matrix[][SIZE], int n)
{
    float det = 0;
    float submatrix[10][10];
    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * checkIllCondition(submatrix, n - 1));
        }
    }
    return det;
}
float f1(float x, float y, float z)
{
    float a, b, c, d;
    a = B[1][1];
    b = B[1][2];
    c = B[1][3];
    d = B[1][4];
    x = (d - b * y - c * z) / a;
    return x;
}

float f2(float x, float y, float z)
{
    float a, b, c, d;
    a = B[2][1];
    b = B[2][2];
    c = B[2][3];
    d = B[2][4];
    y = (d - a * x - c * z) / b;
    return y;
}

float f3(float x, float y, float z)
{
    float a, b, c, d;
    a = B[3][1];
    b = B[3][2];
    c = B[3][3];
    d = B[3][4];
    z = (d - a * x - b * y) / c;
    return z;
}

void guassSeidal()
{
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
    e = 0.005; //relative error falls below 0.05.

    do
    {
        x1 = f1(x0, y0, z0);
        y1 = f2(x1, y0, z0);
        z1 = f3(x1, y1, z0);

        e1 = fabs((x0 - x1) / x0);
        e2 = fabs((y0 - y1) / y0);
        e3 = fabs((z0 - z1) / z0);

        cont2++;

        x0 = x1;
        y0 = y1;
        z0 = z1;

    } while (e1 > e && e2 > e && e3 > e);

    printf("\nStarting of Execution Gauss Seidal Method\n");
    cout << "\nThe solution of linear equation is:\n";
    cout << "x[1]=" << x1 << endl;
    cout << "x[2]=" << y1 << endl;
    cout << "x[3]=" << z1 << endl;

    // printf("total number of flops for gauss jorden method for 3 equations: ");
    // r3 = n1 * n1 * n1 * n1;
    // cout << r3 << "\n";
    // printf("total number of flops for gauss jorden method for 6 equations: ");
    // r4 = n2 * n2 * n2 * n2;
    // cout << r4 << "\n";

    cout << "\nEnd of execution.....\n";
}

void gaussJordan()
{
    //Apply Gauss Jordan Elimination on Matrix a:
    cout << " Gauss Jordan\n";
    for (i = 1; i <= n; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Mathematical Error!");
        }
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                pivot = a[j][i] / a[i][i];
                for (k = 1; k <= n + 1; k++)
                {
                    a[j][k] = a[j][k] - pivot * a[i][k];
                }
            }
        }
    }

    /* Obtaining Solution */
    for (i = 1; i <= n; i++)
    {
        x[i] = a[i][n + 1] / a[i][i];
    }

    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
}

void gaussElimination()
{
    // Forward Elimination
    cout << " Gauss Elimination\n";
    //loop over all rows except last
    for (i = 1; i <= n - 1; i++)
    {
        // if (b[i][i] == 0.0)
        // {
        //     printf("Error!");
        //     exit(0);
        // }

        //loop over all rows bellow the diagonal position, //all the row accept first row
        for (j = i + 1; j <= n; j++)
        {
            pivot = b[j][i] / b[i][i];
            //search for pivot element
            //loop over all columns right of the diagonal position
            for (k = j + 1; k <= n + 1; k++) //access the coloums
            {
                b[j][k] = b[j][k] - pivot * b[i][k]; //aij = aij - akj * ajk/akk
            }
        }
    }

    // Forward Substitution
    // Compute last unknown
    x[n] = b[n][n + 1] / b[n][n];
    //loop over all the row except last row
    for (i = n - 1; i >= 1; i--)
    {
        x[i] = b[i][n + 1];
        //loop over all columns to the right of the current row
        for (j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - b[i][j] * x[j]; // sum = sum + a[k][j] * x[j]
        }
        x[i] = x[i] / b[i][i];
    }

    printf("\nThe solution of linear equation is:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
}

int main()
{
    printf("Enter the size of the equations: ");
    scanf("%d", &n);

    printf("Enter the elements of Coefficients\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            int temp;
            printf("A[%d][%d] : ", i, j);
            // cin >> a[i][j];
            scanf("%f", &temp);
            a[i][j] = temp;
            b[i][j] = temp;
        }
    }
    /* Applying Gauss Jordan Elimination */
    if (a[1][2] / a[1][1] == a[2][3] / a[2][2] == a[3][1] / a[3][3])
    {
        printf("\nNo solution");
    }
    else
    {
        // gaussJordan();
        for (int k = 1; k <= n; k++)
        {
            for (int j = 1; j <= n; j++)
            {

                ab[k][j] = a[k][j];
            }
        }
        int det = checkIllCondition(ab, n);
        // cout << "\nDeterminant of the matrix is " << det << "\n";
        if (det < 1)
        {
            cout << "\n\nIf ill conditioned then solution using Iterative methods are:";
            //gaussElimination();

             guassSeidal();
            // gaussJordan();
        }
        else
        {
            cout << "\n\nThe System is well condition and can be solved by direct method";
            gaussJordan();
        }
    }
    // cout << "\nThe system is well conditioned and can be solved by direct methods\n\n\n";

    return 0;
}
/*
Input

3

7 7 -7 2
-1 11 7 1
11 5 7 0


Enter the size of the equations: 3
Enter the elements of Coefficients
a[1][1] = 7
a[1][2] = 7
a[1][3] = -7
a[1][4] = 2
a[2][1] = -1
a[2][2] = 11
a[2][3] = 7
a[2][4] = 1
a[3][1] = 11
a[3][2] = 5
a[3][3] = 7
a[3][4] = 0

*/
