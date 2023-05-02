#include<bits/stdc++.h>                //https://www.youtube.com/watch?v=7ZfEp71tIec&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=55
using namespace std;
class A {
    public:
    void Afunc(){
        cout<<"Inherited A \n";
    }
};
class B :public A{           //inherited -> A ke public and protected(inheritable) wale, b ke public me aagenge
    public:                 //class B:private A {};  -> A ke public and protected(inheritable) wale, b ke private me aagenge
    void Bfunc(){
        cout<<"B \n";
    }                         //single inheritence
};
class D :public B{          //multi level inheritence
    public:
    void Dfunc(){
        cout<<"D \n";
    }                       
};
class a{
    public:
    void afunc(){
        cout<<"afunc"<<endl;
    }
};
class b{
    public:
    void bfunc(){
        cout<<"bfunc"<<endl;
    }
};
class C :public a , public b{              //multiple inheritence

};
int main(){
    B b;
    b.Afunc();
    C c;
    c.afunc();
    c.bfunc();
    D d;
    d.Afunc();
    return 0;
}