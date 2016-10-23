#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack
{
private:
    T* stack;
    int top;
    int capacity;
public:
    Stack(int stackCapacity);
    bool IsEmpty() const;
    T& Top() const;
    void Push(const T& item);
    void Pop();
    void ShowStack();
    vector<Stack<T> > DivideStack();
    Stack<T> MergeStack(Stack<T> St1, Stack<T> St2);
};

template <class T>
Stack<T>::Stack(int stackCapacity):
    capacity(stackCapacity)
{
    if (capacity < 1) throw "Stack capacity must be > 0";
    stack = new T[capacity];
    top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const {return top == -1;}

template <class T>
inline T& Stack<T>::Top() const
{
    if (IsEmpty()) throw "Stack is empty";
    return stack[top];
}

// Need to change the size of top == capacity-1 (full)
template <class T>
void Stack<T>::Push(const T&x){stack[++top] = x;}

template <class T>
void Stack<T>::Pop()
{   //Hsin: it'd better not use "throw" in constructor...
    if (IsEmpty()) throw "Stack is empty. Cannot delete.";
    stack[top--].~T();
}

template <class T>
void Stack<T>::ShowStack()
{
    for (int i = 0; i <= top; ++i)
    {
        cout <<  "[" << stack[i] << "]";
    }
    cout << endl;
}

template <class T>
vector<Stack<T> > Stack<T>::DivideStack()
{
    if (IsEmpty() || top == 0) throw "Cannot divide.";

    int mid_idx = top / 2;
    Stack<T> ret1(mid_idx+1), ret2(top-mid_idx+1);
    for (int i = 0; i <= mid_idx; ++i)
    {
        ret1.Push(stack[i]);
    }
    for (int j = mid_idx+1; j <= top; ++j)
    {
        ret2.Push(stack[j]);
    }

    vector<Stack<T> > ret;
    ret.push_back(ret1);
    ret.push_back(ret2);
    return ret;
}

template <class T>
Stack<T> Stack<T>::MergeStack(Stack<T> St1, Stack<T> St2)
{
    Stack<T> ret(St1.capacity+St2.capacity);
    for (int i = 0; i <= St1.top; ++i)
    {
        ret.Push(St1.stack[i]);
    }
    for (int j = 0; j <= St2.top; ++j)
    {
        ret.Push(St2.stack[j]);
    }
    return ret;
}

int main(int argc, const char * argv[])
{
    int Capacity = 10;
    Stack<int> St(Capacity);
    St.Push(10);
    St.Push(20);
    St.Push(30);

    vector<Stack<int> > St_v;
    St_v = St.DivideStack();
    St_v[0].ShowStack();
    St_v[1].ShowStack();

    Stack<int> St1(Capacity);
    Stack<int> St2(Capacity);
    St1.Push(10);
    St1.Push(20);
    St2.Push(30);
    Stack<int> St3(Capacity);
    St3 = St3.MergeStack(St1, St2);
    St3.ShowStack();

    return 0;
}
