#include<bits/stdc++.h>
using namespace std;
#define N 20


void printSolution(int board[N][N],int n){
    cout<<"Solution: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int board[N][N],int row,int col,int n){
    int i,j;
    for(i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]){
             return false;
        }
    }
    for(i=row,j=col;i<n && j>=0;i++,j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}


bool solveNQUtil(int board[N][N],int col,int n){
    if(col>=n){
        printSolution(board,n);
        return true;
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        if(isSafe(board,i,col,n)){
            board[i][col]=1;

            flag=solveNQUtil(board,col+1,n)||flag;
                
            board[i][col]=0;
        }
    }
    return false;
}


bool solveNQ(int n){
    int board[N][N]={0};

    if(solveNQUtil(board,0,n)==false){
        //cout<<"Solution does not exist"<<endl;
        return false;
    }
    printSolution(board,n);
    return true;
}

int main(){
    cout<<"Enter size of board: "<<endl;
    int n;
    cin>>n;
    
solveNQ(n);

    return 0;
}

/*
Enter size of board: 
4
Solution: 
0 0 1 0   
1 0 0 0   
0 0 0 1   
0 1 0 0   

Solution: 
0 1 0 0   
0 0 0 1   
1 0 0 0
0 0 1 0
*/