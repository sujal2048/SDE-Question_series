#include<bits/stdc++.h>         //https://www.youtube.com/watch?v=YscEcXRmBoY&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=53
using namespace std;
class student{
    string name;
    public:                                  //makes the atribute of class accesible fron outside;
    
    int age;
    bool gender;

    student(){
        cout<<"default constructor"<<endl;
    }

    student(string s,int a,bool g){          //constructor automatically calls itself as soon as object is created
        cout<<"parametrised constructor"<<endl;
        name=s;
        age=a;
        gender=g;
    }   /// parameterize constructor
     
    student(student &a){                     //we should make our own copy constructor it copy pointer also  ->deep copy
        cout<<"Copy constructor"<<endl;      //default copy constructor ->shallow copy
        name=a.name;
        age=a.age;
        gender=a.gender;
    }
    ~student(){                              // destroy object
        cout<<"destructor called"<<endl;
    }
    void setname(string s){                  //now the name can be access only through setname from outside
        name=s;
    }
    void getname(){
        cout<<name<<endl;
    }
    void printinfo(){
        cout<<"NAME:"<<name<<endl;
        cout<<"AGE:"<<age<<endl;
        cout<<"GENDER:"<<gender<<endl;
    }
    bool operator == (student  &c){                  //operator overloaded
        if(name==c.name && age==c.age && gender==c.gender){
           return true;
        }
        return false;
    }
};
int main(){
   /* int n;
    cin>>n;
    student arr[100];             //n
    for(int i=0;i<n;i++){
        string s;                 //to store name from outside i.e. private members;
        cin>>s;                   //
        arr[i].setname(s);        //
        cin>>arr[i].age;
        cin>>arr[i].gender;
    }
    for(int i=0;i<n;i++){
        arr[i].printinfo();
    }
   */
    student a("Sujal",20,1);
    // a.printinfo();
    student b;
    student c=a;                    //copy constructor;
    if(c==a){                       //operator overloaded
        cout<<"same"<<endl;
    }
    else 
     cout<<"Not same"<<endl;
    return 0;
}                                   //destructor called this point and destroy all object

//error: lvalue required as left operand of assignment
//   42 |         if(name==a.name && age==a.age && gender=a.gender)
//      |                                                   ^~~~~~