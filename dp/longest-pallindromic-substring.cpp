#include <bits/stdc++.h>
using namespace std;


int expandFromCenter(const string&str,int left,int right){
    
    while(left >= 0 && right < str.size() && str[left] == str[right]){
        left--;
        right++;
    }
    
    return right - left-1;
    
}

int main() {
	// your code goes here

    // string str = "babad";
    string str;
    cout<<"Enter string: ";
    cin>>str;
    
    int start=0,end=0;
    
    for(int center=0;center<str.size();center++){
        
        int lenOdd = expandFromCenter(str,center,center);
        int lenEven = expandFromCenter(str,center,center+1);
        
        int maxlen = max(lenOdd,lenEven);
        
        
        if(maxlen>end-start){
            
            start = center - (maxlen-1)/2;
            end = center + maxlen/2;
        }
    }
    
    cout<<str.substr(start,end-start+1);
}
