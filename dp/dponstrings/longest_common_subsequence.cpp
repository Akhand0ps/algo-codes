#include<bits/stdc++.h>

using namespace std;


/* 
Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.


Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.


Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0 

*/


int LCS(int ind1,int ind2,string s1,string s2){

    if(ind1 < 0 || ind2 < 0)return 0;


    //agr match kr rhe hai
    if(s1[ind1] == s2[ind2]){
       return  1 + LCS(ind1-1,ind2-1,s1,s2);
    }

    //agr match nhi kr rhe

    return 0 + max(LCS(ind1-1,ind2,s1,s2) , LCS(ind1,ind2-1,s1,s2));
}

int main(){

    string s1,s2;
    cout<<"Enter string 1: ";
    cin>>s1;
    cout<<"Enter string 2: ";
    cin>>s2;


    cout<<LCS(s1.size()-1,s2.size()-1,s1,s2);
}