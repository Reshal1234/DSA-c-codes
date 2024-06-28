#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int>freq;
    for(int i=0;i<n;i++){
        int presentsize=freq.size();
        if(freq[a[i]]==0&&presentsize==k){
            break;
        }
        freq[a[i]]++;
    }
    vector<pair<int,int>>ans;
    for(auto val:freq){
        pair<int,int>p;
        if(val.second!=0){
            p.first=val.second;
            p.second=val.first;
            ans.push_back(p);
        }
    }
    sort(ans.begin(),ans.end(),greater<pair<int,int>>());
    for(auto val:ans){
        cout<<val.second<<" "<<val.first<<endl;
    }
}