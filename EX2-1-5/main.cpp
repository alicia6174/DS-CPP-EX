#include "complex.h"
#include <math.h>

class Qdt
{
public:
    int a, b, c;
    Qdt():
        a(0), b(0), c(0)
    {}
    Qdt(int a, int b, int c):
        a(a), b(b), c(c)
    {}
    Qdt operator+(const Qdt &q);
    friend ostream& operator<<(ostream &s, const Qdt &q);
    friend istream& operator>>(istream &s, Qdt &q);
    int Eval(int x){return (a*x*x + b*x + c);}
    void Solve();
};

Qdt Qdt::operator+(const Qdt &q)
{
    a += q.a;
    b += q.b;
    c += q.c;
    return *this;
}

ostream& operator<<(ostream &s, const Qdt &q)
{
    s << "The polynomial is: " << q.a << " x^2 + " << q.b << " x + " << q.c << endl;
    return s;
}

istream& operator>>(istream &s, Qdt &q)
{
    cout << "Input a polynomial: ";
    s >> q.a >> q.b >> q.c;
    return s;
}

void Qdt::Solve()
{
    if (a == 0) cout << "Please consider a quadratic polynomial!" << endl;
    int D = b*b-4*a*c;
    double r = -b/(2.0*a);
    double s = sqrt(b*b-4.0*a*c)/(2.0*a);
    if (D == 0) cout << "The root: " << r << endl;
    if (D > 0) cout << "The root: " << r+s << "," << r-s << endl;
    if (D < 0)
    {
        double i = sqrt(-b*b+4.0*a*c)/(2.0*a);
        Cpx c(r, i);
        Cpx d(r, -i);
        cout << "The roots: " << endl;
        cout << c;
        cout << d;
    }
}

int main(int argc, const char * argv[])
{
    #if 0
    Qdt p;
    Qdt q(1, 2, 3);
    cout << p+q;
    #endif

    #if 0
    Qdt r;
    cin >> r;
    cout << r;
    #endif

    #if 0
    Qdt s(1, 1, 1);
    printf("s(1)=%d\n", s.Eval(1));
    #endif

    #if 1
    Qdt t(1, 1, 1);
    t.Solve();
    #endif

    return 0;
}
