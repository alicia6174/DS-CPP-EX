#include <stdio.h>
#include <iostream>
using namespace std;

class Arr
{
    int m_size;
    float *m_buf;
public:
    //#(a)
    Arr(int n, float v):
        m_size(n),
        m_buf(new float[n])
    {
        for (int i = 0; i < n; ++i)
        {
            m_buf[i] = v;
        }
    }

    //Does it satisfy #(b)?
    //(not used as 'Arr a = b'...)

    Arr(const Arr &a)
    {
        *this = a;
    }

    //Does this satisfy #(c)?
    //(not of the prototype 'Arr &operator='...)
    Arr & operator=(const Arr &a)
    {
        m_size = a.m_size;
        m_buf = new float(m_size);

        for (int i = 0; i < m_size; ++i)
        {
            m_buf[i] = a.m_buf[i];
        }

        return *this;
    }

    //#(d) error: pointer being freed was not allocated.. ?
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
    for (int i = 0; i < a.m_size; ++i)
    {
        s << "[" << a.m_buf[i] << "]";
    }
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
        Arr a(3, 0);
        cin >> a;
        cout << a;
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
