#include<bits/stdc++.h>           //https://www.youtube.com/watch?v=snDDBjT8jYA&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=78
#include<algorithm>              //if we reverse a string and then convert opening bracket to closing and vise versa and then perform 
using namespace std;                //infix to postfix and then reverse a string ->infix to prefix
int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' ||c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixtoprefix(string s){

    reverse(s.begin(),s.end());

    stack<char> st;
    string res;
     for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='z')){
            res=res+s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }

    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;

}
int main(){
    cout<<infixtoprefix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}
//"(a-b/c)*(a/k-l)"