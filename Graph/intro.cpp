/*#include<bits/stdc++.h>   
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


vector<bool> prim(20000+1,true);
void SieveOfEratosthenes(int n)
{
    for (int p = 2; p * p <= n; p++)
    {
        if (prim[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prim[i] = false;
        }
    }
}
void dfs(vector<vector<ll> > &a,ll u,vector<bool> &visited){
    visited[u]=true;
    for(auto v:a[u]){
        if(visited[v]==false){
            dfs(a,v,visited);
        }
    }
    return;
}
int main(){
    FIO;
    ll q;cin>>q;
    //SieveOfEratosthenes(20000);
    while(q--){
        ll n,m;cin>>n>>m;ll x,y,z;
        vector<vector<ll> > a(n+1,vector<ll> ());
        //vector<int> a[n+1];
        //vector<vector<pair<ll,ll> > >b(n+1,vector<pair<ll,ll>> ());
        for(int i=1;i<=m;i++){
            cin>>x>>y>>z;
            a[x].push_back(z);
            a[z].push_back(x);
        }
        vector<bool> visited(n+1,false);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(a,i,visited);
                if(i!=1){
                    a[1].push_back(i);
                    a[i].push_back(1);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(auto k:a[i]){
                if(i<k){
                  cout<<i<<" "<<k<<endl;
                }
            }
        }
    }
    return 0;
}*/
#include<bits/stdc++.h>
 
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define yy cout<<"Yes"<<endl;
#define nn cout<<"No"<<endl;
#define YY cout<<"YES"<<endl;
#define NN cout<<"NO"<<endl;
#define f(i,a,b) for(int i=a;i<b;i++)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define google(i,x) cout<<"Case #"<<i<<": "<<x<<endl
using namespace std;
 
const ll MOD=1e9+7;
int INF=1e7;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        vi v(n+1,0);
        f(i,0,m)
        {
            int a,b,c;
            cin>>a>>b>>c;
            v[b]=1;
        }
        int mark=1;
        f(i,1,n+1)
        {
            if(v[i]==0)
            {
                mark=i;
                break;
            }
        }
        f(i,1,n+1)
        {
            if(i!=mark)
            {
                cout<<mark<<" "<<i<<endl;
            }
        }
    }
}
  
