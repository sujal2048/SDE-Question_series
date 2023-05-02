#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
bool is_positive(ll x){
    return x>0;
}
int main(){
    FIO;
    auto sum=[](ll x,ll y){return x+y;};    //just to define function in short way
    cout<<sum(4,5)<<endl;
    vector<ll> v={1,2,3};
    cout<<all_of(v.begin(),v.end(),[](ll x){return x>0;})<<endl;
    
    cout<<all_of(v.begin(),v.end(),is_positive)<<endl;      //if all is true then it is true
    cout<<any_of(v.begin(),v.end(),[](ll x){return x>0;})<<endl;   //if any is true then it is true 
    cout<<none_of(v.begin(),v.end(),[](ll x){return x>0;})<<endl;   //if all is false then only it is 1
    vector<pair<ll,ll>> vp={{1,2},{3,4},{5,6}};
    vector<pair<ll,ll> > :: iterator it;
    for(auto jt:vp){
        cout<<jt.first<<" ";
    }cout<<"yo"<<endl;
    for(it=vp.begin();it!=vp.end();it++){
        cout<<(*it).first<<" ";     //(*it).first==it->first
    }
    cout<<"bnm"<<endl;
    for(auto as:v){
        as++;    //as is a copy of original
    }
    for(auto as:v){
        cout<<as<<" ";
    }cout<<endl;
    for(auto &as:v){
        as++;    // as is original content
    }
    for(auto as:v){
        cout<<as<<" ";
    }cout<<endl;

   return 0;
}
