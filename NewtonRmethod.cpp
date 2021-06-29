#include <bits/stdc++.h>
using namespace std;

double eps = 0.000001;
//functions to find square root. but any function could be used. 
double f(double x)
{
    return (x * x - 122);
}
//derivative of the functions 
double prime(double x)
{
    return (2 * x);
}
//formula of newton ralphson method. 
double newton(double x)
{
    return (x - (f(x) / prime(x)));
}
//condition to find the solution with in a range 
double sqroot(double x)
{
    while (fabs(f(x)) > eps)
    {
        x = newton(x);
    }

    return x;
}
int main(){
    cout<<setprecision(8);

double a, b;
//a is the lower limit of the range 
cin>>a;

//b is the upper limit of the range
cin>>b; 

while (a<=b)
{
    cout<<a<<"   "<<sqroot(a)<<endl;
    a=a+0.1;
}

return 0;

}