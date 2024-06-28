#include<bits/stdc++.h>
using namespace std;
void primeFactor(int n){
    int spf[100];
    for(int i=0;i<100;i++){
        spf[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }cout<<endl;
}
int main(){
    primeFactor(20);
}