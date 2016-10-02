#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

class Arr
{
    int m_size;
    float *m_buf;
public:
    //#(a)
    //fill
    Arr(int n, float v):
        m_size(n),
        m_buf(new float[n])
    {
        fill(m_buf, m_buf + m_size, v);
    }

    //#(b)
    //'Arr a(b)' and 'Arr a = b' are the same.
    Arr(const Arr &a)
    {
        *this = a;
    }

    //#(c)
    //The prototype 'void operator='  can't be used to 'p1=p2=p3'
    //copy
    Arr & operator=(const Arr &a)
    {
        delete [] m_buf;
        m_buf = new float[a.m_size];
        m_size = a.m_size;

        copy (a.m_buf, a.m_buf + a.m_size, m_buf);

        return *this;
    }

    //#(d)
    //delete[]
    ~Arr()
    {
        delete [] m_buf;
    }

    //#(e)
    float& operator[](int i)
    {
        if (i >= m_size)
        {
            fprintf(stderr, "Error.");
            exit(-1);
        }
        return m_buf[i];
    }

    //#(f)
    int getSize(){return m_size;}

    //#(g)
    friend ostream& operator<<(ostream &s, const Arr &a);
    friend istream& operator>>(istream &s, Arr &a)
    {
        cout << "Input a data number." << endl;

        int cnt = 0;
        //greedy principle
        while ((cnt < a.m_size) && (s >> a.m_buf[cnt++]) )
        {
            cout << "Input the next data number." << endl;
            cout << "Enter \\n to end the key-in." << endl;
            // This sentence shows once more.. (why?)
        }
        return s;
    }
};

ostream& operator<<(ostream &s, const Arr &a)
{
    //lambda
    //std=c++11
    for_each(a.m_buf, a.m_buf + a.m_size,
            [&s](float v) { s << "[" << v << "]";});

    s << endl;
    return s;
}

int main(int argc, const char * argv[])
{
    //(a),(b),(d)
    #if 0
    Arr a(3, 2);
    cout << a;
    Arr b(a);
    cout << b;
    //b.~Arr();
    #endif

    //(g)
    #if 1
    {
        Arr a(3, 100);
        cout << a;

        Arr b(4, 200);
        cout << b;
        b = a;
        cout << b;

        return 0;
    }
    #endif

    //(c)
    #if 0
    Arr a(3, 0);
    Arr b(3, 5);
    a = b;
    cout << a;
    #endif

    //(e),(f)
    #if 1
    Arr a(3, 3.3);
    printf("Size=%d\n", a.getSize());
    int i =2;
    printf("a[%d]=%.1f\n", i, a[i]);
    #endif

    return 0;
}
