    double x;
    int N = 1000;
    dcmplx sum;
    for (int k = -N; k < N; k++)
    {
        sum = dcmplx(0, 0);
        for (x = -20; x < 20; x += 0.02)
        {
            sum += ((dcmplx)f(x, 3)) * exp(-2 * M_PI * I * x * (dcmplx)k / (double)N);
        }
        output << real(sum) << " " << imag(sum) << endl;
    }
    for (x = -20; x < 20; x += 0.02)
    {
        orig << f(x, 3) << endl;
    }