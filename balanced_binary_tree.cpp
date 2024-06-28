#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void printLevelOrder(node* root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* Node=q.front();
        q.pop();
        if(Node!=NULL){
            cout<<Node->data<<" ";
            if(Node->left){
                q.push(Node->left);
            }
            if(Node->right){
                q.push(Node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
//method 1---o(n^2)
bool isBalanced(node* root){
    if(root==NULL) return true;
    if(isBalanced(root->right)==false){
        return false;
    }
    if(isBalanced(root->left)==false){
        return false;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)<=1) return true;
    else return false;
}
//method 2---o(n)
bool isBalanced2(node* root,int* height){
    if(root==NULL){
        return true;
    }
    int lh=0,rh=0;
    if(isBalanced2(root->left,&lh)==false){
        return false;
    }
    if(isBalanced2(root->right,&rh)==false){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    if(isBalanced(root)) cout<<"balanced"<<endl;
    else cout<<"not balenced"<<endl;
    int height=0;
    if(isBalanced2(root,&height)) cout<<"balanced2"<<endl;
    else cout<<"not balenced2"<<endl;
}