#include<bits/stdc++.h>
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
bool compare(pair<char,ll> p1,pair<char,ll> p2){if(p1.second>p2.second){return true;}return false;}
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int main(){
    FIO;
    ll w;cin>>w;
    while(w--){
       ll n;cin>>n;
       vector<ll> a(n);unordered_map<ll,ll> m; vector<vector<ll>> b(2000, vector<ll> (n));
       for(int i=0;i<n;i++){
           cin>>a[i];m[a[i]]++;
       }
       ll q;cin>>q;
       bool decide=false;b[0]=a;
        for(auto z:m){
            if(z.first!=z.second){
                decide=true;
            }
        }
        ll last=0;
        ll z=1;
        while(decide){
            decide=false;
            for(int i=0;i<n;i++){
                b[z][i]=m[a[i]];
                a[i]=m[a[i]];
            }
            m.clear();
            for(int i=0;i<n;i++){
               m[a[i]]++;
            }
            for(auto y:m){
                if(y.first!=y.second){
                decide=true;
                }
            }
            z++;last++;
        }
        ll g,h;


        for(int i=1;i<=q;i++){
            cin>>g>>h;
            if(h>=last){
                cout<<b[last][g-1]<<endl;
            }
            else{
                cout<<b[h][g-1]<<endl;
            }
        }

    }
    return 0;
}
