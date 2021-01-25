#include <bits/stdc++.h>
using namespace std;
// Change A,B,C,D accorgind to Ay''+By'+cy = D
double A(double x)
{
    return 1.0;
}
double B(double x)
{
    return (-2.0)*x;
}
double C(double x)
{
    return (-2.0);
}
double D(double x)
{
    return (-4.0)*x;
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
    double h = 0.01;
    double x_0 = 0.0;
    double x_n = 1.0;
    int n = (x_n - x_0) / h + 0.5;
    double *YY = new double[n + 1];
    double *XX = new double[n + 1];
    double *AA = new double[n + 1];
    double *BB = new double[n + 1];
    double *CC = new double[n + 1];
    double *DD = new double[n + 1];
    double *C_bar = new double[n + 1];
    double *D_bar = new double[n + 1];
    XX[0] = x_0;
    YY[0] = 1.0;
    AA[0] = a_index(XX[0], h);
    BB[0] = b_index(XX[0], h);
    CC[0] = c_index(XX[0], h);
    DD[0] = D(XX[0]);
    for (int i = 1; i <= n; i++)
    {
        XX[i] = XX[i - 1] + h;
        AA[i] = a_index(XX[i], h);
        BB[i] = b_index(XX[i], h);
        CC[i] = c_index(XX[i], h);
        DD[i] = D(XX[i]);
    }
    BB[0] = BB[0] - 2*AA[0]*h;
    CC[0] = CC[0] + AA[0];
    AA[0] = 0.0;
    AA[4] = AA[4] + CC[4];
    BB[4] = BB[4] + CC[4]*4*h;
    DD[4] = DD[4] + CC[4]*2*h;
    CC[4] = 0;
    C_bar[0] = CC[0] / BB[0];
    D_bar[0] = (DD[0]) / BB[0];
    for (int i = 1; i <= (n); i++)
    {
        C_bar[i] = CC[i] / (BB[i] - AA[i] * C_bar[i - 1]);
        D_bar[i] = (DD[i] - AA[i] * D_bar[i - 1]) / (BB[i] - AA[i] * C_bar[i - 1]);
    }
    YY[n] = D_bar[n];
    for (int i = n - 1; i >= 1; i--)
    {
        YY[i] = D_bar[i] - C_bar[i] * YY[i + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        cout << "y(" << XX[i] << ") = " << YY[i] << "\n";
    }
    return 0;
}