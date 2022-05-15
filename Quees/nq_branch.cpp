#include<iostream>
#include<bits/stdc++.h>
#define N 8
using namespace std;


bool solveNQUtil(int board[N][N],int col,int backSlashCode[N][N],int slashCode[N][N],bool rowLookup[],bool slashCodeLookup[],bool slashCodeLookup){
    if(col>=N){
        return true;
    }
    for(int i=0;i<N;i++){
        
    }

}

bool solveNQ(){
    int board[N][N]={0};

    int backSlashCode[N][N];
    int slashCode[N][N];

    bool rowLookup[N]={false};
    bool slashCodeLookup[N]={false};
    bool backSlashCodeLookup[N]={false};

    for(int r=0;i<N;r++){
        for(int c=0;c<N;c++){
            slashCode[r][c]=r+c;
            backSlashCode[r][c]=r-c+7;
        }
    }

}


int main(){
    solveNQ()
    return 0;
}