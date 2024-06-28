#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr,n);
    cin.ignore();
    int curle=0,maxle=0,i=0,st=0,maxst=0;
    while(1){
        if(arr[i]==' '||arr[i]=='\0'){
            if(curle>maxle){
                maxle=curle;
                maxst=st;
            }
            curle=0;
            st=i+1;
        }
        else{
            curle++;
        }
        if(arr[i]=='\0'){
            break;
        }
        i++;
    }
    cout<<maxle<<endl;
    for(int i=0;i<maxle;i++){
        cout<<arr[i+maxst];
    }
    cout<<endl;
}