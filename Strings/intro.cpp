#include<iostream>
using namespace std;

int main(){
    string name;
    cout<<"Enter Name :";
    cin>>name;
    // int count=0;
    // for(int i=0;i<20;i++){
    //     if(name[i]=='\0'){
    //         break;
    //     }
    //     count++;
    // }
    name[4]='K';
    cout<<name<<endl;
    // cout<<"Length of String :"<<count;
    int pos=name.find("x");
    cout<<"Index of X is :"<<pos<<endl;

}