#include<iostream>
using namespace std;
//solution 1
int power1(int a,int b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        return power1(a,b/2)*power1(a,b/2);
    }
    else{
        return power1(a,b/2)*power1(a,b/2)*a;
    }
}
//solution 2
int power2(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans=power2(a,b/2);
    if(b%2==0){
        return ans*ans;
    }
    else{
        return ans*ans*a;
    }
}
int main(){
    cout<<power1(0,1);
}