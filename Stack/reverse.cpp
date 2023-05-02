#include<bits/stdc++.h>
#include<stack>
using namespace std;
void reverse(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word=s[i]+word;
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

}
void insertatbottom(stack<int> &st,int k){
    if(st.empty()){
        st.push(k);
        return;
    }
    int topk=st.top();
    st.pop();
    insertatbottom(st,k);
    st.push(topk);

}
void reversestack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int k=st.top();
    st.pop();
    reversestack(st);
    insertatbottom(st,k);  
}
void display(stack<int> &st){
     while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}
int main(){
    string s="Sujal, how are you doing";
    reverse(s);
    stack<int> st;
    st.push(1);
    st.push(2);st.push(3);st.push(4);st.push(5);
    display(st);
    st.push(1);
    st.push(2);st.push(3);st.push(4);st.push(5);
    reversestack(st);
    display(st);
    return 0;
}