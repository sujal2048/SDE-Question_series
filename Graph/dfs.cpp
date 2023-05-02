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
void bfs(vector<vector<ll>> graph,vector<bool> &visited2,ll x){
    queue <ll> q;
    q.push(x);
    visited2[x]=true;
    while(!q.empty()){
        ll u=q.front();
        cout<<u<< " ";
        q.pop();
        for(auto v: graph[u]){
            if(!visited2[v]){
                q.push(v);
                visited2[v]=true;
            }
        }
    }
    cout<<endl;
}
void dfs(vector<vector<ll>> graph,vector<bool> &visited,ll u){
    cout<<u<<" ";
    visited[u]=true;
    for(auto v:graph[u]){
        if(visited[v]==false){
            dfs(graph,visited,v);
        }
    }
    return;
}
void dfsmain(vector<vector<ll>> graph,vector<bool> &visited,ll n){
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(graph,visited,i);
        }
    }
    cout<<endl;
    return;
}
int main(){
    FIO;
    ll n;cin>>n;

    vector<vector<ll>> graph(n+1,vector<ll> ());
    ll e;cin>>e;
    for(int i=0;i<e;i++){
        ll x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(n+1,false);
    //vector<bool> visited2(n+1,false);
    dfsmain(graph,visited,n);
    //bfs(graph,visited2,1);
    return 0;
}
