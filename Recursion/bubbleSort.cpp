#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n ){
    cout<<"Array --> ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    if(n==0 || n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
}
int main(){
    int arr[5]={23,6,1,78,9};
    bubbleSort(arr,5);

}