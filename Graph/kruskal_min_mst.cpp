#include<bits/stdc++.h>  // kruskal mst
using namespace std;
#define ll long long
#define ld long double//https://codeforces.com/contest/1670/problem/C
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

vector<bool> prim(20000+1,true);
void SieveOfEratosthenes(int n){
    for (int p = 2; p * p <= n; p++){
        if (prim[p] == true){
            for (int i = p * p; i <= n; i += p)
                prim[i] = false;}
    }}
pair<ll,ll> countDivisors(ll n)    //tc =n^1/2
{
    ll f=-1;
    ll cnt = 0;ll til=sqrt(n);
    for (int i = 1; i <= til; i++) {
        if (n % i == 0) {
            if(i>1){f=i;}
            if (n / i == i)
                cnt++;
            else 
                cnt = cnt + 2;
        }
    }
    pair<ll,ll> a={cnt,f};
    return a;
}
pair<ll,ld> precisionCompute(pair<ll,ld> x)
{
    ll p1=x.first;ld p2=x.second;
    if(p1%2==0){
        p1=p1/2;
        if(p2>=1){
            p2--;
            p2=(p2/2)+0.5;
        }
        else{
            p2=p2/2;
        }
    }
    else{
        p1=p1/2;
        if(p2>=1){
            p2--;
            p2=(p2/2)+0.5;
        }
        else{
            p2=p2/2;
        }
        if(p2>=0.5){
            p1++;
            p2-=0.5;
        }
        else{
            p2+=0.5;
        }
    }
    return {p1,p2};
}
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
bool compare(pair<ll,ld> p1,pair<ll,ld> p2)
{
    if(p1.first<=p2.first){
        return true;
    }
    return false;

}
ll ncp(ll n,ll p){
    ll u=1;
    for(int i=p+1;i<=n;i++){
        u=u*i;
    }
    ll d=1;
    for(int i=1;i<=(n-p);i++){
        d=d*i;
    }
    ll ans=u/d;
    return ans;
}
struct DSU {
  vector<ll> par, rnk, sz;
  DSU(ll n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  ll find(ll i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(ll i, ll j) {
    return find(i) == find(j);
  }
  ll get_size(ll i) {
    return sz[find(i)];
  }

  ll merge(ll i, ll j) {
    ll x = find(i) ; ll y = find(j); 
    if (rnk[x] > rnk[y]) swap(i, j);
    par[x] = y;
    sz[y] += sz[x];
    if (rnk[x] == rnk[y]) rnk[y]++;
    return y;
  }
};


void solve(){
    ll n,m;
    cin >> n>>m;
    vector<pair<ll,ll>> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    vector<pair<ll,ll>> p;
    for(int i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        p.push_back({x,y});
    }
    sort(a.begin(),a.end());
    vector<pair<ll,pair<ll,ll>>> rest;
    for(int i=1;i<n;i++){
        ll w=a[i+1].first-a[i].first;
        rest.push_back({w,{a[i].second,a[i+1].second}});
    }
    sort(rest.begin(),rest.end());vector<pair<ll,ll>> res;ll wt=0;
    DSU d(n);
    for(int i=0;i<m;i++){
        ll x=p[i].first;ll y=p[i].second;
        if(!d.same(x,y)){
            d.merge(x,y);
            res.push_back({x,y});
        }
    }
    for(int i=0;i<n-1;i++){
        ll w=rest[i].first;ll x=rest[i].second.first;ll y=rest[i].second.second;
        if(!d.same(x,y)){
            d.merge(x,y);
            res.push_back({x,y});
            wt+=w;
        }
    }
    cout<<wt<<" "<<res.size()<<endl;
    for(auto i:res){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return ;    
}


int main(){
    FIO;
    ll t;cin>>t;
    for(int q=1;q<=t;q++){
        //cout<<"Case #"<<q<<": ";
       solve();
      // pair<ll,ld> x=precisionCompute({31,0.23456});
      // cout<<x.first+x.second;

    }
   return 0;
}
