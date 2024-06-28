#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele=st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,ele);
}
int main(){
    stack<int>st;
    st.push(4);
    st.push(3);
    st.push(7);
    st.push(5);
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}