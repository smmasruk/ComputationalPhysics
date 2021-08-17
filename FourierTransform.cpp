#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>
const double PI = 4.0 * atan(1.0);
using namespace std;
typedef complex<double> dcmplx;
const dcmplx I = dcmplx(0.0, 1.0);
double f(double x, double a)
{
    return (exp(-x * x / a));
}

int main()
{
    ofstream output("fourier_transform_3.data");
    ofstream orig("function_3.data");
    double x;
    int N = 1000;
    dcmplx sum;
    for (int k = -N; k < N; k++)
    {
        sum = dcmplx(0, 0);
        for (x = -20; x < 20; x += 0.02)
        {
            sum += ((dcmplx)f(x, 3)) * exp(-2 * M_PI * I * x * (dcmplx)k / (double)N);
        }
        output << real(sum) << " " << imag(sum) << endl;
    }
    for (x = -20; x < 20; x += 0.02)
    {
        orig << f(x, 3) << endl;
    }

    return (0);
}