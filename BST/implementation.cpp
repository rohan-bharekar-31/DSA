#include<iostream>
using namespace std;

class Node{
     public:
    
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertToBST(Node* &root,int d){
    if(root==NULL){
        Node* temp=new Node(d);
        root=temp;
    }
    else if(root->data > d){
        root->left=insertToBST(root->left,d);
    }
    else{
        root->right=insertToBST(root->right,d);       
    }
    return root;
}

void takeInput(Node* &root){
    int d;
    cin>>d;

    while(d!=-1){
        insertToBST(root,d);
        cin>>d;
    }
}

void print(Node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

void search(Node* root,int val){
    if(root==NULL){
        cout<<"Element Not Found"<<endl;
        return;
    }
    else if(root->data == val){
        cout<<"Element Found"<<endl;
        return;
    }
    else if(root->data > val){
        search(root->left,val);
    }
    else{
        search(root->right,val);
    }
}
// 10 8 21 7 27 5 4 3 -1
Node* maxNode(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
Node* deleteFromBST(Node* root,int val){
    //base case
    if(root==NULL){
        return NULL;
    }

    //element found
    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 chid
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            Node* maxNodeLeftTree=maxNode(root->left);
            int maxValLeftTree=maxNodeLeftTree->data;
            root->data=maxValLeftTree;

            root->left=deleteFromBST(root->left,maxValLeftTree);
            return root;

        }

    }
    
    if(root->data < val){
        root->right=deleteFromBST(root->right,val);
        return root;
    }
    else{
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    

}
int main(){
    Node* root=NULL;
    cout<<"Enter Data To be inserted : "<<endl;
    takeInput(root);
    cout<<endl;
    print(root);
    cout<<endl;
    int val;
    cout<<"Enter Element To search:";
    cin>>val;
    search(root,val);
    deleteFromBST(root,4);
    print(root);

}