#include "complex.h"

Cpx Cpx::operator+(const Cpx &d)
{
    real += d.real;
    imag += d.imag;
    return *this;
}

Cpx Cpx::operator*(const Cpx &d)
{
    double tmp_r = real;
    double tmp_i = imag;
    real = tmp_r*d.real - tmp_i*d.imag;
    imag = tmp_r*d.imag + tmp_i*d.real;
    return *this;
}

ostream& operator<<(ostream &s, const Cpx &d)
{
    s << d.real << "+" << d.imag << "i" << endl;
    return s;
}

istream& operator>>(istream &s, Cpx &d)
{
    cout << "Input a complex number: ";
    s >> d.real >> d.imag;
    return s;
}

