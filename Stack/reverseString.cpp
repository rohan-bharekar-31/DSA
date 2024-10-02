#include<iostream>
#include<stack>
using namespace std;

string reverse(string s){
    stack<char>str;
    string ans="";
    for(int i=0;i<s.size();i++){
        str.push(s[i]);
    }
    while(!str.empty()){
        ans.push_back(str.top());
        str.pop();
    }
    return ans;
}


int main(){
    string name="Rohan";
    cout<<reverse(name);
    
}