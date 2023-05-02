#include<bits/stdc++.h>                //https://www.youtube.com/watch?v=iEwX3XA5SDo&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=81
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class Queue{
    node* front;
    node* back;

    public:
    Queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* n=new node(x);
        if(front==NULL){
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void pop(){
        if(front== NULL){
            cout<<"queue is empty"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;
    }
    int peek(){
        if(front== NULL){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front== NULL){
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