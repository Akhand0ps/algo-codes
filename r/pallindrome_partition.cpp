#include<bits/stdc++.h>
using namespace std;


bool pallindrome(int i,int j,string s){

    while(i<j){

        if(s[i] != s[j])return false;
        i++;
        j--;
    }
    return true;
}


void solve(int index,string& s, vector<string>&up,vector<vector<string>>&ans){

    if(index == s.size()){
        ans.push_back(up);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(pallindrome(index,i,s)){
            up.push_back(s.substr(index,i-index+1));
            solve(i+1,s,up,ans);
            up.pop_back();
        }
    }
}



int main(){

    string s= "aab";

    vector<vector<string>>ans;
    vector<string>up;

    solve(0,s,up,ans);

    for(auto it:ans){

        for(auto itt:it){
            cout<<itt<<" ";
        }
        cout<<"\n";
    }
    
   
}