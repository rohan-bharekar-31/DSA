#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
void print(node*& head){
    node* temp=head;
    cout<<"DLL : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
int getLength(node*& head){
    node* temp=head;
    int len=0;
    
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtHead(node*& head,int data){

    node* temp=new node(data);

    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertAtTail(node*& tail,int data){

    node* temp=new node(data);

    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtPosition(node*& head,node*& tail,int position,int data){
    
    if(position==1){
        insertAtHead(head,data);
        return;
    }
    else{
        node*temp=head;
        int count=1;

        while(count<position-1){
            temp=temp->next;
            count++;
        }

        if(temp->next==NULL){
            insertAtTail(tail,data); 
            return;   
        }

        node* nodeToInsert=new node(data);
        
        nodeToInsert->prev=temp;
        nodeToInsert->next=temp->next;
        temp->next->prev=nodeToInsert;
        temp->next=nodeToInsert;
        
    }
} 
void del(node*& head ,node*& tail,int position){
    
    //case 1 deleting for first position
    if(position==1){
        node* temp=head;
        
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;

        delete temp;
    }
    else{
        //case 2 deletiong any middle for last node
        int count=1;
        node* curr=head;
        node* prevNode=NULL;

        while(count<position){
            prevNode=curr;
            curr=curr->next;
            count++;
        }

        curr->prev=NULL;
        prevNode->next=curr->next;
        if(curr->next!=NULL){
            curr->next->prev=prevNode;
        }
        curr->next=NULL;
        delete curr;
    }
} 
void printReverse(node*& tail){
    node* temp=tail;
    cout<<"Reverse DLL : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }cout<<endl;
}

void reverse(node*& head,node*& tail){
    if(head==NULL || head->next==NULL){
       return;
    }
    tail=head;
    node* curr=head;
    node* prev= NULL;
    node* forward=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        curr->prev=forward;
        prev=curr;
        curr=forward;
    }
    head=prev;
}
int main(){
    node* node1=new node(10);

    node* head=node1;
    node* tail=node1;

    insertAtHead(head,11);
    insertAtTail(tail,34);
    insertAtTail(tail,67);
    insertAtPosition(head,tail,3,-100);
    print(head);
    reverse(head,tail);
    print(head);
    printReverse(tail);
}
