#include<bits/stdc++.h>

using namespace std;

string skip(string str,string &ans,int i){

    if(i==str.size()){
        return ans;
    }
    if(str[i] != 'a') ans += str[i];
    return skip(str,ans,i+1);
}

string skipbybody(string str,int i){

    if(i==str.size()) return str;
}


int main(){

    string str = "baccd";
    string ans = "";
    cout<<skip(str,ans,0);
}