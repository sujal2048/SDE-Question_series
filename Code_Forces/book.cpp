#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;b--;}a=(a*a)%MOD;b>>=1;}
   return res;}
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<vector<ll>> a(200000+1,vector<ll> (200000+1,0));
        ll count=0;vector<ll> counter(200000+1);ll poss=true;
        for(int i=1;i<=n;i++){
            cin>>a[i][0];
            if(a[i][0]==0){
                count++;
                counter.push_back(i);
            }
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                if(a[i][j]==i){
                    poss=false;
                }
            }
        }
        if(count==0 && (!poss)){
            cout<<-1<<endl;
        }
        

    }
    return 0;
}
