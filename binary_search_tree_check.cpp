#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* insertBST(node* root,int val){
    if(root==NULL){
        return new node(val); 
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }else{
        root->right=insertBST(root->right,val);
    }
    return root;
}
void printpreorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
bool isBST(node* root,node* min,node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL&&root->data<=min->data){
        return false;
    }
    if(max!=NULL&&root->data>=max->data){
        return false;
    }
    bool leftvalid=isBST(root->left,min,root);
    bool rightvalid=isBST(root->right,root,max);
    return leftvalid and rightvalid;
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    if(isBST(root,NULL,NULL)){
        cout<<"valid BST"<<endl;
    }else{
        cout<<"invalid BST"<<endl;
    }
}