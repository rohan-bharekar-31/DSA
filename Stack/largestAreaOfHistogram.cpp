#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallest(int arr[],int size){
    vector<int>ans(size);
    stack<int>str;
    str.push(-1);
    for(int i= size-1;i>=0;i--){
        int curr=arr[i];
        while(str.top()!=-1 && arr[str.top()]>=curr){
            str.pop();
        }
        ans[i]=str.top();
        str.push(i);
    }
    return ans;
}

vector<int> prevSmallest(int arr[],int size){
    vector<int>ans(size);
    stack<int>str;
    str.push(-1);
    for(int i=0;i<size;i++){
        int curr=arr[i];
        while(str.top()!=-1 && arr[str.top()]>=curr){
            str.pop();
        }
        ans[i]=str.top();
        str.push(i);
    }
    return ans;
}

int LargestArea(int arr[],int n){
    
    vector<int>prev(prevSmallest(arr,n));
    vector<int>next(nextSmallest(arr,n));
    int maxArea=0;
    for(int i=0;i<n;i++){
        
        int height=arr[i];
        
        if(next[i]==-1){
            next[i]=n;
        }
        int breadth=next[i]-prev[i]-1;
        int newArea=height*breadth;
        maxArea=max(maxArea,newArea);
    }
    return maxArea;
}
int main(){
    int arr[7]={2, 3, 1,3,4,5,2};
    cout<<LargestArea(arr,7);
}