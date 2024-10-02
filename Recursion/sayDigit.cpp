#include<iostream>
using namespace std;

void sayDigit(int n){
    //base case
    if(n==0){
        return;
    }
    
    //rc
    sayDigit(n/10);
    
    //processing
    string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight"};
    int digit=n%10;
    cout<<arr[digit]<<" ";
}
int main(){
    int n;
    cin>>n;
    sayDigit(n);
}