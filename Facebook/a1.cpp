#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;cin>>t;
    for(int i=1;i<=t;i++){
        ll n;cin>>n;
        string s;cin>>s;
        int ans=0;bool first=false;char current;
        for(int j=0;j<n;j++){
            char ch=s[j];
            if(ch!='F'){
              if(!first){
                  current=ch;
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
