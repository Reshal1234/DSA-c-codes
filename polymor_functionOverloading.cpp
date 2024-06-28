#include<bits/stdc++.h>
using namespace std;
class overloading{
    public:
    void fun(){
        cout<<"no argument"<<endl;
    }
    void fun(int x){
        cout<<"int argument"<<endl;
    }
    void fun(double x){
        cout<<"no argument"<<endl;
    }
};
int main(){
    overloading k;
    k.fun();
    k.fun(4);
    k.fun(2.3);

}