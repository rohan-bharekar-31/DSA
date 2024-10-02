#include<iostream>
using namespace std;

void subarray(int arr[],int n){
    //picking starting point
    for(int i=0;i<n;i++){
        //picking ending point
        for(int j=i;j<n;j++){
            //printing from start to end
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}
//brute force
int max_sum_subarray1(int arr[],int n){
    int maxi=INT32_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+arr[k];
            }
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}
//optimisation
int max_sum_subarray2(int arr[],int n){
    int maxi=INT32_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}
//KADANES'S ALGORITHM
int max_sum_subarray3(int arr[],int n){
    int maxi=INT32_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
    }
    if(maxi<0){
        return 0;
    }
    return maxi;
}
int main(){
    int arr[9]={1, 2 ,7 ,-4 ,3 ,2, -10 ,9 ,1};
    cout<<"The Subarrays are :"<<endl;
    subarray(arr,4);
    cout<<"Maximum Sub-Array Sum 1 :"<<max_sum_subarray1(arr,9)<<endl;
    cout<<"Maximum Sub-Array Sum 2 :"<<max_sum_subarray2(arr,9)<<endl;
    cout<<"Maximum Sub-Array Sum 2 :"<<max_sum_subarray3(arr,9)<<endl;
}