#include<iostream>
using namespace std;
int HCF(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;
}
int main()
{
    cout<<"HCF : "<<HCF(72,24);
    return 0;
}