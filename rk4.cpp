//Code: RK4 method
#include <bits/stdc++.h>
using namespace std;

double drag(double t, double x)
{
    return (10 - x * x);
}

int main()
{
    //initial values and four points of RK methods. taking from t=0 to t=2
    double t0 = 0, v0 = 0, v, tf = 2, k1, k2, k3, k4, k;
    //number of steps n
    int n = 10000;

    //step size
    double h = (tf - t0) / n;

    //algorithm of rk methods.

    for (int i = 0; i < n; i++)
    {
        k1 = h * drag(t0, v0);
        k2 = h * drag((t0 + h / 2), (v0 + k1 / 2));
        k3 = h * drag((t0 + h / 2), (v0 + k2 / 2));
        k4 = h * drag((t0 + h), (v0 + k3));
        k = (k1 + 2 * (k2 + k3) + k4) / 6;
        v = v0 + k;
        //printing t and v. 
        cout << t0 << "     " << v << endl;
        t0 = t0 + h;
        v0 = v;
    }

    
    

    return 0;
}