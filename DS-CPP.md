# Fundamentals of Data Structures in C++ #

## Basic concepts ##
### Recursive ###
* Recursive to iterative by finite-state machine 

  [[C++]](https://github.com/alicia6174/Finite-state-machine)

### Standard Template Library (STL) ###
* accumulate(start, end, initialValue)

  accumulate(start, end, initialValue, operator)

	```cpp
	#include <stdio.h>
	#include <stdlib.h>
	#include <iostream>
	#include <algorithm> // for accumulate
	using namespace std;
		
	int a[5] = {1, 5, 7, 2, 4};
	int iniVal = 0;
	int sum = accumulate(a, a+4, iniVal);
	int prd = accumulate(a, a+4, iniVal, multiplies<int>());
	```

* copy(start, end, to)

  next_permutation(start, end)
  
  [[C++]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX1-6-1/main.cpp)
  
* count(start, end, value)

  [[C++]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX1-6-4/main.cpp)

* fill(start, end, value)

  [[C++]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX1-6-5/main.cpp)

* Note: Most input variables of the above functions satisfy the form [start, end).

### Performance analysis / measurement ###
* Space complexity
* Time complexity

### Class ###
* A class includes -

	* class name
	* data member
	* member function
	* public / protected / private 
	
	```cpp
	#include <vector>
	template <class T>
	class Prime
	{
    	vector<char> primes_flag;
    	vector<T> primes_table;
    public:
       Prime(void);
       bool isPrime(T n);
       T getNthPrime(int idx);
	};

	template <class T>
	Prime<T>::Prime(void)
	{
    	primes_flag.push_back(0); // 0 is not prime
    	primes_flag.push_back(0); // 1 is not prime
    	primes_flag.push_back(1); // 2 is prime
    	primes_table.push_back(2);// 2 is the 1st prime
	}

	template <class T>
	bool Prime<T>::isPrime(T n)
	{
   		if (primes_flag.size() > n) return primes_flag[n];

    	while (primes_flag.size() <= n)
    	{
    		const T cur_p = primes_flag.size();
        	if ((cur_p & 1) == 0)
        	{
        		primes_flag.push_back(0);
        		continue;
        	}

        	primes_flag.push_back(1);
        	for (T i = 3; i*i <= cur_p; i+=2)
        	{
            	if ((cur_p % i) == 0)
            	{
             		primes_flag.back() = 0;
                	break;
            	}
        	}
    	}

    	return primes_flag[n];
	}

	template <class T>
	T Prime<T>::getNthPrime(int idx)
	{
    	if (primes_table.size() > idx) return primes_table[idx];

    	T cur_num = primes_table.back() + 1;
    	while (primes_table.size() <= idx)
    	{
        	if (isPrime(cur_num))
        	{
        		primes_table.push_back(cur_num);
        	}
			++cur_num;
    	}

    	return primes_table[idx];
	}  
	```

* C++ overload operator >> and << -

	```cpp
	friend ostream& operator<<(ostream &s, const Class &c);
	friend istream& operator>>(istream &s, Class &c);
	```
	[[C++]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX2-1-4/main.cpp)

### new / delete ###

* `new` is the same as `malloc`
* `delete` is the same as `free`

```c
int *ptr = NULL;
ptr = (int *)malloc(sizeof(int)*100);/
free(ptr);
```

```cpp
int *ptr = new int(100);
delete ptr;
```

### reference & ###

```cpp
int a = 10;
int &b = a;
b = 2;
printf("a = %d", a); // a = 2
```
 
### Vector ###

```cpp
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <vector> // for vector
using namespace std; 

// vector<template>
vector<int> V;   

// insert new items - V.push_back()
int x = 2
V.push_back(x);	

// array - V.size(), V.at(i), V[i]
for (int i = 0; i < V.size(); ++i)
{
	printf("%d", V.at(i));	// these two are almost the same
	printf("%d", V[i]);
}

// for loop - iterator, V.begin()<closed>, V.end()<open>, V.back()<closed>
vector<int>::iterator itr = V.begin();
while (itr != V.end()) {
	...
	++itr;
}
```

### Math ###

```cpp
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <math.h> // for math tools

int a = sqrt(2);
double b = sqrt(2);
float c = pow(1.5, 2);
```

## Array ##

* Arrays

 ```cpp
 class Array{
 int siz;
 float *arr;
 public:
 		Arr(int n, float v);
 		Arr(const Arr &a);
 		~Arr();
 		int getSize();
 		float& operator[](int i);
 		void operator=(const Arr &a);
 		friend ostream& operator<<(ostream &s, const Arr &a);
 		friend istream& operator>>(istream &s, Arr &a);
 }
 ```

* Polynomials

 ```cpp
 class Term{
 friend Poly;
 private:
 		float cof;
 		int exp;
 }
 
 // array
 class Poly{
 private:
 		Term *termArray;
 		int capacity; // size of termArray, usually larger than terms just in case
 		int terms;    // # of non-zero terms
 public:
 		Poly();
 		void addNewTerm(const int exp, const float cof);
 		Poly Add(Poly p);
 		Poly Sub(Poly p);
 		Poly Mult(Poly p);
 		float Eval(float x);
 		friend ostream& operator<<(ostream &s, const Poly &p);
 		friend istream& operator>>(istream &s, Poly &p);
 }
 
 // vector
 #include <vector>
 class Poly_vec{
 provate:
 		vector<Term> terms;
 		int num_terms;   // # of non-zero terms
 public:
 		Poly(); // 0x^0
 		Poly(float cof, int exp);
  		void addNewTerm(const int exp, const float cof);
  		Poly operator+(Poly &p);
 		Poly operator-(Poly &p); 
 		Poly operator*(Poly p);
 		float operator()(float x); // evaluation
 		friend ostream& operator<<(ostream &s, const Poly &p);
 		friend istream& operator>>(istream &s, Poly &p);
 }
 ``` 

## Stack & Queue ##

## Linked list ##

## Tree ##

## Graph ##

## References ##

[1] [Fundamentals Data Structures in C++ by Ellis Horowitz](https://www.amazon.com/Fundamentals-Data-Structures-Ellis-Horowitz/dp/0929306376) 

[2] [Proect Euler](https://projecteuler.net/)

[3] [Hsin](https://docs.google.com/document/d/1ghmOR_sdnTmfMJOzu6ohAzkowNOKHPnBuskVjlCDpJ8/edit)


