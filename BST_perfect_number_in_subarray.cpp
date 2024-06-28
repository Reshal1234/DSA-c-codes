#include<bits/stdc++.h>
using namespace std;
bool isNumberPerfect(int n){
    int sum=1;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            if(i==n/i){
                sum+=i;
            }else{
                sum+=i+n/i;
            }
        }
    }
    if(sum==n&&n!=1){  //1 has only one divisor,so it is not a perfect number
        return true;
    }
    return false;
}
int maxSum(int arr[],int n,int k){
    if(n<k){
        cout<<"invalid values"<<endl;
        return -1;
    }
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int res=sum;
    for(int i=k;i<n;i++){
        sum+=(arr[i]-arr[i-k]);
        res=max(res,sum);
    }
    return res;
}
int maxNumberOfPerfects(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(isNumberPerfect(arr[i])){
            arr[i]=1;
        }else{
            arr[i]=0;
        }
    }
    return maxSum(arr,n,k);
}
int main(){
    int arr[]={28,2,3,6,496,99,8128,24};
    int k=4;
    int n=8;
    cout<<maxNumberOfPerfects(arr,n,k)<<endl;
}
