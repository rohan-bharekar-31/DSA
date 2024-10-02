#include<iostream>
using namespace std;
bool binarySearch(int arr[],int n,int key,int s,int e){
    if(s>e){
        return false;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        cout<<"Index : "<<mid<<endl;
        return true;
    }
    else if(arr[mid]>key){
        e=mid-1;
        binarySearch(arr,n,key,s,e);
    }
    else{
        s=mid+1;
        binarySearch(arr,n,key,s,e);
    }  
}
int main(){
    int arr[5]={1,2,3,4,5};
    int size=5;
    int k=5;
    cout<<binarySearch(arr,size,k,0,size-1);
}