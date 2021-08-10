
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
//Fucntion to calculate mean
long double findMean(long double arr[], int u)
{
    long double sum = 0, count = 0;

    for (int i = 0; i <= u; i++)
    {
        sum += arr[i];
        count++;
    }

    long double mean = (sum / count);
    return mean;
}
//Function to calculate standardDeviation
long double standardDeviation(long double a[], int n)
{

    double mean = findMean(a, n);
    long double sqD = 0;
    for (int i = 0; i < n; i++)
    {
        sqD += (a[i] - mean) *
               (a[i] - mean);
    }
    long double v = sqD / (n - 1);
    return (sqrt(v));
}

double gamma(long double x)
{
    double z;
    if (x == 0 || x == 1)
    {
        return 1;
    }
    else if (x == 0.5)
    {
        return (sqrt(M_PI));
    }
    else
    {
        return ((x - 1) * gamma(x - 1));
    }
}

long double volumeGamma(long double n)
{
    //considering the radious is 1
    long double d = gamma((n / 2) + 1);
    return (powl(M_PI, n / 2) / d);
}
//volume using monte carlo algorith.
long double volMonte(long double n)
{
    //number of points: 2^25
    long double N = powl(2, 25);
    srand48(time(NULL) * getpid());
    long double var, counter = 0;
    long double sum = 0;
    for (int i = 0; i < N; i++)
    {
        //n is the dimention.
        for (int i = 0; i < n; i++)
        {
            var = 2 * drand48() - 1;
            sum += var * var;
        }

        if (sum <= 1)
        {
            counter++;
        }
        sum = 0;
    }

    return (pow(2, n) * counter / N);
}

int main()
{

    cout << setprecision(12);

    //to run the loop 16 times:
    int run = 16;
    long double arr[run];
    //dim=3 to 12
    for (int i = 3; i <= 12; i++)
    {
        for (int j = 0; j <= run; j++)
        {
            arr[j] = volMonte(i);
        }

        cout << i << " " << volumeGamma(i) << "    " << findMean(arr, run - 1) << " " << standardDeviation(arr, run - 1) << endl;
    }

    return 0;
}