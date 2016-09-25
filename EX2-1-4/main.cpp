#include <stdio.h>
#include <iostream>
using namespace std;

class Cpx
{
public:
    int real, imag;
    Cpx():
        real(0),
        imag(0)
    {}
    Cpx(int r, int i):
        real(r),
        imag(i)
    {}
    Cpx operator+(const Cpx &d);
    Cpx operator*(const Cpx &d);
    friend ostream& operator<<(ostream &os, const Cpx &d);
    friend istream& operator>>(istream &os, Cpx &d);
};

Cpx Cpx::operator+(const Cpx &d)
{
    real += d.real;
    imag += d.imag;
    return *this;
}

Cpx Cpx::operator*(const Cpx &d)
{
    int tmp_r = real;
    int tmp_i = imag;
    real = tmp_r*d.real - tmp_i*d.imag;
    imag = tmp_r*d.imag + tmp_i*d.real;
    return *this;
}

ostream& operator<<(ostream &s, const Cpx &d)
{
    s << "Complex number is: " << d.real << "+" << d.imag << "i" << endl;
    return s;
}

istream& operator>>(istream &s, Cpx &d)
{
    cout << "Input a complex number: ";
    s >> d.real >> d.imag;
    return s;
}

int main(int argc, const char * argv[])
{
    Cpx A(3,2);
    Cpx B;
    Cpx C, D;
    cin >> C;
    cin >> D;
    cout << (A+B+C+D);
    cout << (A*B*C*D);

    return 0;
}
