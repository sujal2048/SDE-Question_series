#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fr(i,x,n) for(long long int i=n-1;i>=x;i--)
#define pb push_back
#define mod 1000000007
#define endl '\n'
#define ff first
#define ss second

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};

ll dp[100005][2];
ll n;
vll v(100005);

ll solve(int id,int prev){

    /* prev = 0 --> equal from prev
       prev = 1 --> unequal from prev
    */

   if(id == n-1){
       if(prev == 0){
           return 1;
       }
       else{
           return (100000 - v[id-1]);
       }
   }

    if(dp[id][prev] == -1){

        ll ans = 0;

        if(prev == 0){
            if(v[id -1] < v[id]){
                ans = 0;
            }
            else if(v[id - 1] > v[id]){
                ans = solve(id+1,0)%mod;
            }
            else{
                ans = (solve(id + 1,1)%mod + solve(id + 1,0)%mod)%mod;
            }
        }
        else{

            if(id == 0){
                ans = (((solve(id + 1,0)%mod)*(100000 - v[id] + 1))%mod + solve(id + 1,1)%mod)%mod;
            }
            else if(v[id] > v[id-1]){
                ans = (((solve(id + 1,0)%mod)*(100000 - v[id] + 1))%mod + solve(id + 1,1)%mod)%mod;
            }
            else if(v[id] <= v[id -1]){
                ans = (((solve(id + 1,0)%mod)*(100000 - v[id-1]))%mod)%mod;
            }
            
        }

        dp[id][prev] = ans;

    }

    return dp[id][prev];


}

int main(){
    fast_io

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t; cin >> t;

    while(t--){

        cin >> n;

        f(i,0,n-1) cin >> v[i];

        memset(dp,-1,sizeof(dp));

        cout << solve(0,1)%mod << endl;

    }

    

    

       


    return 0;
}
