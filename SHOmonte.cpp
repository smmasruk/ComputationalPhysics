
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <unistd.h>

using namespace std;
double my_rand()
{
    return (drand48());
}
// The potential for the system
double V(double x, double lambda)
{
    return (0.5 * x * x + (x * x * x) * lambda / 3.0);
}

//Creates a new configuration from the old config (oldx)
double new_config(double oldx, double dx, double lambda)
{
    double random = 2 * drand48() - 1.0;
    random = (-random) / lambda;
    return (oldx + dx*random);
}
// Metropolis Test
void metropolis(double old, double &newx, double T, 
    double lambda, int &Accepted, int &Rejected, int &Flipped)
{
    double x = newx;
    if (V(x, lambda) < V(old, lambda))
    {
        newx = x;
        // cout << "accepted"<<endl ;
        Accepted++;
    }
    else if (my_rand() <= exp(-(V(x, lambda) - V(old, lambda)) / T))
    {
        newx = x;
        // cout <<"flipped"<<endl ;
        Flipped++;
    }
    else
    {
        newx = old;
        // cout << "rejected"<< endl ;
        Rejected++;
    }
}
//Change the stepsize according to the acceptance ratio
// Only 5% adjustment is made - increasing this percentile leads to disconts.
// trajectories
double adjust(double dx, double acceptance)
{
    if (acceptance > 0.33)
    {
        return (1.05 * dx);
    }
    else if (acceptance < 0.27)
    {
        return (0.95 * dx);
    }
    else
        return (dx);
}
// Function to calculate the averages of an array
double average(double A[], int Samples)
{
    double sum = 0;
    for (int i = 0; i < Samples; i++)
    {
        sum += A[i];
    }
    return (sum / Samples);
}

void expected(double lambda,double T)
{
    
   // ofstream write("jumps.txt");
    double x = 0, Dx = 5, newx = 0; 
    // Initial position, the stepsize and a decoy position
    int Accepted = 0, Rejected = 0, Flipped = 0;

    int k = 0;
    const int Samples = pow(2, 16);
    double Energy[Samples], Energy_Sq[Samples];
    int accepted = 0;
    double acceptance, newdx;
    //The temperature
   
    double xExp[Samples], z[Samples];
    // initiatting the RNG ( random number generator)
    
    // The averages
    double E, E_sq;
    double expetedX;

    for (int i = 0; i < Samples; i++)
    {
        k++;
        // cout << x << " ";
        newx = new_config(x, Dx, lambda);
        metropolis(x, newx, T, lambda, Accepted, Rejected, Flipped);
        acceptance = (double)Accepted / k;
        newdx = adjust(Dx, acceptance);
        Dx = newdx;
        x = newx;
         cout << x << " "<< "Acceptance=" << acceptance<<endl;
        //write << x << "\t" << V(x, lambda) << endl; // data file with x and V(x)
        //Store V(x) AND V^2(X) in an array
        xExp[k] = x;
        Energy[k] = V(x, lambda);
        Energy_Sq[k] = V(x, lambda) * V(x, lambda);
    }

    cout << lambda << " " << average(xExp, Samples) << endl;

    // Statistics of the results
    // E = average(Energy, Samples);
    // E_sq = average(Energy_Sq, Samples);
    // expetedX = average(xExp, Samples);

    // cout << E << "  " << E_sq << "  " << expetedX << endl;
    // cout << "C_v=" << (E_sq - E * E) / (T * T) << "\t" << endl;
}

int main()
{
    srand48(time(NULL));
    cout << setprecision(8);
    double lam = -2.000001;
    double step = 4 / 1000;
    double T=3;
    //cout << "Temperature=?" << endl;
    //cin >> T;

    while (lam < 2.0)
    {
        expected(lam,T);
        lam += 0.0004;
    }

    return 0;
}