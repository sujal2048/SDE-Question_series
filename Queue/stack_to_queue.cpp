#include<bits/stdc++.h>
using namespace std;                  //stack to queue using only one stack
class que{

    stack<int> s1;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){                               //store rest of element temporarily and doing pop for queue and putting it back
        if(s1.empty()){   
            cout<<"Queue empty"<<endl;          //seeeeeeee it
            return -1;
        }
        int x=s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item=pop();
        s1.push(x);
        return item;
    }
    bool empty(){
        if(s1.empty())
         return true;
        return false;
    }


};
int main(){
     que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop();
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

    

    return 0;
}