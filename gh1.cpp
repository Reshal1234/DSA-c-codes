#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=n*i+j+1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    int b[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]=n*(n-i)-j;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    int c[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=n*i+n-j;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}