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
vector<bool> prim(20000+1,true);
void SieveOfEratosthenes(int n){
    for (int p = 2; p * p <= n; p++){
        if (prim[p] == true){
            for (int i = p * p; i <= n; i += p)
                prim[i] = false;}
    }}
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int main(){
    FIO;
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll i=0;ll c;ll b;ll value=0;ll s;bool jump=false;
        while(k>0){
            b=power(10ll,a[i]);
            if(i+1<n){c=power(10ll,a[i+1]);c=c/b -1;s=min(k,c);
            if(s==c && s==k){jump=true;}
            }
            else{s=k;}
            k=k-s;
            value=value+(b*s);
            i++;
        }
        if(!jump){
        value=value+b;}
        else{
            value=value-power(10ll,a[0]);
            value=value+power(10ll,a[i]);
        }
        cout<<value<<endl;
    }
   return 0;
}
