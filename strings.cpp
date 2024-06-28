    #include<bits/stdc++.h>
using namespace std;
int main(){
    string s(5,'n');
    string s1;
    getline(cin,s1);
    cout<<s1<<endl;
    cout<<s<<endl;
    s1.append(s);
    cout<<s1;
    if(!s1.compare(s)){
        cout<<"strings are equal"<<endl;
    }
    else cout<<"strings are not equal"<<endl;
    s.insert(2,"lol");
    cout<<s<<endl;
    s1.clear();
    string s2="786";
    int x=stoi(s2),y=450;
    cout<<x+2<<endl;
    cout<<to_string(y)+"2"<<endl;
    string s3="xzabdjfi";
    sort(s3.begin(),s3.end());
    cout<<s3<<endl;
    cout<<s1<<endl;
    string s4="5284249";
    sort(s4.begin(),s4.end(),greater<int>());
    cout<<s4<<endl;
}