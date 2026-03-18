#include<bits/stdc++.h>
using namespace std;


bool solve(int i,vector<vector<char>>&board,string word,int row,int col,string up,vector<vector<bool>>&b){

    if(i== word.size())return true;
    if(row < 0 || col >= board[0].size() || col < 0 || row>= board.size())return false;
    if(board[row][col] == word[i]){
        if(!b[row][col]){
            up += board[row][col];
        }
        else return false;
    };

    if(board[row][col] != word[i]){
       return false;
    };

    if(up == word)return true;
    b[row][col] = true;

    if(row < board.size()){
       if( solve(i+1,board,word,row-1,col,up,b)) return true;
    }
    if(row < board.size() && col < board[0].size()){
       if(solve(i+1,board,word,row,col+1,up,b)) return true;
    }

    if(row < board.size() && col < board[0].size()){
       if(solve(i+1,board,word,row+1,col,up,b))return true;
    }
    if(col < board[0].size()){
        if(solve(i+1,board,word,row,col-1,up,b))return true;
    }

    b[row][col] = false;


    return false;
}


bool exist(vector<vector<char>>& board, string word) {
        
    int n = board.size();
    int m = board[0].size();

    vector<vector<bool>>b(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(solve(0,board,word,i,j,"",b))return true;
        }
    }

    return false;
}


bool solve1(int i, vector<vector<char>>& board, string& word, int row,int col,vector<vector<bool>>& b) {

    if (i == word.size()) return true;
    if (row < 0 || col >= board[0].size() || col < 0 || row >= board.size()) return false;
    

    if (board[row][col] != word[i] || b[row][col]) {
        return false;
    };

    b[row][col] = true;

    if (solve1(i + 1, board, word, row - 1, col, b)) return true;

    if (solve1(i + 1, board, word, row, col + 1, b)) return true;

    if (solve1(i + 1, board, word, row + 1, col,b)) return true;

    if (solve1(i + 1, board, word, row, col - 1,b)) return true;
    

    b[row][col] = false;

    return false;
}

int main(){

   vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word;
    cout<<"enter word: ";
    cin>>word;
    cout<<"\n";

    if(exist(board,word))cout<<"yes";
    else cout<<"NO";
}