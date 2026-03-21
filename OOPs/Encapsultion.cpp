
#include<bits/stdc++.h>
using namespace std;

class A{
  public: 
  int a;
  void funca(){
      cout<<"funca \n";
  }
  private:
  int b;
  void funcb(){
     cout<<"funcb \n";
  }
  protected:
  int c;
  void funcc(){
     cout<<"funcc \n";
  }
};

int main(){

    A obj;
    obj.funca();
    return 0;
}
