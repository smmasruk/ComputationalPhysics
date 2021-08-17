#include <bits/stdtr1c++.h>
using namespace std;
typedef complex<double> dcmplx;
//defining sqrt(-1) or i.
const dcmplx I = dcmplx(0, 1.0);

int main()
{
    //basically x= 5+3i

    dcmplx x = dcmplx(5, 3);

    cout << real(x) << "    " << imag(x) << endl;

    //e^i*pi so it gives cos pi and i sin pi.
    cout << exp(I * M_PI) << endl;

    cout << log(x) << endl;
    dcmplx y;
    //finding conjugate of x
    y = conj(x);
    cout << real(y) << "    " << imag(y) << endl;
}
