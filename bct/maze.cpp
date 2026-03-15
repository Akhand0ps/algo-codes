#include<bits/stdc++.h>
using namespace std;


void paths(vector<vector<int>>&matrix,int i,int j,int n,int m,int &cnt){

    if(i>=n || j >=m)return;

    if(i==n-1 && j==m-1){
        cnt++;
    }
    paths(matrix,i+1,j,n,m,cnt);
    paths(matrix,i,j+1,n,m,cnt);
}


int countways(int row,int col){

    if(row == 1 || col==1){
        return 1;
    }
    int down = countways(row-1,col);
    int right = countways(row,col-1);

    return down + right;
}


void path(string p,int row,int col){
    if(row == 1 && col == 1){
        cout<<p<<"\n";
        return;
    }

    if(row > 1){
        path(p+"D",row-1,col);
    }

    if(col > 1){
        path(p+"R",row,col-1);
    }
}


void pathRestriction(string p,vector<vector<bool>>&maze ,int row,int col){
    if(row == maze.size()-1 && col == maze[0].size()-1){
        cout<<p<<" ";
        return;
    }

    //obstacle

    if(!maze[row][col]){
        return;
    }
    if(row < maze.size()-1){
        pathRestriction(p+"D",maze,row+1,col);
    }

    if(col < maze[0].size()-1){
       pathRestriction(p+"R",maze,row,col+1);
    }
    
}


void allPath(string p,vector<vector<bool>>&maze ,int row,int col){
    if(row == maze.size()-1 && col == maze[0].size()-1){
        cout<<p<<"\n";
        return;
    }

    //obstacle

    if(!maze[row][col]){
        return;
    }

    // i am considering the block in my path
    maze[row][col] = false;

    if(row < maze.size()-1){
        allPath(p+"D",maze,row+1,col);
    }

    if(col < maze[0].size()-1){
       allPath(p+"R",maze,row,col+1);
    }

    if(row > 0){
        allPath(p+"U",maze,row-1,col);
    }
    if(col >0){
        allPath(p+"L",maze,row,col-1);
    }

    //this line is where the function willl over
    //so before the function gets removed from stack,also remove the changes that were made by that function.


    maze[row][col] = true;
}


void allPathPrint(string p,vector<vector<bool>>&maze ,int row,int col,vector<vector<int>>&path,int step){
    if(row == maze.size()-1 && col == maze[0].size()-1){

        path[row][col] = step;
        for(auto row:path){
            for(auto col: row){
                cout<<to_string(col)<<" ";
            }
            cout<<"\n";
        }
        cout<<p;
        cout<<"\n";
        return;
    }

    //obstacle

    if(!maze[row][col]){
        return;
    }
    

    // i am considering the block in my path
    maze[row][col] = false;
    path[row][col] = step; //adding the step in the path

    if(row < maze.size()-1){
        allPathPrint(p+"D",maze,row+1,col,path,step+1);
    }

    if(col < maze[0].size()-1){
      allPathPrint(p+"R",maze,row,col+1,path,step+1);
    }

    if(row > 0){
      allPathPrint(p+"U",maze,row-1,col,path,step+1);
    }
    if(col >0){
        allPathPrint(p+"L",maze,row,col-1,path,step+1);
    }

    //this line is where the function willl over
    //so before the function gets removed from stack,also remove the changes that were made by that function.


    maze[row][col] = true;
    path[row][col] = 0; //undoing the past path taken by different function call;
}


vector<string> pathList(string p,int row,int col){
    if(row == 1 && col == 1){
        
        vector<string>str;
        str.push_back(p);
        return str;
    } 
    vector<string>ans;

    if(row > 1){
        vector<string>temp = pathList(p+"V",row-1,col);
        ans.insert(ans.end(),temp.begin(),temp.end());
    }

    if(row > 1 && col > 1){
        vector<string>temp = pathList(p+"D",row-1,col-1);
        ans.insert(ans.end(),temp.begin(),temp.end());
    }

    if(col > 1){
         vector<string>temp =pathList(p+"H",row,col-1);
         ans.insert(ans.end(),temp.begin(),temp.end());
    }

    return ans;
}




int main(){

    vector<vector<int>>matrixx = {
        {1,0,0},
        {0,0,0,0},
        {0,0,0},
        {0,0,1},
    };

    vector<vector<int>>matrix = {
        {1,0,0},
        {0,0,0},
        {0,0,1},
    };

    // for(auto &it:matrix){
    //     for(auto &itt:it){
    //         cout<<itt<<" ";
    //     }
    //     cout<<"\n";
    // }
    int n = matrix.size();
    int m = matrix[0].size();
    // cout<<"no. of rows: "<<n<<"\n";
    // cout<<"no. of columns: "<<matrix[0].size()<<"\n";

    // cout<<matrix[0];

    // cout<<"\n";
    // int cnt =0;
    // paths(matrix,0,0,n,m,cnt);

    // cout<<"no of paths: "<<cnt;

    // cout<<"no. of ways: "<<countways(n,m)<<"\n";

    // path("",n,m);
    // cout<<"\n";

    // vector<string>ans = pathList("",n,m);
    // for(string str:ans)cout<<str<<" ";
    cout<<"\n";



    vector<vector<bool>>maze = {
        {true,true,true},
       {true,true,true},
        {true,true,true},
    };


    // pathRestriction("",maze,0,0);
    // allPath("",maze,0,0);

    vector<vector<int>>path(maze.size(),vector<int>(maze[0].size()));

    allPathPrint("",maze,0,0,path,1);
   
}