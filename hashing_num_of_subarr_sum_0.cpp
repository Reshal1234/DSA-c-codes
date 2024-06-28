#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int>cnt;
    int prefSum=0;
    for(int i=0;i<n;i++){
        prefSum+=a[i];
        cnt[prefSum]++;
    }
    int ans=0;
    for(auto val:cnt){
        int c=val.second;
        ans+=(c*(c-1))/2;
        if(val.first==0){
            ans+=val.second;
        }
    }
    cout<<ans<<endl;
}