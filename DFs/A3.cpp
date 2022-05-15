#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


void dfsiter(int v,vector<int> &check,vector<vector<int>> &g){
//cout<<v<<" ";
stack<int> s;
s.push(v);
//check[v]=1;
while(!s.empty()){
    int tp=s.top();
    s.pop();
    if(check[tp]==0){
        cout<<tp<<" ";
        check[tp]=1;
    }
    for(int i=g[tp].size()-1;i>=0;i--){
        if(check[g[tp][i]]==0){
 s.push(g[tp][i]);
        }
       
    }
}

}

void dfs(int v,vector<vector<int>> &g,vector<int> &check){
   // cout<<"kl ";
    if(check[v]==1){
        return ;
    }
    if(check[v]==0){
        check[v]=1;
        cout<<v<<" ";
        for(int i=0;i<g[v].size();i++){
            if(check[g[v][i]]==0){
                dfs(g[v][i],g,check);
            }
           
        }
    }
}



void bfs(int v,vector<vector<int>> &g,vector<int> &check){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int tp=q.front();
        q.pop();             
        if(check[tp]==0){ 
            cout<<tp<<" ";
            check[tp]=1;          
          for(int i=0;i<g[tp].size();i++){             
              if(check[g[tp][i]]==0){                   
 q.push(g[tp][i]);
 //cout<<g[v][i]<<" ";
              }            
          }
        }          
    }
}

void bfsrecur(queue<int> &q,vector<vector<int>> &g,vector<int> &check){
    if(q.empty()){
        return;
    }
    int  tp=q.front();
    q.pop();
    if(check[tp]==0){
        cout<<tp<<" ";
        check[tp]=1;
        for(int i=0;i<g[tp].size();i++){
            if(check[g[tp][i]]==0){
                q.push(g[tp][i]);
            }
        }
    }
    bfsrecur(q,g,check);
}

int main(){
   int v,e;
    cout<<"enter v & e ";
    cin>>v>>e;
    vector<vector<int>> g(v);
    for(int i=0;i<e;i++){
        int v1,v2;
        cout<<" enter v1 and v2 ";
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    vector<int>check(v,0);
    dfsiter(0,check,g);
   //bfs(0,g,check);
//    queue<int> q;
//    q.push(0);
//    bfsrecur(q,g,check);
}




//    1          0-> 1->2
//    /\         1-> 3
// 2            2-> 
// \    3       3->
//  4