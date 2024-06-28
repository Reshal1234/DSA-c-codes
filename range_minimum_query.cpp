#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+2,MOD=1e9+7;
signed main(){
    int n; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int len=(int)sqrtl(n)+1;
    vector<int>b(len,MOD);
    for(int i=0;i<n;i++){
        b[i/len]=min(a[i],b[i/len]);
    }
    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        int ans=MOD;
        for(int i=l;i<=r;){
            if(i%len==0&&i+len-1<=r){
                ans=min(b[i/len],ans);
                i+=len;
            }else{
                ans=min(a[i],ans);
                i++;
            }
        }
        cout<<ans<<endl;
    }
}