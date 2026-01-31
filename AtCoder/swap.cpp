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
        ll n;cin>>n;
        vector<ll> a(n);
        vector<ll> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
         for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int mx=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i]<b[j] && mx>(i+j)){
                    mx=i+j;
                }
                if(i+j>mx){
                    break;
                   
                }
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
