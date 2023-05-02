#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
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
void precisionCompute(ll x, ll y, int n)
{
    if (y == 0) {cout << "Infinite" << endl;return;}
    if (x == 0) {cout << 0 << endl;return;}
    if (n <= 0) {cout << x / y << endl;return;}
    if (((x > 0) && (y < 0)) || ((x < 0) && (y > 0))) {cout << "-";x = x > 0 ? x : -x;y = y > 0 ? y : -y;}
    int d = x / y;
    for (int i = 0; i <= n; i++) {cout << d;x = x-(y*d);if(x == 0)break;x = x*10;d = x / y;if(i == 0)cout<<".";}
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
ll dfs(ll curr,ll n,vector<ll> &infected,vector<ll> &caninfect,vector<vector<pair<ll,ll>>> road,vector<ll> &vis){
    vis[curr]=1;
    ll count=1;
    for(auto child:road[curr]){
        if(infected[curr] && (child.second==0) ){
            infected[child.first]=1;
        }
        if(vis[child.first]==1){continue;}
        ll res=dfs(child.first,n,infected,caninfect,road,vis);
        if(infected[curr] && (child.second==1) ){
            caninfect.push_back(res);
        }
        count+=res;
        }
    return count;
}
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
void countsub(ll node,ll par,vector<vector<ll> > &tree,vector<ll> &cnt){
    for(auto i:tree[node]){
        if(i!=par){
            countsub(i,node,tree,cnt);
            cnt[node]+=cnt[i];
        }
    }
    return;
}
void dfs(ll node,ll par,vector<vector<ll> > &tree,vector<ll> &cnt,vector<ll> &dp){
    vector<ll> adj;
    for(auto i:tree[node]){
        if(i!=par){
            dfs(i,node,tree,cnt,dp);
            adj.push_back(i);
        }
    }
    if(adj.size()==0){
        dp[node]=0;
    }
    else if(adj.size()==1){
        dp[node]=cnt[adj[0]]-1;
    }
    else{
        dp[node]=max(dp[node],cnt[adj[0]]-1+dp[adj[1]]);
        dp[node]=max(dp[node],cnt[adj[1]]-1+dp[adj[0]]);
    }
    return ;

}
void solve(){
    ll n;cin>>n;
    vector<vector<ll> > tree(n+1);
    vector<ll> cnt(n+1,1),dp(n+1,0);
    for(int i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    tree[1].push_back(0);
    tree[0].push_back(1);
    countsub(1,0,tree,cnt);
    dfs(1,0,tree,cnt,dp);
    cout<<dp[1]<<endl;

  
  
}
int main(){
    FIO;
    ll w;cin>>w;
    while(w--){
        solve();
    }
   return 0;
}
