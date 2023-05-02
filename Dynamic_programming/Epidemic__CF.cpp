#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1000000007;
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;b--;}a=(a*a)%MOD;b>>=1;}
   return res;}
int main(){
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vector<ll> a(k+1,0);
        vector<ll> coi(n+1,INT_MAX);
        for(int i=1;i<=k;i++){
            cin>>a[i];
        }
         for(int i=1;i<=k;i++){
            cin>>coi[a[i]];
        }
        vector <ll> l(n+1,INT_MAX);
        vector <ll> r(n+1,INT_MAX);
        ll p=INT_MAX;
        for(int i=1;i<=n;i++){
            l[i]=min(p+1,coi[i]);
            p=l[i];
        }
        p=INT_MAX;
        for(int i=n;i>0;i--){
            r[i]=min(p+1,coi[i]);
            p=r[i];
        }
        for(int i=1;i<=n;i++){
            cout<<min(l[i],r[i])<<" ";
        }cout<<endl;
    }
    return 0;
}