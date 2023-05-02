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
string max(string a,string b){
    if(a.length()>b.length()){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    FIO;
    string m,n;cin>>m>>n;
    ll s=m.length();ll t=n.length();
    string ans="";
    //ll l=min(m.length(),n.length());
    /*vector<vector<ll> > dp(s+1,vector<ll> (t+1,-1));
    for(int i=0;i<=s;i++){
        for(int j=0;j<=t;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(m[i-1]==n[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }*/
    vector<vector<string> > dp2(s+1,vector<string> (t+1,""));
    for(int i=0;i<=s;i++){
        for(int j=0;j<=t;j++){
            if(i==0 || j==0){
                dp2[i][j]="";
            }
            else if(m[i-1]==n[j-1]){
                dp2[i][j]=dp2[i-1][j-1]+m[i-1];
            }
            else{
                dp2[i][j]=max(dp2[i][j-1],dp2[i-1][j]);
            }
        }
    }
    cout<<dp2[s][t]<<endl;
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define ff first
#define ss second
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
string s, t;
int dp[3005][3005];
int rec(int l, int r, int p, int q)
{           
    if ((l == p) || (r == q))
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    int ans = 0;
    if (s[l] == t[r])
        ans = max(ans, 1 + rec(l + 1, r + 1, p, q));
    else
        ans = max(rec(l + 1, r, p, q), rec(l, r + 1, p, q));
    return dp[l][r] = ans;
}
string ans = {};
void generate(int l, int r, int p, int q)
{
    if ((l == p) || (r == q))
        return;
    if (s[l] == t[r])
    {
        ans += s[l];
        generate(l + 1, r + 1, p, q);
    }
    else if (rec(l + 1, r, p, q) > rec(l, r + 1, p, q))
        generate(l + 1, r, p, q);
    else
        generate(l, r + 1, p, q);
}
signed main()
{
    fast
            cin >>
        s >> t;
    memset(dp, -1, sizeof(dp));
    int n = s.size();
    int m = t.size();
    generate(0, 0, n, m);
    cout << ans << "\n";
    return 0;
}
*/