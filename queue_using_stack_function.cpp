#include<bits/stdc++.h>
using namespace std;
class queu{
    stack<int>s1;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int x=s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item=pop();
        s1.push(x);
        return item;
    }
    bool empty(){
        if(s1.empty()){
            return true;
        }
        return false;
    }
};
int main(){
    queu q;
    q.push(4);
    q.push(3);
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;

}