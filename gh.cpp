#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"enter the number of string input : ";
    int n,count=0; cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cout<<"enter the string "<<i+1<<" : ";
        cin>>s[i];
    }
    string r;
    cout<<"enter the string which should be present : ";
    cin>>r;
    for(int i=0;i<n;i++){
        if(s[i].length()<r.length()) continue;
        for(int j=0;j<s[i].length()-r.length()+1;j++){
            if(s[i].substr(j,r.length())==r) count++;
        }
    }
    cout<<"total no. of times '"<<r<<"' has occured is : "<<count<<endl;
}