#include<bits/stdc++.h>
using namespace std;
int rainwater(vector<int>v){
    stack<int>st;
    int n=v.size(),ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty()&&v[st.top()]<v[i]){
            int curr=st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int dif=i-st.top()-1;
            ans +=((min(v[st.top()],v[i])-v[curr])*dif);
        }
        st.push(i);
    }
    return ans;
}
int main(){
    vector<int>v={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rainwater(v)<<endl;
}