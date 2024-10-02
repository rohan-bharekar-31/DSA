#include <iostream>
using namespace std;
#include <queue>
#include<stack>

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        node *left = NULL;
        node *right = NULL;
    }
};

node *create(node *root)
{
    cout << "Enter data :";
    int element;
    cin >> element;

    root = new node(element);

    if (element == -1)
    {
        return NULL;
    }

    cout << "Enter data for left root of " << root->data << endl;
    root->left = create(root->left);

    cout << "Enter data for right root of " << root->data << endl;
    root->right = create(root->right);

    return root;
}

void Level_Order_Traversal(node *root)
{
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    cout << "Level order Traversal :" << endl;
    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl; // purane wala level khatam

            if (!q.empty())
            { // agar child notes he present toh
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void Reverse_Level_Order_Traversal(node* root){
    queue<node*>q;
    stack<node*> str;
    
    q.push(root);
    q.push(NULL);
    
    
    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){

            str.push(NULL);
            if(!q.empty()){
                q.push(NULL);
                str.push(NULL);
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
    cout<<"Reverse Level Traversal"<<endl;
    while(!str.empty()){
        if(str.top()!=NULL){
            cout<<str.top()->data<<" ";
            str.pop();
            }
        else{
            cout<<endl;
            str.pop();
        }
    }
}

//inorder Recursive Traversal
void inorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//postorder Recursive Traversal
void postorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//preorder Recursive Traversal
void preorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//Pre-order iterative
void it_preorder(node*root){

    if(root==NULL){return;}
    stack <node*> str;
    str.push(root);

    while(!str.empty()){
        node* temp=str.top();
        str.pop();
        cout<<temp->data<<" ";
        if(temp->right){
            str.push(temp->right);
        }
        if(temp->left){
            str.push(temp->left);
        }
    }
}

//In-order iterative
void it_inorder(node*root){

    if(root==NULL){return;}
    stack <node*> str;
    node* temp=root;

    while(!str.empty() || temp!=NULL ){
       while (temp!=NULL){
            str.push(temp);
            temp=temp->left;
       }
       temp=str.top();
       str.pop();
       cout<<temp->data<<" ";
       temp=temp->right;
    }
}

void it_postorder(node* root){
    stack<node*> s1,s2;
    node* temp=root;
    s1.push(temp);

    while(!s1.empty()){
        temp=s1.top();
        s2.push(temp);
        s1.pop();

        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}
int main()
{

    node *root = NULL;

    // creating a Binary Tree
    root = create(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //  Level Order Traversal
    Level_Order_Traversal(root);

    // Reverse Level Order Traversal
    Reverse_Level_Order_Traversal(root);
    cout<<endl;

    //Inorder Traversal
    cout<<"Inorder Traversal :";
    inorder(root);
    cout<<endl;

    //Post-order Traversal
    cout<<"Post-order Traversal :";
    postorder(root);
    cout<<endl;

    //Pre-order Traversal
    cout<<"Pre-order Traversal :";
    preorder(root);
    cout<<endl;

    cout<<"Pre-order Traversal Iterative :";
    it_preorder(root);
    cout<<endl;

    cout<<"In-order Traversal Iterative :";
    it_inorder(root);
    cout<<endl;

    cout<<"Post-order Traversal Iterative :";
    it_postorder(root);
    cout<<endl;
}