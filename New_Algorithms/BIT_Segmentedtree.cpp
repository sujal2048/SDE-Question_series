#include<bits/stdc++.h>  
using namespace std;
#define ll long long
#define ld long double
const int MOD = 100000007;
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

void buildS(vector<ll> &stree,ll n,vector<ll> arr)
{
    for (int i=0; i<n; i++)   
        stree[n+i] = arr[i];
     
    for (int i = n - 1; i > 0; --i)    
        stree[i] = stree[i<<1] + stree[i<<1 | 1];   
}
int queryS(vector<ll> stree,ll n,int l, int r)   // index 0    https://www.geeksforgeeks.org/segment-tree-efficient-implementation/?ref=lbp
{
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res += stree[l++];
     
        if (r&1)
            res += stree[--r];
    }
     
    return res; 
}
void updateTreeS(vector<ll> &stree,ll n,int p, int value)
{
    stree[p+n] = value;
    p = p+n;
     
    for (int i=p; i > 1; i >>= 1)
        stree[i>>1] = stree[i] + stree[i^1];
}

void updateB(vector<ll> &bitree,vector<ll> &a,ll i,ll sum){         // 1 based indexing i=1 (first element)
    ll N=bitree.size();  //(n+1)
    a[i-1]=a[i-1]+sum;
    for(int k=i;k<N;k+=(k&(-k))){
        bitree[k]+=sum;
    }

}
ll sumB(vector<ll> &bitree,ll i){        //(5)arr[0...4] -> first five element
    ll ans=0;
    for(int k=i;k>0;k-=k&(-k)){
        ans+=bitree[k];
    }
    return ans;
}
void consB(vector<ll> &bitree,vector<ll> a){
    ll N=bitree.size();
    for(int i=1;i<N;i++){
        updateB(bitree,a,i,a[i-1]);
    }
}
int main(){
    FIO;
    ll t;cin>>t;
    while(t--){
       ll n;
       cin>>n;
       vector<ll> a(n);
       for(int i=0;i<n;i++){
           cin>>a[i];
       }
       vector<ll> bitree(n+1,0);
       consB(bitree,a);
       for(int i=1;i<=n;i++){
           cout<<bitree[i]<<" ";
       }cout<<endl;
       cout<<sumB(bitree,5)<<endl;;
       updateB(bitree,a,12,1);
        for(int i=0;i<n;i++){
           cout<<a[i]<<" ";
       }cout<<endl;
        for(int i=1;i<=n;i++){
           cout<<bitree[i]<<" ";
       }cout<<endl;
       
    }
    ll q;cin>>q;
    while(q--){
        ll n;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<ll> stree(2*n,0);

    }
    
    


   return 0;
}
