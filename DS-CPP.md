# Fundamentals of Data Structures in C++ #

## Basic concepts ##
### Recursive ###
* Recursive to iterative by finite-state machine 

  [[C++]](https://github.com/alicia6174/Finite-state-machine)

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

## C++ build-in functions ##
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

### new / delete ###

* `new` is the same as `malloc`
* `delete` is the same as `free`

```cpp
int* a = new int;		//int* a = (int*) malloc(sizeof(int));
delete a;				//free(a);

int* b = new int(100);	//int* b = (int*) malloc(sizeof(int)*100);
delete [] b;			//free(b)
```

### Reference & ###
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

### String ###
```cpp
string s(n, c); 
s[i] = 'a';
s = "abcde";
s.length(); 
s.begin(); 
s.end();
s.push_back(c);
s.erase(start, length);
count(start, end, c);
s.find(s); // indexof type %lu
s.replace(start, length, s); 
string(c_str);	// C-string -> std:string
s.c_str();		// std:string -> C-string
strchr(s.c_str(), c); // pointer
strchr(s.c_str(), c)-s.c_str(); // index of type %lu
strcpy(s.c_str(), t.c_str());
strcat(s.c_str(), t.c_str());
strncat(s.c_str(), t.c_str(), n);
strcmp(s.c_str(), t.c_str()); // return the ASKII of s-t
strncmp(s.c_str(), t.c_str(), n); // return the ASKII of (s-t)(0:n-1)
```
[[C++]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX2-6/main.cpp)

### Set ###
```cpp
#include <set>
```

### Map ###
```cpp
#include <map> // map<int,int> & mp
```

### Queue ###
```cpp
#include <queue> // queue<int> q;
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
### Random ###
```cpp
// always the same result
#include <stdio.h>
#include <stdlib.h>

printf("%d ", rand()); 
```
```cpp
// different results
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// srand() can't be put in loop 
// o.w. the resulting numbers will be the same
srand( (unsigned)time(NULL) ); // take time series as random seeds 
printf("%d\n", rand()); 
```
```cpp
// 1~100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

srand( (unsigned)time(NULL) );
num = (int)( rand() / (RAND_MAX+1.0)*100.0 + 1);
printf("%d\n", num);
```

### Greedy principle ###
[[C++]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX2-2/main.cpp)

### C++ 11 ###
New C++ syntax has been invented since 2011, such as **lambda expression**.

Need to add `CFLAGS   = -g -Wall -std=c++11` in the Makefile while using it.

```cpp
// lambda expression in C++
for_each(arr, arr + size,
		[&s](float lambda) { s << "[" << lambda << "]";});
```
```python
# lambda expression in C++
map(arr, lambda x: x * 2)
```

[[C++]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX2-2/main.cpp)
[[Makefile]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX2-2/Makefile)

## Array ##

### Arrays ###
 ```cpp
 // ADT
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
 };
 ```
[[C++]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX2-2/main.cpp)

```cpp
// C++ build-in functions
list()
```
To see more, please refer to [here](http://pydoing.blogspot.tw/2011/02/python-list.html).

### Polynomials ###
 ```cpp
 // ADT
 class Term{
 private:
 		float cof;
 		int exp;
 };
 
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
 };
 
 // vector
 #include <vector>
 class Poly_vec{
 private:
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
 };
 ``` 
 [[C++]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX2-2-3-8/main.cpp)

### Sparse matrix ###
```cpp
// ADT
 class MatrixTerm{
 private:
  		int row, col, value;
 };
 
class SparseMatrix{
private:
		int rows, cols, terms, capacity; // terms=#(nonzero terms)
		MatrixTerm *smArray;			 // capacity=size of array
public:
		SparseMatrix(int r, int c, int t); // t = terms
		SparseMatrix Transpose();
		SparseMatrix FastTranspose();
		SparseMatrix Add(SparseMatrix b);
		SparseMatrix Multiply(SparseMatrix b);
};
```

### Multi-dimensional matrix ###

### String ###
```cpp
// ADT
class String
public:
		String(char *init, int m);
		bool operator==(String t);
		bool operator!(); // empty-> true
		int Length();
		String Concat(String t);
		String Substr(int i, int j);
		int Find(String pat); // Find 1st place of substring pat
		int FastFind(String pat); // Knuth-Morris-Pratt
}
```
```cpp
// C++ build-in functions
#include <stdio.h>
#include <string>
using namespace std;

string s(3, 'a');
//...see above
```
## Stack & Queue ##

## Linked list ##

## Tree ##

## Graph ##

## Hash ##

## Sorting ##

## References ##

[1] [Fundamentals Data Structures in C++ by Ellis Horowitz](https://www.amazon.com/Fundamentals-Data-Structures-Ellis-Horowitz/dp/0929306376) 

[2] [Proect Euler](https://projecteuler.net/)

[3] File: /Google Drive/Hsin_computer_course/C++.gdoc

[4] Folder: /Google Drive/Hsin_computer_course_in_coding


