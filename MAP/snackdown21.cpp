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
    ll q;cin>>q;
    while(q--){
        ll n;cin>>n;
        vector<ll> a(n);vector<ll> b(n);
        vector<ll> c(n+1,0);ll count=0;ll ci=0,co=0;
        unordered_map<ll,ll> w;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(c[a[i]-1]==0){
               b[i]=a[i]-1;
               c[a[i]-1]++;
            }
            else{
                ci=a[i]-1;
                count=a[i]-1;
                while(count>=0 && c[count]!=0){
                    if(w.find(count)!=w.end()){
                    count=w[count];
                    }
                    count--;
                }
                if(count>=0){
                    b[i]=count;
                    c[count]++;
                }
                else{
                    b[i]=a[i]-1;
                }
                co=count;
            }
            w[ci]=co;
        }
        for(int i=0;i<n;i++){
            cout<<b[i]<<" ";
        }cout<<" "<<endl;
    }
    return 0;
}
