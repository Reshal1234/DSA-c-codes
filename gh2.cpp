#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        for(int k=n-2*i+1;k>=0;k--){
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<" "<<j+1;
        }cout<<endl;
    }
}