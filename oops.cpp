#include<bits/stdc++.h>
using namespace std;
class student{
    string name;
    public:
    int age;
    bool gender;
    void setName(string s){
        name=s;
    }
    student(){
        cout<<"default constructor"<<endl;
    }//default constructor
    student(string s,int n,int g){
        cout<<"parameterised constructor"<<endl;
        name=s;
        age=n;
        gender=g;
    }//parameterised constructor
    student(student &a){
        cout<<"copy constructor"<<endl;
        name=a.name;
        age=a.age;
        gender=a.gender;
    }
    ~student(){
        cout<<"destructor called"<<endl;
    }
    bool operator ==(student &a){
        if(name==a.name&&age==a.age&&gender==a.gender){ //here name is the second operand
            return true;
        }
        return false;
    }
    void getName(){
        cout<<name<<endl;
    }
    void printInfo(){
        cout<<"name= ";
        cout<<name<<endl;
        cout<<"age: ";
        cout<<age<<endl;
        cout<<"gender: ";
        cout<<gender<<endl;
    }
};
int main(){
    // student arr[3];
    // for(int i=0;i<3;i++){
    //     string s;
    //     cout<<"name= ";
    //     cin>>s;
    //     arr[i].setName(s);
    //     cout<<"age: ";
    //     cin>>arr[i].age;
    //     cout<<"gender: ";
    //     cin>>arr[i].gender;
    // }
    // for(int i=0;i<3;i++){
    //     arr[i].printInfo();
    // }
    student a("Urvi",20,1);
    // a.printInfo();
    student b;
    student c=a;
    if(c==a){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
}