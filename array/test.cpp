#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;cin>>t;
    while(t--){
        ll n,x,y,k;
        cin>>n>>x>>y>>k;
        vector<int> a(n);
        for(auto &i: a){
            cin>>i;
        }
        
        sort(a.begin(),a.end());
        ll ans=1;
        vector<ll> b(1000000001,0);
        b[a[0]]=1;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1] && b[i]==0){
                b[a[i]]=1;
                ans++;
            }
            else{
                int count=x;
                while(count<=y){
                    if(b[count]==0){
                        b[count]=1;
                        ans++;
                    }
                }
                }
            }
        }
    }

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define SYNC std::ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
 
//typedef    long long            ll;
typedef     long double      ld;
typedef    vector<ll>           vi; 
typedef    pair<ll,ll>          ii; 
 
#define    pb                   push_back 
#define    mp                   make_pair
#define    all(c)               (c).begin(),(c).end() 
#define    ff           first
#define    ss           second
//typedef tree<int, null_type, less<int>, rb_tree_tag,
//             tree_order_statistics_node_update>
//    ost;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template <typename T, typename V>
void __print(pair<T, V> x);
template<typename C, typename T = typename C::value_type>
void __print(C x);
template <typename T>
void __print(const T a[]);
template <typename T, typename V>
void __print(pair<T, V> x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename C, typename T = typename C::value_type>
void __print(C x) {int f = 0; cerr << '{'; for (auto i: x) cerr << (f++ ? "," : ""),__print(i) ; cerr << "}";}
template <typename T>
void __print(const T a[]) { cerr << "\n{"; for(int i = 0; i < 10; i++){ __print(a[i]);cerr << ","; } cerr <<  " ... }\n"; }
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
//#define debug(x...) cerr << "Line " << __LINE__ << ": [" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
#define     int           long long
const ll MOD = 1e9+7;
const ll MOD1 = 998244353;
const ll N = 2e5+5;
const ll INF = 3e9;
const ll BIG_INF = 3e18;
const ld EPS = 1e-12;
const ld PI = 3.141592653589793116;

void solve(int tc){
    ll n,x,y,k;
    cin>>n>>x>>y>>k;
    set<ll> st,tot;
    vi v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
        if(v[i] >= x && v[i] <= y){
            st.insert(v[i]);
        }
        tot.insert(v[i]);
    }

    ll filled = st.size();
    ll left = y - x + 1 - st.size();

    left = min(left,k);
    ll ans = min(n,(ll)tot.size() + left);
    cout<<ans<<"\n";
}

int32_t main()
{
  SYNC   //Disable on interactive problems

  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif // ONLINE_JUDGE
 
    ll t=1;
    int tc = 1;
    cin>>t;
    while(t--){
      solve(tc++);
    }
 
    //cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
  return 0;
}