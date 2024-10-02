#include<iostream>
using namespace std;
#include<string>

char get_Max_Occ(string s){
    int count[26]={0};
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z'){
            count[s[i]-'A']++;
        }
        else{
            count[s[i]-'a']++;
        }
    }
    int maxi=0;
    int index=-1;
    for(int i=0;i<26;i++){
        if(maxi<count[i]){
            maxi=count[i];
            index=i;
        }
    }
    return index+'A';
}

int main(){
    string s;
    cin>>s;
    cout<<"The Maximum Ocurring Charcter is :"<<get_Max_Occ(s)<<endl;
}