#include<iostream>
#include<vector>
using namespace std;

void Eratosthenes(int n){
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=false;
    int count=0;
    for(int i=2;i<n;i++){
        if(prime[i]){
            count++;
            for(int j=2*i;j<n;j=j+i){
                prime[j]=false;
            }
        }
    }
    cout<<"Count : "<<count<<endl;
    cout<<"Prime Number : ";
    for(int i=0;i<n;i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }cout<<endl;
}

int main(){
    int k;
    cout<<"Enter Number : ";
    cin>>k;

    Eratosthenes(k);
}