#include<iostream>
using namespace std;

class node{
public:    
    int val;
    node* left;
    node* right;
    
    node(int d){
        this->val=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insert_node(node*& root,int data){
    //base case
    if(root==NULL){
        root=new node(data);
        return root;
    }

    if(root->val>data){
        root->left=insert_node(root->left,data);
    }
    else{
        root->right=insert_node(root->right,data);
    }
    return root;
    
}
void Input_Val(node*& root){
    cout<<"Enter Data :";
    int data;
    cin>>data;
    
    while(data!=-1){
        insert_node(root,data);
        cin>>data;
    }
}
//preorder Recursive Traversal
void preorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void search(int x,node* root){
    node*temp=root;
    while(temp!=NULL){
        if(temp->val==x){
            cout<<"Element Found "<<endl;
            return;
        }
        else if(temp->val>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    cout<<"Not Found"<<endl;
}

//minimum value
node* mini(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

//maximum Value
node* maxi(node* root){
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
//delete
node* To_delete_BST(node* root ,int d){
    //base case 1
    if(root==NULL){
        return NULL;
    }
    //base case 2
    if(root->val ==d){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //only left child
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        //only right child
        if(root->right!=NULL && root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->right!=NULL && root->left!=NULL){
            int mini_val=mini(root->right)->val;
            root->val=mini_val;
            root->right=To_delete_BST(root->right,mini_val);
            return root;
        }
    }
    else if(root->val>d){
        //left part me dhundo 
        root->left=To_delete_BST(root->left,d);
        return root;
    }
    else {
        //right part me dundho
        root->right=To_delete_BST(root->right,d);
    }
}
int main(){
    node*root=NULL;
    
    Input_Val(root);
    // 10 8 21 7 27 5 4 3 -1

    cout<<"Pre Order Traversal :";
    preorder(root);

    cout<<endl;
    search(42,root);

    cout<<"Maximum Value :"<<maxi(root)->val<<" , Minimum Value :"<<mini(root)->val<<endl;
}