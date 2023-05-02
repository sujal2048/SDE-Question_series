//    study  -> https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
//    https://atcoder.jp/contests/dp/tasks/dp_e
//    https://atcoder.jp/contests/dp/tasks/dp_d
//    max_size=178956970 of vector;
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
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main(){
    FIO;
    ll n,w;cin>>n>>w;
    vector<vector<ll>> a(n,vector<ll> (2,0));
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    /* dp approach TC=N*W
                   SC=N*W

    vector<vector<ll>> dp(n+1,vector<ll> (w+1,0));     
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(a[i-1][0]<=j){
                dp[i][j]=max(a[i-1][1]+dp[i-1][j-a[i-1][0]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w]<<endl;*/
    // DP Approach TC=N*W
    //             SC=W;
    
    /*   vector<ll> dp2(w+1,0);
        for(int i=1;i<=n;i++){
        for(int j=w;j>=0;j--){
            if(a[i-1][0]<=j){         //cond so that dp do not go outside  or invalid set;
                dp2[j]=max(dp2[j],a[i-1][1]+dp2[j-a[i-1][0]]);
            }
        }
    }                                                                                            
    cout<<dp2[w]<<endl;*/
    // changing the state with optimize space complexity;
    vector<ll> dp3(100001,1e10);      //dp[V][i] represents the minimum weight subset of the subarray arr[i…N-1] 
    dp3[0]=0;                         //required to get a value of at least V. The recurrence relation will be:
    for(int i=0;i<n;i++){
        ll wei=a[i][0];
        ll val=a[i][1];
        for(int j=100000;j>=val;j--)
            dp3[j]=min(dp3[j],dp3[j-val]+wei);
    }
    for(int i=100000;i>=0;i--){
        if(dp3[i]<=w){ 
            cout<<i<<endl;
            break;
        }
    }
    
    
    return 0;
}
//more question:
//https://www.codechef.com/START22B/problems/MERGEBS  dp