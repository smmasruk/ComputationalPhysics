#include <bits/stdc++.h>
using namespace std;

typedef complex<double> dcmplx;

//defining sqrt(-1) or i.
const dcmplx I = dcmplx(0, 1.0);

//making things complex
dcmplx mkComplex(double x)
{
    return (exp(I * x));
}

struct Pair
{
    dcmplx first;
    dcmplx second;
};

// x1dot = a*x1 + b*x2
// x1dot = c*x1 + d*x2

Pair xdot(Pair x, dcmplx hamiltonian[2][2])
{
    dcmplx a = hamiltonian[0][0];
    dcmplx b = hamiltonian[0][1];
    dcmplx c = hamiltonian[1][0];
    dcmplx d = hamiltonian[1][1];

    Pair x_dot;

    x_dot.first = I * (a * x.first + b * x.second);
    x_dot.second = I * (c * x.first + d * x.second);

    return x_dot;
}

// t = 2,3,4,5,6,7,8
// nt = (8-2)/1

void runge_k(Pair x0, double t0, double tf, double dt, dcmplx hamiltonian[2][2])
{
    int nt = (int)((tf - t0) / dt);

    // initializing time frame
    double t[nt];
    t[0] = t0;
    for (int i = 1; i < nt; i++)
    {
        t[i] = t0 + i * dt;
    }

    (dcmplx) dt;

    // initializing x
    Pair x[nt]; //
    x[0] = x0;

    // calculating x
    for (int i = 0; i < nt - 1; i++)
    {

        //k1 = xdot*h
        //calculating k1
        Pair k1 = xdot(x[i], hamiltonian);

        //k2 = f(x_n+h*k1/2)
        //calculating k2
        Pair temp = x[i];
        temp.first += dt * k1.first / ((dcmplx)2);
        temp.second += dt * k1.second / ((dcmplx)2);
        Pair k2 = xdot(temp, hamiltonian);

        //k3 = f(x_n+h*k2/((dcmplx) 2))
        //calculating k3
        temp = x[i];
        temp.first += dt * k2.first / ((dcmplx)2);
        temp.second += dt * k2.second / ((dcmplx)2);
        Pair k3 = xdot(temp, hamiltonian);

        //k4 = f(x_n+h*k3)
        //calculating k4
        temp = x[i];
        temp.first += dt * k3.first;
        temp.second += dt * k3.second;
        Pair k4 = xdot(temp, hamiltonian);

        //calculating x
        x[i + 1].first = x[i].first + dt * (k1.first + (dcmplx)2 * k2.first + (dcmplx)2 * k3.first + k4.first) / ((dcmplx)6);
        x[i + 1].second = x[i].second + dt * (k1.second + (dcmplx)2 * k2.second + (dcmplx)2 * k3.second + k4.second) / ((dcmplx)6);
    }
    // printing x
    // cout << "t" << "," << "x1" << "," << "x2" << endl;
    for (int i = 0; i < nt; i++)
    {
        //cout << t[i] << " " << real(x[i].first) <<" "<< real(x[i].second)<<endl;
        //cout << t[i] << " " << real(x[i].first) << " " << imag(x[i].first) << " " << real(x[i].second) << " " << imag(x[i].second) << endl;
        cout << t[i] << " " << real(x[i].first * conj(x[i].first)) << " " << real(x[i].second * conj(x[i].second)) << endl;
    }
}

int main()
{
    Pair x0;
    x0.first = 1;
    x0.second = 0;
    double t0 = 0;
    double tf = 10;
    double dt = 0.01;

    dcmplx hamiltoian[2][2] = {
        {(5, 0), (0, 0)},
        {(0, 0), (-5, 0)}};

    runge_k(x0, t0, tf, dt, hamiltoian);
    return 0;
}
