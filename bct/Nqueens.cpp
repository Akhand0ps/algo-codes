#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>>&board){

    for(auto it:board){

        for(auto row:it){

            if(row == true){
                cout<<"Q ";
            }else{
                cout<<"X ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool isSafe(vector<vector<bool>>&board,int row,int col){

    //check foor vertical row

    for(int i=0;i<row;i++){
        if(board[i][col]){
            return false;
        }
    }

    //check left

    int maxleft = min(row,col);

    //diagonal left;
    // -1 kr rhe hai kyuki diagonal me upar left jauga toh -1,-1 krna hoga;

    for(int i=1;i<=maxleft;i++){

        if(board[row-i][col-i]){
            return false;
        }
    }

    //diagonal right
    int n = board.size();
    int maxright = min(row,n-col-1);

    for(int i=1;i<=maxright;i++){
        if(board[row-i][col+i]){
            return false;
        }
    }


    return true;
    
}

int queens(vector<vector<bool>>&board,int row){

    if(row == board.size()){
        display(board);
        return 1;
    }

    int count = 0;

    for(int col = 0;col < board.size();col++){
        //if place is safe to put the queen
        if(isSafe(board,row,col)){
            board[row][col] = true;
            count +=  queens(board,row+1);
            board[row][col] = false;
        }
    }

    return count;
}

int main(){

    int n = 4;
    vector<vector<bool>>board(n,vector<bool>(n));

    cout<<queens(board,0);

}