//doubt
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
struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
Info largestBSTInBT(node* root){
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL&&root->right==NULL){
        return {1,root->data,root->data,1,true};
    }
    Info leftInfo=largestBSTInBT(root->left);
    Info rightInfo=largestBSTInBT(root->right);
    Info curr;
    curr.size=(1+leftInfo.size+rightInfo.size);
    if(leftInfo.isBST&&rightInfo.isBST&&leftInfo.max<root->data&&rightInfo.min>root->data){
        curr.min=min(leftInfo.min,min(rightInfo.min,root->data));
        curr.max=max(leftInfo.max,max(rightInfo.max,root->data));
        curr.ans=curr.size;
        return curr;
    }
    curr.ans=max(leftInfo.ans,rightInfo.ans);
    curr.isBST=false;
    return curr;
}
int main(){
    node* root=new node(15);
    root->left=new node(10);
    root->right=new node(30);
    root->left->left=new node(5);
    cout<<largestBSTInBT(root).ans<<endl;
}