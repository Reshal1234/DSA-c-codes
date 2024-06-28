#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
bool vis[N];
vector<int>adj[N];
void DFS(int node){
    //preorder
    vis[node]=true;
    cout<<node<<endl;
    for(auto val:adj[node]){
        if(!vis[val]){
            DFS(val);
            cout<<"bactrack from "<<val<<" to "<<node<<endl;
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<=n;i++){
        vis[i]=false;
    }
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1);
}