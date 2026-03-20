#include<bits/stdc++.h>
using namespace std;


vector<string>ans;

vector<string> mapping = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};


void solve(string p,string up){

    if(up.size() == 0){
        ans.push_back(p);
        return;
    }
    int digit = up[0] -'0';


    for(int i=(digit-1)*3;i<digit*3;i++){

        char ch = 'a' + i;
        // cout<<ch<<" ";
        solve(p+ch,up.substr(1));
    }
}



void solve1(string p,string up){

    if(up.size() == 0){
        ans.push_back(p);
        return;
    }
    int digit = up[0] -'0';


    for(char ch:mapping[digit]){

        solve1(p+ch,up.substr(1));
    }
}

int main(){

    string s;
    cout<<"Enter string: ";
    cin>>s;

    solve1("",s);
    // cout<<"ans: ";
    for(auto it:ans)cout<<it<<" ";

}