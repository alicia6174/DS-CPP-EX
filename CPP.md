# Fundamentals of Data Structures in C++ [[Ref.]](https://www.amazon.com/Fundamentals-Data-Structures-Ellis-Horowitz/dp/0929306376)#

## Basic concepts ##
### Recursive ###
* Recursive to iterative by finite-state machine 

  [[C++ Code]](https://github.com/alicia6174/Finite-state-machine)

### Standard Template Library (STL) ###
* accumulate(start, end, initialValue)

  accumulate(start, end, initialValue, operator)
		
		#include <stdio.h>
		#include <stdlib.h>
		#include <iostream>
		#include <algorithm>
		
		using namespace std;
		
		int a[5] = {1, 5, 7, 2, 4};
		int iniVal = 0;
		int sum = accumulate(a, a+4, iniVal);
		int prd = accumulate(a, a+4, iniVal, multiplies<int>());
		
* copy(start, end, to)

  next_permutation(start, end)
  
  [[C++ Code]](https://github.com/alicia6174/DS-CPP-EX/blob/master/EX1-6-1/main.cpp)
  
* count(start, end, value)

* fill(start, end, value)

* Note: Most input variables of the above functions satisfy the form [start, end).

