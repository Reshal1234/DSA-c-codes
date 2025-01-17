#include<bits/stdc++.h>
using namespace std;
void update(int i,int inc,int bit[],int n){
    while(i<=n){
        bit[i]+=inc;
        i+=i&(-i);
    }
}
int query(int i,int bit[],int n){
    int ans=0;
    while(i>0){
        ans+=bit[i];
        i-=i&(-i);
    }
    return ans;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        int bit[n+10]={0};
        int u;cin>>u;
        while(u--){
            int l,r,inc; cin>>l>>r>>inc;
            l++;r++;     //to 0 based indexing to 1 base indexing
            update(l,inc,bit,n);
            update(r+1,-inc,bit,n);
        }
        int q; cin>>q;
        while(q--){
            int w; cin>>w;
            w++;
            cout<<query(w,bit,n)<<endl;
         }
    }
}