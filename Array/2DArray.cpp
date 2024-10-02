#include<iostream>
#include<vector>
using namespace std;

void Row_Wise_Sum(int arr[][4],int row,int col){
    
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum=sum+arr[i][j];
        }
        cout<<"Sum "<<i+1<<" Row -> "<<sum<<endl;
    }
}
void Col_Wise_Sum(int arr[][4],int row,int col){
    
    for(int i=0;i<col;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum=sum+arr[j][i];
        }
        cout<<"Sum "<<i+1<<" Col -> "<<sum<<endl;
    }
}
void largestRowSum(int arr[][4],int row,int col){
    int ans=INT32_MIN;

    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum=sum+arr[i][j];
        }
        if(sum>ans){
            ans=sum;
        };
    }
    cout<<"Largest Row Sum is "<<ans<<endl;
}
bool isPresent(int arr[][4],int target,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    //Create 2D Array
    int arr[3][4]={0,1,2,3,100,5,6,7,8,9,10,11};
    // Taking Input ->Row Wise
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    //Coloumn Wise Input
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<3;j++){
    //         cin>>arr[j][i];
    //     }
    // }
    //Printing 2D Array
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int target;
    cout<<"Enter Target Element : ";
    cin>>target;
    if(isPresent(arr,target,3,4)){
        cout<<"Target Element Found "<<endl;
    }
    else{
        cout<<"Target Element Not Found "<<endl;
    }

    Row_Wise_Sum(arr,3,4);
    Col_Wise_Sum(arr,3,4);
    largestRowSum(arr,3,4);

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

        int startRow=0;
        int endRow=2;
        int startCol=0;
        int endCol=3;
        vector<int>ans;

        while(startRow<=endRow && startCol<=endCol){
            for(int col = startCol ; col <= endCol && startRow<=endRow && startCol<=endCol  ; col++){
                ans.push_back(arr[startRow][col]);
            }
            startRow++;
            for(int row = startRow  ; row <= endRow && startRow<=endRow && startCol<=endCol  ; row++){
                ans.push_back(arr[row][endCol]);
            }
            endCol--;
            for(int col = endCol ; col >= startCol && startRow<=endRow && startCol<=endCol  ; col--){
                ans.push_back(arr[endRow][col]);
            }
            endRow--;
            for(int row = endRow  ; row >= startRow && startRow<=endRow && startCol<=endCol  ; row--){
                ans.push_back(arr[row][startCol]);
            }
            startCol++;
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }

}