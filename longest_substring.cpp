#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    vector<int>v(256,-1);
    int maxLen=0,start=-1;
    for(int i=0;i<s.length();i++){
        if(v[s[i]]>start){
            start=v[s[i]];
        }
        v[s[i]]=i;
        maxLen=max(maxLen,i-start);
    }
    cout<<maxLen<<endl;
}