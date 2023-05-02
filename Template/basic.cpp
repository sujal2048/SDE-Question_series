#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
const int MOD = 1000000007;
#define all(x)          (x).begin(),(x).end()
#define rep(i,a,b)      for(ll i=a;i<b;i++)
#define ff              first
#define ss              second
#define YY              cout<<"Yes"<<endl
#define NN              cout<<"No"<<endl
ll power(ll a, ll b){
    ll res=1;a=a%MOD;
    while(b>0){
        if(b&1){
            res=(res*a)%MOD;b--;
        }
        a=(a*a)%MOD;b>>=1;}
    return res;
    }
const int No = 1e5+5;
vector<ll>  fact(No),invfact(No);
void init(){
    fact[0]=1;
    for(ll i=1;i<No;i++){fact[i]=i*fact[i-1]%MOD;}
    invfact[No-1]=power(fact[No-1],MOD-2);
    for(ll i=No-2;i>=0;i--){
        invfact[i]=(i+1)*invfact[i+1]%MOD;
    }
}
ll ncr(ll n,ll r,ll p){
    return (((fact[n]*invfact[n-r])%p)*invfact[r])%p;
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
const int N=1e7+1;
int spf[N+1]={0};
void primeSieve()
{
    
    for(int i=2;i<=N;i++)
    {
        spf[i]=i;
    }
    for(int i=2;i<=N;i++)
    {
        if(spf[i]==i)
        {
            for(int j=2*i;j<=N;j+=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }   
}
 
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

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
void solve(){
   
    
}
int main(){
    FIO;
    #ifndef ONLINE_JUDGE
		//freopen("input4.txt","r",stdin);
		//freopen("output2.txt","w",stdout);
		freopen("error2.txt","w",stderr);
		clock_t clk = clock();
	#endif
	//init_usaco();
    ll t;cin>>t;
    for(int q=1;q<=t;q++){
        //cout<<"Case #"<<q<<": ";
       solve();
      // pair<ll,ld> x=precisionCompute({31,0.23456});
      // cout<<x.first+x.second;
    }
    #ifndef ONLINE_JUDGE
	  	cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
	#endif
    
   return 0;
}
