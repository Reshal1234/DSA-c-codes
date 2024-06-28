#include<bits/stdc++.h>
using namespace std;
int firstOccur(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    firstOccur(arr,n,i+1,key);
}
int lastOccur(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    int restArray=lastOccur(arr,n,i+1,key);
    if(restArray!=-1){
        return restArray;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}
int main(){
    int arr[7]={2,4,3,5,6,3,8};
    cout<<firstOccur(arr,7,0,3)<<endl;
    cout<<lastOccur(arr,7,0,3)<<endl;
}