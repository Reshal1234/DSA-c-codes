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
bool getPath(node* root,int key,vector<int>&path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }
    if(getPath(root->left,key,path)||getPath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}
int LCA(node* root,int n1,int n2){
    vector<int> path1,path2;
    if(!getPath(root,n1,path1)||!getPath(root,n2,path2)){
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size()&&path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];
}
node* LCA2(node* root,int n2,int n1){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1||root->data==n2){
        return root;
    }
    node* leftLCA=LCA2(root->left,n2,n1);
    node* rightLCA=LCA2(root->right,n2,n1);
    if(leftLCA&&rightLCA){
        return root;
    }
    if(leftLCA!=NULL){
        return leftLCA;
    }
    return rightLCA;
}
int main(){
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    int n1=6;
    int n2=7;
    // int lca=LCA(root,n1,n2);
    // if(lca==-1){
    //     cout<<"LCA does not exist"<<endl;
    // }else{
    //     cout<<"LCA: "<<lca<<endl;
    // }
    node* lca1=LCA2(root,n1,n2);
    if(lca1==NULL){
        cout<<"LCA does not exist"<<endl;
    }else{
        cout<<"LCA: "<<lca1->data<<endl;
    }
}