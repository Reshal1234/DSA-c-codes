#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int> adj[N];
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjm(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    cout<<"adjacency matrix of above graph is given by: "<<endl;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<adjm[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    if(adjm[7][3]==1){
        cout<<"edge is present"<<endl;
    }else{
        cout<<"edge is not present"<<endl;
    }
    cin>>n,m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"adjacency list of the above graph is given by: "<<endl;
    for(int i=1;i<n+1;i++){
        cout<<i<<"->";
        vector<int>::iterator it;
        for(it=adj[i].begin();it<adj[i].end();it++){
            cout<<*it<<" ";
        }cout<<endl;
    }
}