#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* createBinaryTree(node* root){

    cout<<"Enter Data : ";
    int data;
    cin>>data;

    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter Data left of "<<root->data<<endl;
    root->left=createBinaryTree(root->left);

    cout<<"Enter Data right of "<<root->data<<endl;
    root->right=createBinaryTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void reverseLevelOrderTraversal(node* root){
    queue<node*>q;
    stack<node*>str;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            str.push(NULL);
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            str.push(temp);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

    while(!str.empty()){
        node* temp=str.top();
        str.pop();
        if(temp==NULL){
            cout<<endl;
        }
        else{
            cout<<temp->data<<" ";
        }
    }

}
void buildFromLevelOrder(node* &root){
    cout<<"Enter Data :";
    int data;
    cin>>data;
    root=new node(data);
    queue<node*>q;
    q.push(root);
    
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"Enter Data for left of "<<temp->data<<" : ";
        cin>>data;
        if(data==-1){
            temp->left=NULL;
        }
        else{
            temp->left=new node(data);
            q.push(temp->left);
        }
        cout<<"Enter Data for Right of "<<temp->data<<" : ";
        cin>>data;
        if(data==-1){
            temp->right=NULL;
        }
        else{
            temp->right=new node(data);
            q.push(temp->right);
        }
    }

}
void preoder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preoder(root->left);
    preoder(root->right);
}

int main(){
    node* root=NULL;
    root=createBinaryTree(root);    // 1 3 7 -1 -1 11 -1 -1 5 17  -1 -1 -1
    cout<<" Reverse Level Order : "<<endl;
    reverseLevelOrderTraversal(root);
    // cout<<"Preorder : ";
    // preoder(root);
    // cout<<endl;
    // cout<<"Level Order : ";
    // levelOrderTraversal(root);

    // buildFromLevelOrder(root);
    // cout<<"Preorder : ";
    // preoder(root);
    // cout<<endl;
    
}