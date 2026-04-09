#include<bits/stdc++.h>
using namespace std;
int main(){
    ll t;cin>>t;
    for(int i=1;i<=t;i++){
        ll n;cin>>n;
        string s;cin>>s;
        for(int j=0;j<n;j++){
            char ch=s[j];
            if(ch!='F'){
              if(!first){
                  first=true;
              }
              else{
                  if(current!=ch){
                      ans++;current=ch;
                  }
              }
            }
        }
       
    }
    return 0;
}
