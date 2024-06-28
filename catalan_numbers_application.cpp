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
int catalan(int n){
    int res=0;
    if(n<=1){
        return 1;
    }
    for(int i=0;i<n;i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}
vector<node*>constructTrees(int start,int end){
    vector<node*>trees;
    if(start>end){
        trees.push_back(NULL);
    }
    for(int i=start;i<end;i++){
        vector<node*>leftSubtrees=constructTrees(start,i-1);
        vector<node*>rightSubtrees=constructTrees(i+1,end);
        for(int j=0;j<leftSubtrees.size();j++){
            node* left=leftSubtrees[j];
            for(int k=0;k<rightSubtrees.size();k++){
                node* right=rightSubtrees[k];
                node* root=new node(i);
                root->left=left;
                root->right=right;
                trees.push_back(root);
            }
        }
    }
    return trees;
}
void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    for(int i=0;i<10;i++){
        cout<<catalan(i)<<" ";
    }
    vector<node*>totalTrees=constructTrees(1,3);
    for(int i=0;i<totalTrees.size();i++){
        cout<<(i+1)<<" ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
    cout<<endl;
}