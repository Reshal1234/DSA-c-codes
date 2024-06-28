#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int k; cin>>k;
    vector<int>v(n);
    for(auto &i:v){
        cin>>i;
    }
    bool found=false;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        int lo=i+1,hi=n-1;
        while(lo<hi){
            int curr=v[lo]+v[hi]+v[i];
            if(curr==k){
                found=true;
            }
            if(curr<k){
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    if(found){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
}