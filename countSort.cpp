#include<bits/stdc++.h>
using namespace std;
void countSort(int arr[],int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(arr[i],k);
    }
    int count[k+1]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
int main(){
    int arr[]={1,2,4,2,1,3,7,5};
    countSort(arr,sizeof(arr)/sizeof(int));
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}