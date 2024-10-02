#include<iostream>
using namespace std;

class stack{
    int top=-1;
    int* arr;
    int size;
    public:

    stack(int size){
        this->size=size;
        this->arr=new int[size];
    }

    int peek(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
        }else{
            return arr[top];
        }
    }
    bool empty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int val){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            arr[top]=val;
        }
    }
    void pop(){
        if(empty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            arr[top]=-1;
            top--;
        }
    }
};

int main(){
    stack s(3);
    cout<<s.empty()<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
}