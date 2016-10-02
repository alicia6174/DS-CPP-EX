#include <stdio.h>
#include <iostream>
using namespace std;

class Arr
{
    int siz;
    float *arr;
public:
    //#(a)
    Arr(int n, float v)
    {
        siz = n;
        arr = (float*) malloc(sizeof(float)*n);
        for (int i = 0; i < n; ++i)
        {
            arr[i] = v;
        }
    }

    //Does it satisfy #(b)?
    //(not used as 'Arr a = b'...)
    Arr(const Arr &a)
    {
        siz = a.siz;
        //arr = (float*) malloc(sizeof(float)*siz);
        arr = new float(siz);
        for (int i = 0; i < siz; ++i)
        {
            arr[i] = a.arr[i];
        }
    }

    //Does this satisfy #(c)?
    //(not of the prototype 'Arr &operator='...)
    void operator=(const Arr &a)
    {
        siz = a.siz;
        arr = (float*) malloc(sizeof(float)*siz);
        for (int i = 0; i < siz; ++i)
        {
            arr[i] = a.arr[i];
        }
    }

    //#(d) error: pointer being freed was not allocated.. ?
    ~Arr(){delete arr;}

    //#(e)
    float& operator[](int i)
    {
        if (i >= siz)
        {
            fprintf(stderr, "Error.");
            exit(-1);
        }
        return arr[i];
    }

    //#(f)
    int getSize(){return siz;}

    //#(g)
    friend ostream& operator<<(ostream &s, const Arr &a);
    friend istream& operator>>(istream &s, Arr &a)
    {
        cout << "Input the size." << endl;
        s >> a.siz;
        cout << "Input a data number." << endl;
        float tmp;
        int cnt = 0;
        while ( (s >> tmp) && (cnt < a.siz) )
        {
            a.arr[cnt] = tmp;
            cnt++;
            cout << "Input the next data number." << endl;
            cout << "Enter \\n to end the key-in." << endl;
            // This sentence shows once more.. (why?)
        }
        return s;
    }
};

ostream& operator<<(ostream &s, const Arr &a)
{
    for (int i = 0; i < a.siz; ++i)
    {
        s << "[" << a.arr[i] << "]";
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
    #if 0
    Arr a(3, 0);
    cin >> a;
    cout << a;
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
