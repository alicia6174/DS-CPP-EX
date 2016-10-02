#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Term
{
public:
    float cof;
    int exp;
    Term():
        cof(0),
        exp(0){};
    Term(float cof, int exp):
        cof(cof),
        exp(exp){};
};

class Poly
{
private:
    vector<Term> terms;
    int num_terms;   // # of non-zero terms
public:
    Poly()
    {
        Term term = Term();
        terms.push_back(term);
        num_terms = 0;
    }
    Poly(float cof, int exp)
    {
        Term term = Term(cof, exp);
        terms.push_back(term);
        num_terms = 1;
    }
    void addNewTerm(const int exp, const float cof);
    Poly operator+(Poly &p);
    Poly operator-(Poly &p);
    Poly Mult(Poly p); // undone
    float operator()(float x);
    friend ostream& operator<<(ostream &s, const Poly &p);
    friend istream& operator>>(istream &s, Poly &p);
};

void Poly::addNewTerm(const int exp, const float cof)
{
    Term newTerm = Term(exp, cof);
    terms.push_back(newTerm);
}

// Only for polynomials with coeficients in descending order..
// For general ones, we need a compare function to sort them first.
Poly Poly::operator+(Poly &p)
{
    Poly ret = Poly();
    vector<Term>::iterator itr = terms.begin();
    vector<Term>::iterator itrp = (p.terms).begin();
    if (terms[0].cof == 0 && terms[0].exp == 0) itr++; // to skip 0x^0
    while (itr != terms.end() && itrp != p.terms.end())
    {
        if (itr->exp == itrp->exp)
        {
            float tmp = itr->cof + itrp->cof;
            if (tmp) ret.addNewTerm(tmp, itr->exp);
            itr++; itrp++;
        }
        else if (itr->exp < itrp->exp)
        {
           ret.addNewTerm(itrp->cof, itrp->exp);
           itrp++;
        }
        else
        {
           ret.addNewTerm(itr->cof, itr->exp);
           itr++;
        }
    }

    for (; itr != terms.end(); itr++) ret.addNewTerm(itr->cof, itr->exp);
    for (; itrp != p.terms.end(); itrp++) ret.addNewTerm(itrp->cof, itrp->exp);
    return ret;
}

// only for polynomials with coeficients in descending order
Poly Poly::operator-(Poly &p)
{
    Poly ret = Poly();
    vector<Term>::iterator itrp = (p.terms).begin();
    while (itrp != p.terms.end())
    {
        itrp->cof = itrp->cof * (-1);
        itrp++;
    }

    ret = *this + p;
    return ret;
}


float Poly::operator()(float x)
{
    float ret = 0.0;
    vector<Term>::iterator itr = (terms).begin();
    while (itr != terms.end())
    {
        ret += itr->cof * pow(x, itr->exp);
        itr++;
    }
    return ret;

}

ostream& operator<<(ostream &s, const Poly &p)
{
    int cur = 0;
    if (p.terms[0].cof == 0 && p.terms[0].exp == 0)
    {
        cur++;
        s << (p.terms[cur]).cof << "x^" << (p.terms[cur]).exp;
    }
    else
    {
        s << (p.terms[cur]).cof << "x^" << (p.terms[cur]).exp;
    }
    for (int i = cur+1; i < p.terms.size(); ++i)
    {
        if (p.terms[i].cof == 0 && p.terms[i].exp == 0) i++;
        s << "+"  << (p.terms[i]).cof << "x^" << (p.terms[i]).exp;
    }
    s << endl;
    return s;
}

int main(int argc, const char * argv[])
{
    Poly p = Poly(4, 5);
    p.addNewTerm(2, 3);
    cout << p;
    Poly q = Poly(1, 3);
    p = p + q;
    cout << p;
    p = p - q;
    cout << p;
    printf("p(%d) = %.1f\n", 2, p(2));
    return 0;
}
