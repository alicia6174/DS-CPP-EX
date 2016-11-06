#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue
{
private:
    T* queue;
    int front, rear, capacity, numOfItems;
public:
    Queue(int queueCapacity);
    bool IsEmpty();
    bool IsFull();
    T& Front();
    T& Rear();
    //void Enqueue(const T& item);
    void EnFront(const T& item);
    void EnRear(const T& item);
    //void Dequeue();
    void DeFront();
    void DeRear();
    T& ShowNumOfItems();
    void ShowQueue();
};

template <class T>
Queue<T>::Queue(int queueCapacity):
    capacity(queueCapacity)
{
    if (capacity < 1)
    {
        fprintf(stderr, "Queue capacity must be > 0.\n");
        exit(-1);
    }
    queue = new T[capacity];
    front = rear = 0;
    numOfItems = 0;
}

template <class T>
inline bool Queue<T>::IsEmpty(){return numOfItems == 0;}

template <class T>
inline bool Queue<T>::IsFull(){return numOfItems == capacity-1;}

template <class T>
inline T& Queue<T>::Front()
{
    if (IsEmpty())
    {
        fprintf(stderr, "Queue is empty");
        exit(-1);
    }
    return queue[(front+1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear()
{
    if (IsEmpty())
    {
        fprintf(stderr, "Queue is empty");
        exit(-1);
    }
    return queue[rear];
}

// template <class T>
// void Queue<T>::Enqueue(const T&x)
// {
//     if (isFull())
//     {
//         fprintf(stderr, "Queue is full");
//         exit(-1);
//     }
//     rear = (rear + 1) % capacity;
//     queue[rear] = x;
//     numOfItems += 1;
// }

template <class T>
void Queue<T>::EnFront(const T&x)
{
    if (IsFull())
    {
        fprintf(stderr, "Queue is full");
        exit(-1);
    }
    queue[front] = x;
    front = (front - 1) % capacity;
    numOfItems += 1;
}

// The same as Enqueue
template <class T>
void Queue<T>::EnRear(const T&x)
{
    if (IsFull())
    {
        fprintf(stderr, "Queue is full");
        exit(-1);
    }
    rear = (rear + 1) % capacity;
    queue[rear] = x;
    numOfItems += 1;
}

// template <class T>
// void Queue<T>::Dequeue()
// {
//     if (IsEmpty())
//     {
//         fprintf(stderr, "Queue is empty. Cannot delete.\n");
//         exit(-1);
//     }
//     front = (front + 1) % capacity;
//     queue[front].~T();
//     numOfItems -= 1;
// }

// The same as Dequeue
template <class T>
void Queue<T>::DeFront()
{
    if (IsEmpty())
    {
        fprintf(stderr, "Queue is empty. Cannot delete.\n");
        exit(-1);
    }
    front = (front + 1) % capacity;
    queue[front].~T();
    numOfItems -= 1;
}

template <class T>
void Queue<T>::DeRear()
{
    if (IsEmpty())
    {
        fprintf(stderr, "Queue is empty. Cannot delete.\n");
        exit(-1);
    }
    queue[rear].~T();
    rear = (rear - 1) % capacity;
    numOfItems -= 1;
}

template <class T>
inline T& Queue<T>::ShowNumOfItems()
{
    printf("numOfItems = %d\n", numOfItems);
    return numOfItems;
}

template <class T>
void Queue<T>::ShowQueue()
{
    for (int i = 1; i <= numOfItems; ++i)
    {
        cout <<  "[" << queue[(front+i) % capacity] << "]";
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    int Capacity = 10;
    Queue<int> Qu(Capacity);
    Qu.EnRear(10);
    Qu.ShowNumOfItems();
    Qu.ShowQueue();
    Qu.EnFront(20);
    Qu.ShowNumOfItems();
    Qu.ShowQueue();
    Qu.EnRear(30);
    Qu.ShowNumOfItems();
    Qu.ShowQueue();
    Qu.DeFront();
    Qu.ShowNumOfItems();
    Qu.ShowQueue();
    Qu.DeRear();
    Qu.ShowNumOfItems();
    Qu.ShowQueue();

    return 0;
}
