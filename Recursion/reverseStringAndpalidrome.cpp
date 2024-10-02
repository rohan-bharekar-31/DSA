#include<iostream>
#include<string>
using namespace std;

void reverse(string &str,int i=0, int j=-1){
    if(i==0){
        j=str.length()-1;
    }
    cout<<"Call Received For : "<<str<<endl;
    //base case
    if(i>j){
        return;
    }
    swap(str[i],str[j]);
    i++;
    j--;
    reverse(str,i,j);
}
bool palidrone(string str,int i,int j){
    //base case
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        i++;
        j--;
        return palidrone(str,i,j);
    }
}
int main(){
    string str="CAC";
    reverse(str);
    cout<<str<<endl;
    cout<<"Is Palidrone --> "<<palidrone(str,0,str.length()-1);
}