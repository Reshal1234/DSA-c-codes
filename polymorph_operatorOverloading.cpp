#include<bits/stdc++.h>
using namespace std;
class comple{
    private:
    int real,imag;
    public:
    comple(int r=0,int i=0){
        real=r;
        imag=i;
    }
    comple operator +(comple const &obj){
        comple res;
        res.imag=imag+obj.imag;
        res.real=real+obj.real;
        return res;
    }
    void display(){
        cout<<real<<" +i"<<imag<<endl;
    }
};
int main(){
    comple c1(12,7);
    comple c2(6,7);
    comple c3=c1+c2;
    c3.display();
    return 0;
}