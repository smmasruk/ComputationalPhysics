#include <bits/stdc++.h>
using namespace std;
//defination of logistic map
double lmap(double lambda, double x)
{
    return (lambda * x * (1 - x));
}

//function to get stable value
double x100(double l, double x)
{
    for (int i = 1; i < 100002; i++)
    {

        x = lmap(l, x);
    }
    return x;
}
//start with any values of x in (0,1) , plot lambda vs x_101

// target x_100 for diffrent initial x
// x=1--x=100
// x=2--x=100
// ...
// x=100--100
//for diffrent lambda.

int main()
{
   // double f, k;

    cout << setprecision(8);
    double x = 0.0001;
    double lambda =1;
    while(lambda<4){
        cout<<lambda<<"         "<<x100(lambda,x)<<endl;
        x=x100(lambda,x);
        lambda+=0.0002;
    }
    
    return 0;
}