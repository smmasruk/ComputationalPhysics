// This program generates a random walk
// in 2D where the size of the walk is fixed. 

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <sys/types.h>
#include <unistd.h>
#include <fstream>

using namespace std;


int main(){


  //Initial position of the particle 
  double x=0;
  double y=0;
  double r;
  double theta;
  // the displacement in each step '

  double dr,dtheta;
  srand(time(NULL)*getpid());
  ofstream write("Walk.data");

    for ( int k=0; k < 800000; k++){

      dr=drand48() ; 
      dtheta=2 * M_PI * drand48();
      //      cout << dx << "    " << dy << endl;
      x+=dr*cos(dtheta);
      y+=dr*sin(dtheta);
      
      write <<log(k) <<"     " <<   x<< "      " << y << "     "<<  log(sqrt(x*x + y*y))<<  endl;
    }
    return(0);
}



// Find how the RMS displacement error scale with your time steps.

// This will require you to write a function that calculates the

// standard deviation from a sample.
