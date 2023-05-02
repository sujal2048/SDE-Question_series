#include<bits/stdc++.h>//https://codeforces.com/group/nisINkUPNQ/contest/344953
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1000000007;
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;b--;}a=(a*a)%MOD;b>>=1;}
   return res;}
ll smallb(ll a,string s){ll mod=0;ll l=s.length();for(int i=0;i<l;i++){mod=(mod*10 + (s[i]-'0'))%a;}
    return mod;}
ll gcd(ll a, ll b){if (!a)return b;return gcd(b % a, a);}
ll gcdlarge(ll a,string s){ll num=smallb(a,s);return gcd(a,num);}
int main(){
    ll n;cin>>n;
    vector<ll> s(n,0);
    vector<ll> c(n,0);
    vector<ll> pre(n,INT_MAX);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){
            if(s[j]<=s[i]){
                continue;
            }
            pre[i]=min(pre[i],c[j]);
        }
    }ll found=0;ll ans=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[j]<=s[i]){
                continue;
            }
            if(pre[j]!=INT_MAX){
                found=1;
                ans=min(ans,c[i]+c[j]+pre[j]);
            }
        }
    }
    if(found){
        cout<<ans<<endl;
    }
    else
        cout<<-1<<endl;
    return 0;
}