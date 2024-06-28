0//question-unique no in a array where rest of no occur thrice except one
#include<bits/stdc++.h>
using namespace std;
int getBit(int n,int pos){
    return ((n&(1<<pos))!=0);
}
int setBit(int n,int pos){
    return (n|(1<<pos));
}
int unique(int arr[],int n){
    int result=0;
        for(int i=0;i<64;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(getBit(arr[j],i)){
                    sum++;
                }
            }
            if(sum%3!=0){
                result=setBit(result,i);
            }
        }
        return result;
}
int main(){
    int arr[7]={1,1,1,2,2,2,3};
    cout<<unique(arr,7)<<endl;
}