#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quickSort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi,r);
    }
}
int main(){
    int arr[]={5,4,3,2,1};
    quickSort(arr,0,(sizeof(arr)/sizeof(int))-1);
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}