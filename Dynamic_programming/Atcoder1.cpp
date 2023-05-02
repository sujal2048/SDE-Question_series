#include<bits/stdc++.h>        // https://atcoder.jp/contests/dp/tasks/dp_b
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
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k>=(n-1)){
        cout<<abs(a[0]-a[n-1])<<endl;
    }
    else{
        vector<ll> dp(n,INT_MAX);
        dp[0]=0;ll k1=k;
        for(int i=1;i<=k;i++){
            for(int j=i-1;j>=0;j--){
                dp[i]=min(dp[i],dp[j]+abs(a[j]-a[i]));
            }
        }
        for(int i=k+1;i<n;i++){
            for(int j=i-1;j>=i-k;j--){
                dp[i]=min(dp[i],dp[j]+abs(a[j]-a[i]));
            }
        }
        
        cout<<dp[n-1]<<endl;
    }
    return 0;
}
