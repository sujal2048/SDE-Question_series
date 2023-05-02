//hbnbn
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll md=1000000000+7;
    ll t;cin>>t;
    vector<ll> dp(800000,0);
    for(ll i=1;i<=t;i++){
        ll n;cin>>n;
        string s;cin>>s;
        ll final=0;ll ans=0;
       
        bool first=false;char current;
        for(ll j=0;j<n;j++){
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
            final=(final%md + ans%md)%md;
            if(j>0){
                dp[j]=final;
            }
        }
        ans=0;
        cout<<"Case #"<<i<<": "<<final%md<<endl;
        for(int k=0;k<n;k++){
            cout<<dp[k]<<" ";
        }cout<<endl;
        
    }
    return 0;
}