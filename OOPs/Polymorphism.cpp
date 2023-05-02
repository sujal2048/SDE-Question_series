#include<bits/stdc++.h>     //many forms -> poly...morphism
using namespace std;        //https://www.youtube.com/watch?v=F5PbnZkHqmg&t=115s

//function overloading
class apni{
    public:
    void func(){
        cout<<"I am a func with no argument"<<endl;
    }
    void func(int x){
        cout<<"I am a func with int argument"<<endl;
    }
};

//operator overloading
class Complex{
    private:
    
    public:
     int real,img;
    
    Complex(int r=0,int m=0){          //complex(int r=0,int m=0){}  //default construtor
        real=r;
        img=m;
    }
    Complex operator + (Complex const &obj){
           Complex res;
           res.real=real+obj.real;
           res.img =img+obj.img;
           return res;
    }
    void display(){
        cout<<real<<" +i "<<img<<endl;
    }
};

class base{
    public:
    virtual void print(){                                      //to change at run time virtual keyword is used
        cout<<"this is base class print func \n";              //dynamically bound ho raha hai
    }
    void display(){
        cout<<"this is base class display func \n";             //ye statically bound ho raha hai
    }
};
class derived : public base{
    public:
    void print(){
        cout<<"this is derived class print func \n";
    }
    void display(){
        cout<<"this is derived class display func \n";
    }
};
int main(){
    apni obj;
    obj.func();
    obj.func(5);
    cout<<endl;

    Complex c1(4,7);
    Complex c2(4,6);
    Complex c3=c1+c2;
    c3.display();
    cout<<endl;

    base *baseptr;
    
    derived d;
    baseptr=&d;
    baseptr -> print();
    baseptr -> display();

    return 0;
}