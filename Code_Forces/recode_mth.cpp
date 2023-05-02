#include<bits/stdc++.h>  //https://codeforces.com/group/nisINkUPNQ/contest/344953/problem/J
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
int bita(ll a){
    ll c=0;ll e=0;
    while(a){
        if(a&1==1){
            e++;
        }
        c++;
        a=a>>1;
    }
    if(e>1){
        return 1<<(c);
    }
    return 1<<(c-1);
}
int main(){
    ll n;cin>>n;
    if(n==1){
        cout<<1<<" "<<0;
        //cout<<bita(65);
        return 0;
    }
    vector<ll> p;
    vector<ll> a;ll iq=2;ll ans=1;
    while(n>1){
        if(n%iq==0){
            p.push_back(iq);ll count=0;ans*=iq;
            while(n%iq==0){
                count++;n=n/iq;
            }
            a.push_back(count);
        }
        iq++;
    }
   
    ll remain=1;ll tc=0;ll mx=0;
    while(mx/2!=1){
        bool z=true;
        mx=0;
        for(auto q:a){
            mx=max(mx,q);
            if(q%2!=0){
                z=false;
            }
        }
        if(z){
            if(mx==1){
                break;
            }
            for(int i=0;i<a.size();i++){
                a[i]=a[i]/2;
            }
            tc++;
            if(mx/2==1){
                break;
            }
        }
        else{
             if(mx==1){
                break;
            }
            if(mx%2!=0){
                mx++;
            }
            mx=bita(mx);
            for(int i=0;i<a.size();i++){
                a[i]=mx/2;
            }
            tc=tc+2;
        }
    }
    cout<<ans<<" "<<tc<<endl;
    
   return 0;
}
/*


#include < bits/stdc++.h >

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long 
int main() {

        ll n, jv=0, ans=1, n1;
	cin >> n;
	n1=n;
	
	for (int i=2;i<=n;i++)
	{
		if (n % i == 0) ans*=i;
		while (n % i==0) n/=i;
	}
	
	n=ans;
	
	while (n % n1) n*=n, jv++;
	if (n > n1) jv++;
	cout << ans <<" " << jv;

}

*/