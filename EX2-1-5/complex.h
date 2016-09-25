#ifndef COMPLEX_H
#define COMPLEX_H
#include <stdio.h>
#include <iostream>
using namespace std;

class Cpx
{
public:
    double real, imag;
    Cpx():
        real(0),
        imag(0)
    {}
    Cpx(double r, double i):
        real(r),
        imag(i)
    {}
    Cpx operator+(const Cpx &d);
    Cpx operator*(const Cpx &d);
    friend ostream& operator<<(ostream &os, const Cpx &d);
    friend istream& operator>>(istream &os, Cpx &d);
};

#endif
