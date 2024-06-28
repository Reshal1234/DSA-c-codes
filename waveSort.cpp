#include<bits/stdc++.h>
using namespace std;
void waveSort(int arr[],int n){
    int i=1;
    while(i<n){
        if(arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[i+1]&&i<=(n-2)){
            swap(arr[i],arr[i+1]);
        }
        i+=2;
    }
}
int main(){
    int arr[]={1,2,0,1,0,0,2};
    waveSort(arr,sizeof(arr)/sizeof(int));
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}