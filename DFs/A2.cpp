#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void DFS_rec(vector<int>v[],vector<int>&vis,int n){
   vector<int>a=v[n];
   cout<<n;
   for(int i=0;i<a.size();i++){
       if(vis[a[i]]==0){
           vis[a[i]]=1;
           DFS_rec(v,vis,a[i]);
       }
   }
}
void DFS(vector<int>v[],int n){
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            DFS_rec(v,vis,i);
        }
    }
}
void BFS_rec(vector<int>v[],vector<int>&vis,queue<int>&q){
  if(q.empty()){
      return;
  }
    int ele=q.front();
    q.pop();
    cout<<ele;
   vector<int>a=v[ele];

   for(int i=0;i<a.size();i++){
       if(vis[a[i]]==0){
           vis[a[i]]=1;
           q.push(a[i]);
           
       }
   }
   BFS_rec(v,vis,q);
}
void BFS(vector<int>v[],int n){
    queue<int>q;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            q.push(i);
            BFS_rec(v,vis,q);
           
        }
    }
     
}

int main(){
   int n,e;
   cout<<"Enter no. of vertices: "<<endl;
   cin>>n;
   cout<<"Enter no. of edges: "<<endl;
   cin>>e;
   vector<int>v[n+1];
   int e1,e2;
   for(int i=0;i<e;i++){
      cout<<"Enter source vertex: "<<endl;
      cin>>e1;
      cout<<"Enter Destination vertex: "<<endl;
      cin>>e2;
      v[e1].push_back(e2);
      v[e2].push_back(e1);
   }

   for(int i=1;i<=n;i++){
       cout<<i<<": "<<endl;
       for(int j=0;j<v[i].size();j++){
           cout<<v[i][j]<<"-->";
       }
       cout<<endl;
   }
   int c;
   while(true){
       cout<<"1.DFS traversel\n2.BFS Traversal\n3.Exit"<<endl;
    cin>>c;
    if(c==1){
         DFS(v,n);
    }
    else if(c==2){
        BFS(v,n);
    }
    else{
        exit(0);
    }
   }
  

   
    return 0;
}

/*

Enter no. of vertices: 
4
Enter no. of edges: 
3
Enter source vertex: 
1
Enter Destination vertex: 
2
Enter source vertex: 
1
Enter Destination vertex: 
3
Enter source vertex: 
2
Enter Destination vertex: 
4
1: 
2-->3-->
2:
1-->4-->
3:
1-->
4:
2-->
1.DFS traversel
2.BFS Traversal
3.Exit
1
12431.DFS traversel
2.BFS Traversal
3.Exit
2
12341.DFS traversel
2.BFS Traversal
3.Exit
3
*/