#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
class grp{
    public:
    long prefix,suffix,sum,ans;
};
int a[N];
grp tree[4*N];
void build(int node,int st,int en){
    if(st==en){
        if(a[st]<=0){
            tree[node]={0,0,a[st],0};
        }else{
            tree[node]={a[st],a[st],a[st],a[st]};
        }
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    long sum=tree[2*node].sum+tree[2*node+1].sum;
    long prefix=max(tree[2*node].prefix,tree[2*node].sum+tree[2*node+1].prefix);
    long suffix=max(tree[2*node+1].suffix,tree[2*node+1].sum+tree[2*node].suffix);
    long ans=max(tree[2*node].suffix+tree[2*node+1].prefix,max(tree[2*node].ans,tree[2*node+1].ans));
    tree[node]={prefix,suffix,sum,ans};
}
void update(int node,int st,int en,int idx,int val){
    if(st==en){
        a[st]=val;
        if(a[st]<=0){
            tree[node]={0,0,a[st],0};
        }else{
            tree[node]={a[st],a[st],a[st],a[st]};
        }
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }else{
        update(2*node+1,mid+1,en,idx,val);
    }
    long sum=tree[2*node].sum+tree[2*node+1].sum;
    long prefix=max(tree[2*node].prefix,tree[2*node].sum+tree[2*node+1].prefix);
    long suffix=max(tree[2*node+1].suffix,tree[2*node+1].sum+tree[2*node].suffix);
    long ans=max(tree[2*node].suffix+tree[2*node+1].prefix,max(tree[2*node].ans,tree[2*node+1].ans));
    tree[node]={prefix,suffix,sum,ans};
}
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    cout<<tree[1].ans<<endl;
    for(int i=0;i<m;i++){
        int idx,val;cin>>idx>>val;
        update(1,0,n-1,idx,val);
        cout<<tree[1].ans<<endl;
    }
}