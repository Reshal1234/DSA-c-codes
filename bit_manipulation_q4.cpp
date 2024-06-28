//question-unique no in a array where rest of no occur twice except one
#include<bits/stdc++.h>
using namespace std;
int unique(int arr[],int n){
        int xorsum=0;
        for(int i=0;i<n;i++){
            xorsum=xorsum^arr[i];
        }
        return xorsum;
}
int main(){
    int arr[5]={1,1,2,2,3};
    cout<<unique(arr,5);
}