#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,w;cin>>n>>w;
    vector<int>val(n);
    for(auto &i:val){
        cin>>i;
    }
    vector<int>wt(n);
    for(auto &i:wt){
        cin>>i;
    }
    vector<int>dp(w+1,0);
    for(int j=0;j<=w;j++){
        for(int i=0;i<n;i++){
            if(j-wt[i]>=0){
                dp[j]=max(dp[j],val[i]+dp[j-wt[i]]);
            }
        }
    }
    cout<<dp[w];
}