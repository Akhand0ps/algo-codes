#include<bits/stdc++.h>
using namespace std;

// Permutation in String

vector<string>per;
void f(string s, int idx){
    if(idx == s.size()){
        // per.push_back(s);
        cout<<s<<" ";
        return;
    }

    for(int i=idx;i<s.size();i++){
        swap(s[i],s[idx]);
        f(s,idx+1);
        swap(s[i],s[idx]);
    }
}

int main(){
    string s = "abc";
    f(s,0);

    // for(auto &it:per){
    //     cout<<it<<" ";
    // }
}
