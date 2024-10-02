// #include<iostream>
// using namespace std;
// #include<algorithm>
// void print_array(int arr[],int size){
//     cout<<"Printing an array :";
//     for(int i=0; i<size;i++){
//         cout<<arr[i]<<" ";
//     }
// }

// void update(int arr[],int n,int key){
//     for(int i=0;i<n;i++){
//         arr[i]=key;
//     }
    
// }
// void reverse(int arr[],int n){
//     int i=0;
//     int j=n-1;

//     while(i<j){
//         int temp=arr[i];
//         arr[i]=arr[j];
//         arr[j]=i;
//         i++;
//         j--;
//     }
// }
// int main(){
//     //declare
//     int arr[5]={1,3,7,12,0};
//     print_array(arr,5);
//     cout<<endl;
   
//     for(int i=0;i<5;i=i+2){
//         if(i+1<5){
//             swap(arr[i],arr[i+1]);
//         }
//     }

//     print_array(arr,5);

//     // // //accessing an element 
//     // // cout<<"Value at zero index :"<<arr[14]<<endl;
    

//     // //array size
//     // int size=sizeof(arr)/sizeof(int);

//     // //max min 
//     // // int maxi=INT16_MIN;
//     // // for(int i=0;i<5;i++){
//     // //     if(maxi<arr[i]){
//     // //         maxi=arr[i];
//     // //     }
//     // // }
//     // print_array(arr,5);
//     // reverse(arr,5);
//     // // update(arr,5,-1);
//     // print_array(arr,5);
//     // // cout<<endl;
//     // // cout<<"Maximun Value :"<<maxi<<endl;
    
//     // // cout<<"Test Case Pass"<<endl;


// }
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
 bool is_present(vector<int> temp,vector<vector<int>>ans){
        for(int i=0;i<ans.size();i++){
            if(ans[i]==temp){
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;j<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        if(!is_present(temp,ans)){
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        // if(ans.size()!=0){
        //     return ans;
        // }
        // else{
        //     return{};
        // }
        return ans;
    }
int main()
{   vector<vector<int>>ans;
    vector<int>x={-1,0,1,2,-1,-4};
    ans=threeSum(x);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<3;j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}