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
bool compare(pair<ll,ll> p1,pair<ll,ll> p2){
    if(p1.first<=p2.first){
        return true;
    }
        return false;
        }
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

int LIS(vector<ll> &a){
    vector<ll> lis;
    for(auto &x :a){
        auto it=lower_bound(lis.begin(),lis.end(),x);     //lower for strictly increasing ,upper for non decreasing;
        if(it==lis.end()){                                // LENGTH OF LIS
            lis.push_back(x);
        }
        else{
            *it=x;
        }
    }
    return lis.size();
}
int lis(vector<ll> arr)   // tc=(n*n) dp approach
{
    ll n=arr.size();
    vector<ll> lis(n);
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] >= arr[j] )           //= for non decreasing   ,  > for strictly increaasing
                lis[i] = max(lis[i],lis[j] + 1);
    }
    return *max_element(lis.begin(),lis.end());
}
  
int main(){
    FIO;
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n;
        vector<ll> a(n);
        //vector<ll> b(m);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        cout<<lis(a)<<endl;
    }
    return 0;
}
