#include<bits/stdc++.h>
using namespace std;


void per(string p,string up){

    if(up.size() == 0){
        // cout<<p<<" ";
        return;
    }

    char ch = up[0];

    for (int i = 0; i <=p.size(); i++)
    {
        /* code */
        string first = p.substr(0,i);
        string second = p.substr(i,p.length());
        // cout<<"first: "<<first<<"\n";
        // cout<<"second: "<<second<<"\n";
        per(first+ch+second,up.substr(1));
    }
    
}


vector<string>permutations(string p,string up){

    if(up.size() == 0){
        vector<string>nums;
        nums.push_back(p);
        return nums;
    }
    char ch  = up[0];
    vector<string>ans;

    for(int i=0;i<=p.size();i++){

        string first = p.substr(0,i);
        string second = p.substr(i,p.size());

        vector<string>temp = permutations(first+ch+second,up.substr(1));

        ans.insert(ans.end(),temp.begin(),temp.end());
    }
    return ans;
}

int countPermutations(string p,string up){

    if(up.size()==0){
        return 1;
    }
    int count = 0;
    char ch = up[0];

    for(int i=0;i<=p.size();i++){

        string first = p.substr(0,i);
        string second = p.substr(i,p.size());

        count = count + countPermutations(first+ch+second,up.substr(1));
    }
    return count;
}

int main(){

    string str = "abc";
    // per("",str);
    vector<string> ans = permutations("",str);
    for(string it:ans)cout<<it<<" ";

    cout<<"\n";

    cout<<"Total number of permuations: "<<countPermutations("",str);
}