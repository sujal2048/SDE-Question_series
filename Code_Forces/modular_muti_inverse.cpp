#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll fact[1000001];
const int MOD = 1000000007;
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;b--;}a=(a*a)%MOD;b>>=1;}
   return res;}
ll invf(ll val){
    return power(val,MOD-2);
    }
void pre(){
    fact[0]=1;
    for(int i=1;i<=1000000;i++)
        fact[i]=(i*fact[i-1])%MOD;
    return;
}
int main(){
    pre();
    ll a,b,n;cin>>a>>b>>n;
    ll na,nb,sum,x,nax,nbx,ntx,combo;ll ans=0;
    for(ll i=0;i<=n;i++){
         na=i;
         nb=n-i;
         sum=(na*a)+(nb*b);
         x=sum; nax=0; nbx=0;ntx=0;
        while(x>0){
            ll t=x%10;
            if(t==a){
                nax++;
            }
            if(t==b){
                nbx++;
            }
            ntx++;
            x=x/10;
        }
        
        if(ntx==(nbx+nax)){
            ans=(ans+       (    (  fact[n]*invf(fact[i])  )%MOD   *    invf(fact[n-i])%MOD      )        )%MOD;
           // https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
            //ans=(ans+           (  fact[n]   /  ((fact[i])*(fact[n-i]))    )        )%MOD;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}