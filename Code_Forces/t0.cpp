#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
ll bfs(vector<vector<ll>> &a,vector<bool> &temp,ll c){
    queue<ll> q;
    q.push(c);
    if(temp[c])
     return c;
    else{
    while(q.empty()){
        ll top=q.front();
        q.pop();
        for(auto z:a[top]){
            q.push(z);
        }
        for(int i=q.front();;){


        }

    }
    }
}
int main(){
    FIO;
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<vector<ll>> v(n+1);  //undirected graph
        for(int i=1;i<n;i++){
            ll a,b;cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<vector<ll>> a(n+1);   // directed tree;
        vector<bool> conn(n+1,true);
        for(int i=1;i<n;i++){
            for(auto z:v[i]){
                if(conn[i] && conn[z])
                   a[i].push_back(z);
            }
            conn[i]=false;
        }
        vector<bool> temp(n+1,false);
        ll q;cin>>q;
        for(int i=1;i<=n;i++){
            ll c;cin>>c;
            ll ans=bfs(a,temp,c);
            temp[c]=true;
            if(ans){
                cout<<"YES "<<ans<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }

    }
    return 0;
}
