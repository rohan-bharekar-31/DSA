#include<iostream>
using namespace std;

int main(){
    cout<<"Enter Row and col : ";
    int n,m;
    cin>>n>>m;
    
    int**arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[m];
    }

    //input
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    //output
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
    
    //delete
    for(int i=0;i<n;i++){
        delete[]arr[i];
    }
    delete []arr;
}