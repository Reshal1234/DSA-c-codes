#include<bits/stdc++.h>
using namespace std;
int kadane(int n,int arr[]){
    int maxsum=INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0) sum=0;
        maxsum=max(sum,maxsum);
    }
    return maxsum;
}
int main(){
    int n; cin>>n;
    int arr[n],nonwrapsum,totalsum=0,wrapsum;
    for(int i=0;i<n;i++) cin>>arr[i];
    nonwrapsum=kadane(n,arr);
    for(int i=0;i<n;i++){
        totalsum+=arr[i];
        arr[i]=-arr[i];
    }
    wrapsum=totalsum+kadane(n,arr);
    cout<<max(nonwrapsum,wrapsum);
}