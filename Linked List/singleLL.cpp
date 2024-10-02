#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;
    //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory Freed for node : "<<value<<endl;
    }
};

void InsertAtHead(node*& head,node*& tail,int data){

    node* temp=new node(data);
    //case 1: empty linked list
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    //case 2 
    temp->next=head;
    head=temp;

}

void InsertAtTail(node*&head,node*&tail,int data){

    node* temp=new node(data);
    //case 1 : empty Linked List
    if(head==NULL){
        tail=temp;
        head=temp;
        return;
    }
    //else
    tail->next=temp;
    tail=tail->next;
}

void InsertAtPosition(node*& head,node*& tail,int data,int position){
    
    //inserting at start
    if(position==1){
        InsertAtHead(head,tail,data);
        return;
    }

    //count = 1 ; because initially we start from head  
    int count=1;
    node* temp=head;

    while(count!=position-1){
        temp=temp->next;
        count++;
    }

    //inserting at last position
    if(temp->next==NULL){
        InsertAtTail(head,tail,data);
        return;
    }

    node* nodeToInsert=new node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

void del(node*& head ,node*& tail,int position){
    
    //case 1 deleting for first position
    if(position==1){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //case 2 deletiong any middle for last node
        int count=1;
        node* curr=head;
        node* prev=NULL;

        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }

        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(node*& head){
    
    node* temp=head;
    cout<<"Linked List  : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    node* head=NULL;
    node* tail=NULL;
    
    InsertAtPosition(head,tail,10,1);
    InsertAtPosition(head,tail,0,1);
    InsertAtPosition(head,tail,20,2);
    InsertAtPosition(head,tail,15,2);
    InsertAtPosition(head,tail,-1,5);
    InsertAtTail(head,tail,-2);

    cout<<"Head "<<head->data<<" "<<tail->data<<" "<<endl<<endl;
    print(head);

    del(head,tail,6);

    print(head);
    cout<<endl<<endl<<"Head "<<head->data<<" "<<tail->data<<" "<<endl<<endl;
    

}