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
vector<ll> prefix_array(string s){           //tc=o(n)  https://www.youtube.com/watch?v=lhhqbGH7Pao
                                             //https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/tutorial/
    ll l=s.length();
    vector <ll> ans(l,0);

    for(int i=1;i<l;i++){
        ll j=ans[i-1];
        while(j>0 && s[i]!=s[j]){
            j=ans[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        ans[i]=j;
    }

    return ans;
}
void prelps(string s,vector<ll> &lps,ll m){
    lps[0]=0;
    int i=1;ll len=0;
    while(i<m){
        if(s[i]==s[len]){
            len++;lps[i]=len;i++;
        }
        else{
            if(len>0 ){
                len=lps[len-1];
            }
            else{
                lps[i]=0;i++;
            }
        }
    }
}
void countpat(string s,string pat){
    ll n=s.size();
    ll m=pat.size();
    vector<ll> lps(m);
    prelps(pat,lps,m);
    int i=0;int j=0;
    while(i<n){
        if(pat[j]==s[i]){
            i++;j++;
        }
        if(j==m){
            cout<<i-j<<" ";
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=s[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i=i+1;
            }
        }
    }
}

int main(){
    FIO;
    ll t;t=1;
    while(t--){
        string p,s;cin>>p>>s;
        string final=p+"@"+s;
        vector<ll> prefix=prefix_array(final);
        
        ll count=0;ll l=p.length();ll l2=final.length();
        for(int i=1;i<l2;i++){
            if(prefix[i]==l){
                count++;
            }
        }
        /*for(auto i:prefix){
            cout<<i<<" ";
        }cout<<endl;
        //p,s,prefix;
        ll pos=0;
        ll i=0,j=0;
        while(i<s.size()){
            if(s[i]==p[j]){
                i++;j++;
            }
            else{
                if(j!=0){
                    j=prefix[j-1];
                }
                else{
                    i++;
                }
            }
            if(j==p.size()){
                count++;
            }
        }*/
        cout<<count<<endl;
    }
    return 0;
}
