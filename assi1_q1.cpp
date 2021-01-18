#include <bits/stdc++.h>
using namespace std;
// Change A,B,C,D accorgind to Ay''+By'+cy = D
double A(double x)
{
    return x*x;
}
double B(double x)
{
    return x;
}
double C(double x)
{
    return 0.0;
}
double D(double x)
{
    return 1.0;
}
double a_index(double x, double h)
{
    double A_ind = (A(x) / (h * h)) - (B(x) / (2.0 * h));
    return A_ind;
}
double b_index(double x, double h)
{
    double B_ind = -(2.0 * A(x) / (h * h)) + C(x);
    return B_ind;
}
double c_index(double x, double h)
{
    double C_ind = (A(x) / (h * h)) + (B(x) / (2.0 * h));
    return C_ind;
}
int main()
{
    double h = 0.1;
    double x_0 = 1.0;
    double x_n = 1.4;
    int n = (x_n - x_0) / h + 0.5;
    double *YY = new double[n + 1];
    double *XX = new double[n + 1];
    double *AA = new double[n + 1];
    double *BB = new double[n + 1];
    double *CC = new double[n + 1];
    double *DD = new double[n + 1];
    double *C_bar = new double[n + 1];
    double *D_bar = new double[n + 1];
    XX[0] = 1;
    YY[0] = 0.0;
    YY[n] = 0.0566;
    for (int i = 1; i <= n; i++)
    {
        XX[i] = XX[i - 1] + h;
        AA[i] = a_index(XX[i], h);
        BB[i] = b_index(XX[i], h);
        CC[i] = c_index(XX[i], h);
        DD[i] = D(XX[i]);
    }
    C_bar[1] = CC[1] / BB[1];
    D_bar[1] = (1 - AA[1] * YY[0]) / BB[1];

    for (int i = 2; i < (n - 1); i++)
    {
        C_bar[i] = CC[i] / (BB[i] - AA[i] * C_bar[i - 1]);
        D_bar[i] = (1 - AA[i] * D_bar[i - 1]) / (BB[i] - AA[i] * C_bar[i - 1]);
    }
    YY[n - 1] = (DD[n] - CC[n - 1] * YY[n] - AA[n - 1] * D_bar[n - 2]) / (BB[n - 1] - AA[n - 1] * C_bar[n - 2]);

    for (int i = n - 2; i >= 1; i--)
    {
        YY[i] = D_bar[i] - C_bar[i] * YY[i + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        cout << "y(" << XX[i] << ") = " << YY[i] << "\n";
    }

    return 0;
}