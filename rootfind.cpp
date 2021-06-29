#include <iostream>

#include <cmath>

using namespace std;

double f(double x)
{
    //You can put your fucntions as you like.
    return (tanh(x) - 0.5 * x);
}

int main()
{
    double a, b, c, d;

    cout << "press 1 to solve via avarage method" << endl;
    cout << "press 2 to solve via second method" << endl;
    cin >> d;

    cout << "input lowar range: a " << endl;

    cin >> a;

    cout << "input upper range: b " << endl;

    cin >> b;
    int i = 0;

    if (f(a) * f(b) >= 0)
    {

        cout << "invalid input" << endl;
    }

    else
    {
        for (i = 0; fabs(f(a) - f(b)) >= 0.001; i++)
        {
            //d=1 for avarage method
            if (d == 1)
            {
                c = (a + b) / 2;
            }
            //d=2 for second method
            else if (d == 2)
            {
                if (f(b) - f(a) == 0)
                {
                    cout << " 0 on the denominator, undefined. change upper and lower limit " << endl;
                    break;
                }

                c = ((a * f(b) - b * f(a)) / (f(b) - f(a)));
            }
            if (fabs(f(c) - 0) <= 0.001)
            {
                break;
            }

            else if (f(a) * f(c) > 0)
            {

                a = c;
            }
            else if (f(b) * f(c) > 0)
            {

                b = c;
            }
            //checking change of the range and number of loops
            // cout << a << " /a " << b << "  /b " << c << "/c " << i << endl;
        }
    }
    //checking final range and number of loops
    //cout << a << " / " << b << " / " << c << " / " << i << endl;
    cout << "root of the equation is: " << c << endl;
    return 0;
}