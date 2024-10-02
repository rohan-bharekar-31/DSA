#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n<=1){
        return false;
    }
    else{
        for(int i=2;i<n;i++){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int k;
    cout<<"Enter Number : ";
    cin>>k;

    if(isPrime(k)){
        cout<<"Prime"<<endl;
    }
    else{
        cout<<"Not Prime "<<endl;
    }
}