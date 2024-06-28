//question- number of 1's in bit of a number
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=17,count=0;
    while(n!=0){
        n=n&(n-1);
        count++;
    }
    cout<<count<<endl;
}