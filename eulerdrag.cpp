//Code: Eular Method 
#include <bits/stdc++.h>
using namespace std;

double drag(double x)
{
    return (10 - x * x);
}

int main()
{
    cout.precision(8);
    //initial values + variables.
    double v0 = 0;
    double t0 = 0, tf = 2, v, fPrime;
    //assuming final time t=2s dx=h and number of separation n
    int n = 10000;
    double h = ((tf - t0) / n);

    // //Euler methos algorithm

    for (int i = 0; i < n; i++)
    {
        v0 = v0 + h * drag(v0);
        t0 = t0 + h;

        //printing t and v
        cout << t0 << "     " << v0 << endl;
    }

    return 0;
}