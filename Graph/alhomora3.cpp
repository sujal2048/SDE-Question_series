#include <bits/stdc++.h>//https://discuss.codechef.com/t/greatsack-editorial/100569
using namespace std;
#define sub             freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
#define ll              long long
#define ttime           {cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';}
#define helpUs          template<typename T = ll , typename U = ll>
#define helpMe          template<typename T = ll>
#define pb              push_back
#define sz(x)           (int)((x).size())
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);
#define all(x)          (x).begin(),(x).end()

#define endl "\n"
#define int ll

typedef pair<ll,ll> pairll;
typedef map<ll,ll>  mapll;
typedef map<char,ll> mapch;
typedef vector<ll> vll;
//mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
helpUs class comp{public:bool operator()(T a, U b){return a>b;}};
helpUs istream& operator>>(istream& aa, pair<T,U> &p){aa>>p.ff>>p.ss;return aa;}
helpMe ostream& operator<<(ostream& ja, vector<T> &v){for(auto it:v)ja<<it<<" ";return ja;}
helpMe istream& operator>>(istream& aa, vector<T> &v){for(auto &it:v)cin>>it;return aa;}
helpUs ostream& operator<<(ostream& ja, pair<T,U> &p){ja<<p.ff<<" "<<p.ss;return ja;}



struct Solution{

    ll n,k,q;
    vector<vll> numTimes;
    vector<vll> divisors;
    vll values;
    vector<vll> adj;
    vll in, out;

    int tim=0;
    ll MAX = 200000; 

    void pre(){
        for(int i=1;i<=MAX;i++){
            int j=i;
            while(j<=MAX){
                divisors[j].pb(i);
                j+=i;
            }
        }
    }

    void dfs(int x, int p){
        
        in[x] = (++tim);
        int val = values[x];

        numTimes[val].push_back(in[x]);
        
        for(auto it:adj[x]){
            if(it != p){
                dfs(it,x);
            }
        }
        
        out[x] = tim;
    }

    int count(vector<int> &v, int t1, int t2){
        int cnt = upper_bound(all(v) , t2) - lower_bound(all(v) , t1);
        return cnt;
    }

    void solve(){

        divisors = vector<vll> (200001);
        pre();
        cin>>n>>q;

        numTimes = vector<vll> (MAX+1);
        values = vll(n+1);
        in = vll(n+1);
        out = vll(n+1);

        for(int i=1;i<=n;i++){
            cin>>values[i];
        }

        set<pairll> edges;
        set<int> xs;
        set<vll> qrs;

        adj = vector<vll> (n+1);
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);

        }

        dfs(1,0);

        int temp=q;

        while(temp--){
            
            int u,v,x;

            cin>>u>>v>>x;

            int cnt_u=0, cnt_v=0;

            for(auto it:divisors[x]){
                cnt_u += count(numTimes[it] , in[u] , out[u]);
                cnt_v += count(numTimes[it] , in[v] , out[v]);
            }

            if(cnt_u == cnt_v){
                cout<<"Draw"<<endl;
            }
            else if(cnt_u > cnt_v){
                cout<<u<<endl;
            }
            else{
                cout<<v<<endl;
            }
            cout<<"intime  ";
            for(auto q:in){
                cout<<q<<" ";
            }cout<<endl;
            cout<<"outtime  ";
            for(auto q:out){
                cout<<q<<" ";
            }cout<<endl;
            cout<<"numtime  ";
           for(auto q=0;q<=5;q++){
                for(auto w:numTimes[q]){
                    cout<<w<<" ";
                }cout<<endl;
            }cout<<endl;

        }

    }

};

           
signed main(){

    fast;
    ll t=1;

   // freopen("input.txt" , "r" , stdin);
   
    // clock_t clk = clock();
    
    Solution S;
    S.solve();
    
    // ttime;

    return 0;

}        