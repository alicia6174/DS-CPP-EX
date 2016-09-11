#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/*-----------------------------Ideas----------------------------
 * Metho.I   Use array to onstruct the table of Pasca triangles.
 * Method.II Use Finite Status Machine
 * ------------------------------------------------------------*/

struct Frame
{
    Frame(int n = 0, int k = 0, int s = 0):
        arg_n(n),
        arg_k(k),
        st(s)
    {

    }

    int arg_n;
    int arg_k;

    int local_tmp;

    int ret;
    int st;
};

//stack<sys_st_data_t> sys_st;

template <class T>
class Stack
{
    int m_sp;
    T m_buf[1024];

public:
    Stack(void):
        m_sp(0)
    {
    }

    T * top(void)
    {
        return &m_buf[m_sp-1];
    }

    T pop(void)
    {
        return m_buf[--m_sp];
    }

    void push(const T & t)
    {
        m_buf[m_sp++] = t;
    }

    bool empty(void) const
    {
        return m_sp == 0;
    }

    int size(void)
    {
        return m_sp;
    }

};

enum
{
    ST_RETURE = 64
};

int g_itr_cnt = 0;
int CnkItr(int n, int k)
{

    Stack<Frame> sys_st;

    sys_st.push(Frame(n, k));


    int ret_val = 0;

    int max_sp = 0;

    int arr[30][30];
    memset(arr, 0, sizeof(arr));

    while (!sys_st.empty())
    {
        int st = sys_st.top()->st;
        int n = sys_st.top()->arg_n;
        int k = sys_st.top()->arg_k;

        max_sp = max(max_sp, sys_st.size());
        switch (st)
        {
            case 0:
                g_itr_cnt++;
                /*---Add Table---*/
                if (arr[n][k] > 0)
                {
                    ret_val = arr[n][k];
                    sys_st.pop();
                    break;
                }
                /*----------------*/
                if (n == k || n == 0 || k == 0)
                {
                    ret_val = 1;
                    arr[n][k] = 1;

                    sys_st.pop();
                    break;
                }

                //call C(n-1, k-1)
                sys_st.top()->st = 1;
                sys_st.push(Frame(n-1, k-1));
                break;

            case 1:
                // got C(n-1, k-1)
                sys_st.top()->local_tmp = ret_val;

                //call C(n-1, k)
                sys_st.top()->st = 2;
                sys_st.push(Frame(n-1, k));
                break;

            case 2:
                // got C(n-1, k-1), C(n-1, k)
                ret_val = sys_st.top()->local_tmp + ret_val;
                sys_st.pop();
                /*---Add Table---*/
                arr[n][k] = ret_val;
                /*---------------*/
                break;


        };

    }

    printf("max sp = %d\n", max_sp);
    return ret_val;

}

int g_rec_cnt = 0;
int CnkRec(int n, int k)
{
    ++g_rec_cnt;
    if (n == 0 || k == 0 || n == k)
        return 1;

    return CnkRec(n-1, k-1) + CnkRec(n-1, k);
}

int main(int argc, const char * argv[])
{
    int n = 30;
    int k = 15;

    // n = 6;
    // k = 4;
    
    printf("%d, %d times\n", CnkItr(n,k), g_itr_cnt);
//    printf("%d, %d times\n", CnkRec(n,k), g_rec_cnt);
    return 0;
}
