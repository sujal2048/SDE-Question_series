#include<bits/stdc++.h>
using namespace std;
#define n 100
class Queue{
     int* arr;
     int front;
     int back;
     public:
     Queue(){
         arr=new int[n];          //array ko memeory allocate kar rahe hai
         front=-1;
         back=-1;
     }
     void pop(){
         if(front==-1 || front >back){
             cout<<"Queue is empty"<<endl;
             return;
         }
         front++;
     }
     void push(int a){
         if(back==n-1){
             cout<<"Queue overflow"<<endl;
             return;
         }
         back++;
         arr[back]=a;
         if(front==-1){
             front++;
         }
         return;
     }
     int peek(){
          if(front==-1 || front >back){
             cout<<"Queue is empty"<<endl;
             return -1;
         }
         return arr[front];
     }
     bool empty(){
         if(front==-1 || front >back){
             return true;
         }
         return false;
     }

};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.empty()<<endl;

    return 0;
}