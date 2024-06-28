#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //map<int,int>freq;
    unordered_map<int,int>freq;
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    for(auto val:freq){
        cout<<val.first<<": "<<val.second<<endl;
    }
}