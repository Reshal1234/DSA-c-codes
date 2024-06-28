//question-unique no in a array where rest of no occur twice except two numbers
#include<bits/stdc++.h>
using namespace std;
int getBit(int n,int pos){
    return ((n&(1<<pos))!=0);
}
void unique(int arr[],int n){
        int xorsum=0;
        for(int i=0;i<n;i++){
            xorsum=xorsum^arr[i];
        }
        int setbit=0,pos=0;
        int tempxor=xorsum;
        while(setbit!=1){
            setbit=xorsum&1;
            pos++;
            xorsum=xorsum>>1;
        }
        int newxor=0;
        for(int i=0;i<n;i++){
            if(getBit(arr[i],pos-1)){
                newxor=newxor^arr[i];
            }
        }
        cout<<newxor<<endl;
        cout<<(tempxor^newxor)<<endl;
}
int main(){
    int arr[6]={1,1,2,2,3,4};
    unique(arr,6);
}