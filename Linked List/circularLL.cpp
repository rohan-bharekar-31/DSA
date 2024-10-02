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

void print(node*& tail){
    if(tail==NULL){
        cout<<"Empty CLL"<<endl;
        return;
    }
    node* temp=tail;
    cout<<"CLL : ";
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    } while (temp!=tail);
    cout<<endl;
    
}
void insertAtValue(node*& tail,int value,int data){
    //case 1 : Empty CLL
    if(tail==NULL){
        node* temp=new node(data);
        tail=temp;
        temp->next=temp;
        return;
    }
    //ase 2 : Non Empty CLL
    node* curr=tail;
    while(curr->data!=value){
        curr=curr->next;
    }
    node* nodeToInsert=new node(data);

    nodeToInsert->next=curr->next;
    curr->next=nodeToInsert;
}
void del(node*& tail,int value){
    if(tail==NULL){
        cout<<"Empty CLL"<<endl;
        return;
    }
    else{
        node* prev=tail;
        node* curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //single element
        if(curr==prev){
            tail=NULL;
        }
        //2> elements
        else if(curr==tail){ 
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}


int main(){
    node*tail=NULL;
    insertAtValue(tail,1,1);
    // insertAtValue(tail,1,2);
    // insertAtValue(tail,1,3);
    // insertAtValue(tail,1,4);
    // insertAtValue(tail,3,100);
    print(tail);
    // cout<<tail->data<<endl;
    del(tail,1);
    print(tail);

}