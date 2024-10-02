#include<iostream>
using namespace std;

int get_root(int n){
    int s=0;
    int e=n;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        int square=mid*mid;
        if(square==n){
            return mid;
        }
        else if( square>n){
            e=mid-1;
        }
        else{
            ans=mid;
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

double more_Precision(int n,int Precision,int tempsol){
    double factor=1;
    double ans=tempsol;
    for(int i=0;i<Precision;i++){
        factor=factor/10;
        for(double j=ans;j*j<=n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int tempsol=get_root(n);

    cout<<"Square Root without Precision :"<<tempsol<<endl;

    cout<<"Square Root :"<<more_Precision(n,3,tempsol)<<endl;
}