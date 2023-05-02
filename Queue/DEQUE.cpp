#include<bits/stdc++.h>   //  //combination of stack queue
#include<deque>             //https://www.youtube.com/watch?v=4JstGzs6Q9I&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=84
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    for(auto i:dq){
        cout<<i<<" ";
    }
    cout<<endl;
    dq.pop_back();
    dq.pop_front();
    for(auto i:dq){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<dq.size()<<endl;
    return 0;
}