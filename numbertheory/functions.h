//
//  functions.h
//  numbertheory
//
//  Created by Blake Hull on 6/12/20.
//  Copyright © 2020 Blake Hull. All rights reserved.
//

#ifndef functions_h
#define functions_h
#include <ostream>
#include <list>
#include <string>
using namespace std;
std::list<int> factors = {};
  
int product(std::list<int> xList)
{
    unsigned product = 1;

    for (std::list<int>::iterator it=xList.begin(); it!=xList.end(); ++it) {
        product = product * (*it);
    }
    return product;
}

int modularPow(int b, int e, int m, int result = 1) {
  // seems to be working perfectly
  if(e == 1) {
      return result*b % m;
  }
  else {
      return modularPow(b, e - 1, m, result*b % m);
  }
}

int gcd(int a, int b) {
    if(b > a){
      return gcd(b, a);
    }
    if(a*b == 0){
        return std::max(a,b);
    }else{
        return gcd(b, a % b);
    }
}

std::list<int> pMinusOne(int n, int solution, int a = 2) {
    int worker = a;
    int iter = 1;
    int divisor = gcd(worker,n);
    while(divisor == 1){
        worker = modularPow(worker, iter, n);
        divisor = gcd(worker - 1, n);
        iter = iter + 1;
    }
    factors.push_back(divisor);
    if(product(factors) == solution){
        return factors;
    }else{
        return pMinusOne(n/divisor, solution);
    }
}

#endif /* functions_h */
