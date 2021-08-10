#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

double boxMuller(double u1, double u2)
{
    double y1 = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    double y2 = sqrt(-2 * log(u1)) * sin(2 * M_PI * u2);
    return (y1);
}

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

long double variance(long double a[], int n)
{

    double mean = findMean(a, n);
    long double sqD = 0;
    for (int i = 0; i < n; i++)
    {
        sqD += (a[i] - mean) *
               (a[i] - mean);
    }
    long double v = sqD / (n - 1);
    return v;
}

long double kurtosis(long double a[], int n)
{

    double mean = findMean(a, n);

    long double sqD = 0;
    for (int i = 0; i < n; i++)
    {
        sqD += powl((a[i] - mean), 4);
    }
    long double s = sqD / powl(variance(a, n), 2);
    return s / n;
}

int main()
{
    fixed(cout);

    cout << setprecision(10);
    int N = pow(2, 16);
    long double arr[N];
    int n = sizeof(arr) / sizeof(arr[0]);
    long double u1, u2, y1, y2;
    srand48(time(NULL) * getpid());
    for (int i = 0; i < N; i++)
    {
        u1 = drand48();
        u2 = drand48();

        arr[i] = boxMuller(u1,u2);
    }

    //Solution to a. Sorted in a single file.
    sort(arr, arr + n);
    for (int i = 0; i < N; i++) 
    {

        cout << arr[i] << endl;
    }
    //solution to b.

    long double mean = findMean(arr, N - 1);
    cout << "The Mean is: " << mean << endl;
    //Solution to c.

    cout << "The variance is: "<<variance(arr, N - 1) << endl;
    cout<<"The kurtosis is: " << kurtosis(arr, N - 1) << endl;

    return 0;
}