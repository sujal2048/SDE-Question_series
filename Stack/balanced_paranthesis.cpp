#include<bits/stdc++.h>                        //https://www.youtube.com/watch?v=P31WyOcQvaE&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=78
using namespace std;
bool isvalid(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='[' ||s[i]=='{' || s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(s[i]==')'){
               if( !st.empty() && st.top()=='('){
                  st.pop();              
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
               if(  !st.empty() && st.top()=='['){
                   st.pop();
               }
               else{
                   return false;
               }
            }
            else if(s[i]=='}'){
               if(  !st.empty() && st.top()=='{'){
                   st.pop();
               }
               else{
                   return false;
               }
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string s="[{()}]";
    if(isvalid(s)){
        cout<<"VALID STRING"<<endl;
    }
    else{
        cout<<"NON VALID STRING"<<endl;
    }
    return 0;
}
//"{[()[["