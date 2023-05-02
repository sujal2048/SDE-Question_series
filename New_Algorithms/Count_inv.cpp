#include<bits/stdc++.h>           //https://www.youtube.com/watch?v=NOykDuH1_OY
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
void update(vector<ll> &bitree,ll i,ll sum){         // 1 based indexing i=1 (first element)
    ll N=bitree.size();  //(n+1)
   // a[i-1]=a[i-1]+sum;
    for(int k=i;k<N;k+=(k&(-k))){
        bitree[k]+=sum;
    }

}
ll sum(vector<ll> &bitree,ll i){        //(5)arr[0...4] -> first five element
    ll ans=0;
    for(int k=i;k>0;k-=k&(-k)){
        ans+=bitree[k];
    }
    return ans;
}
void consbit(vector<ll> &bitree,vector<ll> a){
    ll N=bitree.size();
    for(int i=1;i<N;i++){
        update(bitree,i,a[i-1]);
    }
}

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int main(){
    FIO;
    ll t;cin>>t;
    while(t--){
        ll  n;cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        map<ll,ll> m;                         // just to map the element of a[i]
        for(int i=0;i<n;i++){                 //  if they are of range 10^9       
           m[a[i]]=0;                           //then we cannot create array of size 10^9
        }                                     // so we mapping the distant element to be in range 
        ll index=1;                           //
        for(auto &i:m){                        //  
            i.second=index;                   //       
            index++;                          //      
        }                                     //              
         for(int i=0;i<n;i++){                //               
           a[i]=m[a[i]];                      //  
        }                                     //   
        vector<ll> bitree(100000,0);
        ll count=0;
        for(int i=0;i<n;i++){
            count+=sum(bitree,99999)-sum(bitree,a[i]);
            update(bitree,a[i],1);
        }
        cout<<count<<endl;
        
    }
    
    


   return 0;
}
