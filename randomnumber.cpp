#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/types.h>
using namespace std;
int main()
{
    srand48(0);
    //cout<<getpid()*time(NULL)<<endl;
  // cout<< drand((getpid() * time(NULL))<<endl;
    
    cout<<drand48()<<endl;
    return 0;
}