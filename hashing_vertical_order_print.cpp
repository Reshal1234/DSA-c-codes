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
void getVerticalOrder(node* root,int hdis,map<int,vector<int>>&m){
    if(root==NULL){
        return;
    }
    m[hdis].push_back(root->data);
    getVerticalOrder(root->left,hdis-1,m);
    getVerticalOrder(root->right,hdis+1,m);

}
int main(){
    struct node* root=new node(10);
    root->left=new node(7);
    root->right=new node(4);
    root->left->left=new node(3);
    root->left->right=new node(11);
    root->right->left=new node(14);
    root->right->right=new node(6);
    map<int,vector<int>>m;
    int hdis=0;
    getVerticalOrder(root,hdis,m);
    for(auto val:m){
        for(int i=0;i<(val.second).size();i++){
            cout<<(val.second)[i]<<" ";
        }cout<<endl;
    }
}