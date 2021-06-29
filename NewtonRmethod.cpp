#include <bits/stdc++.h>
using namespace std;

double eps = 0.000001;

double f(double x)
{
    return (x * x - 122);
}

double prime(double x)
{
    return (2 * x);
}

double newton(double x)
{
    return (x - (f(x) / prime(x)));
}

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

cin>>a;
cin>>b; 

while (a<=b)
{
    cout<<a<<"   "<<sqroot(a)<<endl;
    a=a+0.1;
}

return 0;

}