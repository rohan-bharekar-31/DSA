#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next=NULL;
    node(int data){
        this->data=data;
    }
};

void insertAtTail(node* &head,node* &tail,int val){
    node* temp=new node(val);
    if(tail==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}
class stack{
    node* tail=NULL;
    node* head=NULL;
    public:

    bool isEmpty(){
        if(tail==NULL){
            return 1;
        }
        else{
            return false;
        }
    }
    
    void push(int val){
        insertAtTail(head,tail,val);
    }

    int peek(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        else{
            return tail->data;
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            if(head->next==NULL){
                node* todelete=head;
                head=NULL;
                tail=NULL;
                delete todelete;
            }
            else{
                node*prev=NULL;
                node* curr=head;
                while(curr!=tail){
                    prev=curr;
                    curr=curr->next;
                }
                cout<<"Popped Element : "<<curr->data<<endl;
                tail=prev;
                tail->next=NULL;
                delete curr;
            }
        }
    }
};
int main(){
    stack s;
    cout<<s.isEmpty()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.push(1);
    s.push(10);
    s.push(100);
    s.push(50);
    s.pop();
    cout<<s.isEmpty()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    

}