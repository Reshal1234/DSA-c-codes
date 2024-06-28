#include<bits//stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"input the line : ";
    getline(cin,s,'\n');
    for(int i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
        if(s[i-1]==' ') s[i]=toupper(s[i]);
    }s[0]=toupper(s[0]);
    cout<<s<<endl;
}