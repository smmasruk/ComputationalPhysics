#include <bits/stdc++.h>
#include <fstream>

using namespace std;

typedef complex<double> dcmplx;
//defining sqrt(-1) or i.
const dcmplx I = dcmplx(0, 1.0);

//making things complex

dcmplx mkComplex(double x)
{
    return (exp(I * x));
}

\\step Function 1 double theta(double x)
{
    if (x >= 0)
    {
        return 1;
    }
    else
        return 0;
}

\\step function 2 double thetaPi(double x)
{
    if (x >= M_PI)
    {
        return 0;
    }
    else
        return -1;
}

//force function
double force(double t)
{

    return (4 * theta(t) * thetaPi(t));
}

int main()
{
    ofstream soln("gammsol5.data");
    ofstream ft("ft5.data");
    //initial time and the drag coeficient
    double t = 0, b = 1.1;

    dcmplx x = mkComplex(0.0);
    dcmplx v = mkComplex(1.0);
    dcmplx v_nw;
    dcmplx sum;

    double t_0 = 0, t_f = 100;
    int n = 10000;
    double dt = (t_f - t_0) / n;

    //to store real and complex part of x
    double arrxR[n];
    double arrxC[n];
    for (int i = 1; i <= n; i++)
    {
        soln << i * dt << " " << real(x) << " " << imag(x) << endl;
        arrxR[i] = real(x);
        arrxC[i] = imag(x);
        x += v * dt;
        v_nw = (1 - 2 * b * dt) * v - x * dt + dt * force(i * dt);
        v = v_nw;
    }

    dcmplx p = 0;
    //Fourier Transform
    for (int k = -n; k < n; k++)
    {
        sum = dcmplx(0, 0);
        for (int j = 1; j < n; j++)
        {
            p = dcmplx(arrxR[j], arrxC[j]);
            sum += p * exp(-2 * M_PI * I * (double)j * (dcmplx)k / (double)n);
        }
        ft << real(sum) << " " << imag(sum) << endl;
    }

    return 0;
}
