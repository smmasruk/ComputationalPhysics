#include <iostream>
using namespace std;
int main()

//this code will find the epsilon of machine
//machine eps using long 
{
    long double x = 2.0;
    int f;
    for (int  i = 1;   1+x>1; i ++)
    {
        x=x/2;
         f=i;
 
    }
    
    cout << "Machine eps is: " << x << endl;
    cout<<f<<endl;

    return 0;
}

