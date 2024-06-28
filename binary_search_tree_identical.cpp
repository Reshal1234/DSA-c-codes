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
bool isIdentical(node* root1,node* root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    else if(root1==NULL||root2==NULL){
        return false;
    }else{
        bool cond1=root1->data==root2->data;
        bool cond2=isIdentical(root1->left,root2->left);
        bool cond3=isIdentical(root1->right,root2->right);
        if(cond1&&cond2&&cond3){
            return true;
        }
        return false;
    }
}
int main(){
    node* root1=new node(12);
    root1->left=new node(9);
    root1->right=new node(15);
    root1->left->left=new node(5);
    root1->left->right=new node(10);

    node* root2=new node(12);
    root2->left=new node(9);
    root2->right=new node(15);
    root2->left->left=new node(5);
    root2->left->right=new node(20);
    if(isIdentical(root1,root2)){
        cout<<"BSTs are identical"<<endl;
    }else{
        cout<<"BSTs are not identical"<<endl;
    }
}