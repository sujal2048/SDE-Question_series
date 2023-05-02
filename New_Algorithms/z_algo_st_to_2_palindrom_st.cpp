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


 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

vector<ll> z_function(string s) {
    ll n =  s.length();
    vector<ll> z(n);
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min ((r - i + 1), z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
void solve()
    {
        ll n;string s;
        cin >> n;
        cin>>s;
        string str1,str2;
        string rev = s;
        reverse(all(rev));
        str1 = s + '?' + rev;
        str2 = rev + '?' + s;
        vector<ll> v_pref,v_suff;
        v_pref = z_function(str1);
        v_suff = z_function(str2);
        vector<bool>found(n,false);
        for(int i=0;i<=n-1;i++)
        {
            if(v_suff[i] == n - i)
            {
                found[i] = true;
            }
        }
        ll min_len = n;
        for(int i=0;i<=n-1;i++)
        {
            if(v_pref[i] == n - i and found[n-i])
            {

                min_len = min(min_len,n - i);
            }
        }
        string add = "";
        for(int i=1;i<=min_len;i++)
        {
            add+=s[i-1];
        }
        reverse(all(add));
        cout<<add<<"\n";
        return ;
    }
int main(){
    FIO;
    ll t=1;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}







