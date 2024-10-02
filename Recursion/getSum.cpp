#include<iostream>
using namespace std;

int getSum(int arr[],int n){
    //base case
    if(n==0){
        return 0;
    }
    //RC
    return arr[0]+getSum(arr+1,n-1);
}

int main(){
    int arr[5]={1,1,3,4,4};
    cout<<"Sum : "<<getSum(arr,5);
}