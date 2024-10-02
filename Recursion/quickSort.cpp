#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int count=0;
    int pivot=arr[s];
    for(int i=s+1 ; i<=e ; i++){
        if(arr[i]<=pivot){
            count++;
        }
    }

    int pivotIndex=s+count;


    //place pivot at right place
    swap(arr[s],arr[pivotIndex]);


    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while (arr[i]<pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if (i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[],int s,int e){
    //base case
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);
    //RC
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main(){
    int arr[5]={1,2,3,4,5};
    quickSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}