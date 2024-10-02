#include<iostream>
using namespace std;

void update(int*& p){
    p=p+1;
}
int main(){
//     int num=0;
//     //int *ptr;//BAD PRACTISE
//     int* ptr = &num;
//     cout<<"Addresss : "<<ptr<<endl;
//     cout<<"Value : "<<*ptr<<endl;
//     //size of pointer 8 byte 
//     cout<<"Size of Pointer : "<<sizeof(ptr)<<endl;
//    int arr[10];
//     cout<<"Address of first element  : "<<arr<<endl;
//     cout<<"Address of first element  : "<<&arr[0]<<endl;
//     return 0; 
    // int arr[3]={1,2,3};

    // cout<<"arr ->     "<<arr<<endl;
    // cout<<" &a ->     "<<&arr<<endl;
    // cout<<"&arr[0] -> "<<&arr[0]<<endl;

    // cout<<"sizeof(arr ->)     "<<sizeof(arr)<<endl;
    // cout<<"sizeof( &a ->)     "<<sizeof(&arr)<<endl;
    // cout<<"sizeof(&arr[0] ->) "<<sizeof(&arr[0])<<endl;

    //Character Arrays 
    // int arr[3]={0};
    // char ch[3]="bc";
    // cout<<"arr -> "<<arr<<endl;
    // cout<<"ch  -> "<<ch<<endl;
    // cout<<ch[3]<<endl;

    // // char* ptr=&ch[0];
    // // cout<<ptr<<endl;
    // char a='z';
    // char* ptr=&a;
    // cout<<ptr<<endl;


    //DOUBLE POINTER
    int i=5;
    int* ptr=&i;
    int** ptr2=&ptr;

    cout<<"Address of i "<<endl;
    cout<<&i<<endl;
    cout<<ptr<<endl;
    cout<<*ptr2<<endl;

    cout<<endl<<"Cobtent of i "<<endl;
    cout<<i<<endl;
    cout<<*ptr<<endl;
    cout<<**ptr2<<endl;

    cout<<endl<<"Address of ptr "<<endl;
    cout<<&ptr<<endl;
    cout<<ptr2<<endl;

    int k=10;
    int *p=&k;
    (*p)++;
   
    (*r)++;
    cout<<k;
}