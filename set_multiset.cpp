#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    //print in reverse
    for(auto i=s.rbegin();i!=s.rend();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    set<int,greater<int>>s1;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    cout<<s.size()<<endl;;
    cout<<*s.lower_bound(2)<<endl;
    cout<<*s.upper_bound(2)<<endl;
    cout<<(s.upper_bound(3)==s.end())<<endl;
}
