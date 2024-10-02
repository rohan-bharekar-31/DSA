#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>arr,vector<vector<int>> &ans,vector<int>output,int index){
    if(index>=arr.size()){
        ans.push_back(output);
        return;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[i],arr[index]);
        output.push_back(arr[index]);
        solve(arr,ans,output,index+1);
        swap(arr[i],arr[index]);
        output.pop_back();
    }  
}

vector<vector<int>> permutation(vector<int>arr){
    vector<vector<int>>ans;
    vector<int>output;
    int index=0;
    solve(arr,ans,output,index);
    return ans;
}
int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>>perm= permutation(arr);

    for(int i=0;i<perm.size();i++){
        cout<<"( ";
        for(int j=0;j<perm[0].size();j++){
            cout<<perm[i][j]<<" ";
        }cout<<") "<<endl;
    }
}