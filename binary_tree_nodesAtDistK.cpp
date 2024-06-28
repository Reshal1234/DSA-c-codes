//102
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
void printsubtreeNodes(node* root,int k){
    if(root==NULL||k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printsubtreeNodes(root->left,k-1);
    printsubtreeNodes(root->right,k-1);
}
int printNodesAtk(node* root,node *target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printsubtreeNodes(root,k);
        return 0;
    }
    int dl=printNodesAtk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }else{
            printsubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr=printNodesAtk(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }else{
            printsubtreeNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}
int main(){
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    cout<<printNodesAtk(root,root->left,1)<<endl;
}