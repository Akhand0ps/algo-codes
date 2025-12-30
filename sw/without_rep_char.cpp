#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	string str = "geeksforgeeks";
	// cin>>str;
	
	int maxlen =0;

	
	for(int i=0;i<str.size();i++){
	    
	   vector<int>hash(256,0);
	   
	   for(int j=i;j<str.size();j++){
	       
	       if(hash[str[j]- 'a']== 1)break;
	       
	       maxlen = max(maxlen,j-i+1);
	       
	       hash[str[j] - 'a']= 1;
	   }
	}

    cout<<"by brute: "<<maxlen<<"\n";
    maxlen = 0;
    vector<int>hash(256,0); //use 26,0 if they are lowercase only.

    int l=0;
    int r=0;
    int n = str.length();

    while(r<n){

        while(hash[str[r] - 'a'] == 1){
            
            hash[str[l] - 'a'] = 0;

            // cout<<"l: "<<l<<" "<<"\n";
            l++;
        }

        hash[str[r]-'a'] = 1;
        maxlen = max(maxlen,r-l+1);
        r++;
    }

    cout<<"by better: "<<maxlen<<"\n";

    maxlen = 0;

    l=0;
    r=0;
    
    vector<int>Nhash(256,-1);
    while(r < n){

        if(Nhash[str[r]] != -1){


            //kya woh char l aur r ke beech me aara hai? ye iska break point hai.
            if(Nhash[str[r]] >= l){

                l = Nhash[str[r]] +1;

            }
        }


        maxlen = max(maxlen,r-l+1);
        Nhash[str[r]]  =r;
        r++;
    }

    cout<<"by optimal: "<<maxlen;

}
