#include<bits/stdc++.h>
using namespace std;
vector<int>bit;
int getSum(int idx){
    int ans=0;
    while(idx>0){
        ans+=bit[idx];
        idx-=idx&(-idx);
    }
    return ans;
}
void update(int n,int idx,int inc){
    while(idx<=n){
        bit[idx]+=inc;
        idx+=idx&(-idx);
    }
}
int main(){
    int n; cin>>n;
    vector<int>a(n);
    for(auto &i:a){
        cin>>i;
    }
    vector<int>temp=a;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++){
        a[i]=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin()+1;
    }
    bit=vector<int>(n+1);
    int inv=0;
    for(int i=n-1;i>=0;i--){
        inv+=getSum(a[i]-1);
        update(n,a[i],1);
    }
    cout<<inv<<endl;
}