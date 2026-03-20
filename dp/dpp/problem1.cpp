#include<bits/stdc++.h>
using namespace std;

/* 

    Problem:
    Find the sum of first N numbers.

    Objective function:
    f(i) is the sum of the first i elements

    Recururence relation:

    f(n) = f(n-1) + n

*/

// int n = 

int nSum(int n){

    vector<int>dp(n+1);
    dp[0] = 0;
    
    for(int i=1;i<=n;i++){

        dp[i] = dp[i-1] +i;
    }
    return dp[n]; 
}


void testcases(){
    // Test case 1: n = 5, expected = 15 (1+2+3+4+5)
    assert(nSum(5) == 15);
    cout << "Test 1 passed: nSum(5) = " << nSum(5) << " (expected: 15)" << endl;
    
    // Test case 2: n = 10, expected = 55 (1+2+...+10)
    assert(nSum(10) == 55);
    cout << "Test 2 passed: nSum(10) = " << nSum(10) << " (expected: 55)" << endl;
    
    // Test case 3: n = 1, expected = 1
    assert(nSum(1) == 1);
    cout << "Test 3 passed: nSum(1) = " << nSum(1) << " (expected: 1)" << endl;
    
    // Test case 4: n = 0, expected = 0
    assert(nSum(0) == 0);
    cout << "Test 4 passed: nSum(0) = " << nSum(0) << " (expected: 0)" << endl;
    
    cout << "All tests passed!" << endl;
}

int main(){
    testcases();
    return 0;
}