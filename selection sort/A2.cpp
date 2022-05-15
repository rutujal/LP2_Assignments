#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>&arr,int n){
    for(int i=0;i<n-1;i++){
        int minidx=i;
        for(int j=i;j<n;j++){
            if(arr[minidx]>arr[j]){
                minidx=j;
            }
        }
        int temp=arr[minidx];
        arr[minidx]=arr[i];
        arr[i]=temp;
    }
}


int main(){
    int c,a;
    int n;
    vector<int>v;
      while(1){
          cout<<"Enter your choice:\n1.Enter  elements of array\n2.Perform selection sort\n3.Exit\n";
          cin>>c;
          if(c==1){
              cout<<"enter size of array: "<<endl;
            cin>>n;
            cout<<"Enter elements of array: "<<endl;
            for(int i=0;i<n;i++){
               cin>>a;
                v.push_back(a);
            }
          }
          else if(c==2){
              selection_sort(v,n);
              for(int i=0;i<v.size();i++){
                  cout<<v[i]<<" ";
              }
          }
          else{
              break;
          }
      }
    return 0;
}

/*
Enter your choice:
1.Enter  elements of array
2.Perform selection sort
3.Exit
1
enter size of array: 
4
Enter elements of array: 
9
3
4
1
Enter your choice:
1.Enter  elements of array
2.Perform selection sort
3.Exit
2
1 3 4 9 Enter your choice:
1.Enter  elements of array
2.Perform selection sort
3.Exit
3
*/