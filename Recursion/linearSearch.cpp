#include<iostream>
using namespace std;

bool search(int arr[],int size,int key){
    //base case
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    else{
        bool remainingPart=search(arr+1,size-1,key);
        return remainingPart;
    }
}
int main(){
    int arr[5]={1,4,3,11,7};
    int n;
    cin>>n;
    if(search(arr,5,n)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}