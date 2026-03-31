#include<bits/stdc++.h>
using namespace std;


/* 
Problem: Given an unlimited supply of coins of given denominations,
find the total number of ways to make a change of size n

NOTE: In this problem order does not matter.

1 3 5 10


n=4
first way -> use only 1 for fours times
second way-> use one time 3 and one time 1 
third way-> use one time 1 and one time 3 


Approch?

define the objective function -> 
f(i) = total no.of ways to make a change of size n.

Base cases:
f(0) = 1; how many ways to make a chnage of size 0 ? ans =1 take each coins zero times
f(1) = 1 (1cent)
f(2) = 1 ( (1)cent (1)cent);
f(3) = f(2) + f(0); (3-1) return 2 or {3} return 0;
f(3) = 2;

f(n) = f(n-1) + f(n-3); transition function 


*/


int main(){



}