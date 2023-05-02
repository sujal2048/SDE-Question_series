//https://www.youtube.com/watch?v=ay3vwXWpqck
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
const int MOD = 1000000007;
ll power(ll a, ll b){
    ll res=1;a=a%MOD;
    while(b>0){
        if(b&1){
            res=(res*a)%MOD;b--;
        }
        a=(a*a)%MOD;b>>=1;}
    return res;
    }
ll smallb(ll a,string s){ll mod=0;ll l=s.length();for(int i=0;i<l;i++){mod=(mod*10 + (s[i]-'0'))%a;}
    return mod;}
ll gcd(ll a, ll b){
    if (!a)return b;
    return gcd(b % a, a);}
ll gcdlarge(ll a,string s){ll num=smallb(a,s);return gcd(a,num);}
bool compare(pair<char,ll> p1,pair<char,ll> p2){if(p1.second>p2.second){return true;}return false;}
vector<bool> prim(20000+1,true);
void SieveOfEratosthenes(int n){
    for (int p = 2; p * p <= n; p++){
        if (prim[p] == true){
            for (int i = p * p; i <= n; i += p)
                prim[i] = false;}
    }}
ll countDivisors(ll n)    //tc =n^1/2
{
    ll cnt = 0;ll til=sqrt(n);
    for (int i = 1; i <= til; i++) {
        if (n % i == 0) {
            if (n / i == i)
                cnt++;
            else 
                cnt = cnt + 2;
        }
    }
    return cnt;
}
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll sof(ll n){
    ll nas=0;
    for(int i=1;i<=n;i++){
        nas=nas+i;
    }
    return nas;
}
int getSingle(vector<ll> arr, int n)
{
    int ones = 0, twos = 0;
    int common_bit_mask;
    for (int i = 0; i < n; i++) {
        twos = twos | (ones & arr[i]);
        ones = ones ^ arr[i];
        common_bit_mask = ~(ones & twos);
        ones &= common_bit_mask;
        twos &= common_bit_mask;
    }
    return ones;
}
 
int main(){
    FIO;
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=getSingle(arr,n);
        cout<<ans<<endl;
    }
    return 0;
}
