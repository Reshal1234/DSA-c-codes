#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="aqyudkeafq";
    unordered_map<char,int>m;
    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }
    char x;
    int y,freq=0;
    for(auto val:m){
        if(val.second>freq){
            freq=val.second;
            x=val.first;
        }
    }
    cout<<x <<" has max frequency of "<<freq<<endl;
}