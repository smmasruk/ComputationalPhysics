
//Code:I will use  Euler method to solve this problem.
#include <bits/stdc++.h>
using namespace std;
//The function I have got above.
double f(double x, double m)
{
    return (sqrt(2) / sqrt(cos(x) - cos(m)));
}

//whih a specific value of the amplitude this function will give the priod of the pendulum 

//And the return of this function is T. 
double finalPeriod(double m)
{
    double x0 = 0, xf = m, s0 = 0;

    int n = 1000;

    double h = (xf - x0) / n;

    for (int i = 0; i < n; i++)
    {
        s0 = s0 + h * f(x0, m);
        x0 += h;
    }
    return s0;
}

int main()
{
    cout << setprecision(8);

    //making a list of Amplitude and T. here i is the Amplitude and output of the function is T.  
    
    //range is given  [0,4]
    for (double i = 0; i < 4; i += 0.001)
    {
        cout << i << "      " << finalPeriod(i) << endl;
    }

    return 0;
}