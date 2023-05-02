#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ll md=1000000000+7;
    ll t;cin>>t;
    vector<ll> ans(t,0);
    for(int i=0;i<t;i++){
        ll n;cin>>n;
        string s;cin>>s;
        vector<ll> x(n,0);
        vector<ll> un(n,0);
        vector<ll> o(n,0);
        vector<ll> curr(n,0);
        vector<ll> total(n,0);
        if(n==1){
            ans[i]=0;
            continue;
        }

        if(s[0]=='F'){
            un[0]=1;
        }
        else if(s[0]=='X'){
            x[0]=1;
        }
        else if(s[0]=='O'){
            o[0]=1;
        }

        for(int j=1;j<n;j++){
            if(s[j]=='F'){
                x[j]=x[j-1];
                un[j]=un[j-1]+1;
                o[j]=o[j-1];
                curr[j]=curr[j-1];
                total[j]=(total[j-1]%md+curr[j]%md)%md;
            }
            else if(s[j]=='X'){
                x[j]=x[j-1]+un[j-1]+o[j-1]+1;
                un[j]=0;
                o[j]=0;
                curr[j]=curr[j-1]+o[j-1];
                total[j]=(total[j-1]%md+curr[j]%md)%md;
            }
            else if(s[j]=='O'){
                x[j]=0;
                un[j]=0;
                o[j]=x[j-1]+un[j-1]+o[j-1]+1;
                curr[j]=curr[j-1]+x[j-1];
                total[j]=(total[j-1]%md+curr[j]%md)%md;
            }
             
        }
        ans[i]=total[n-1];
    }
    for(int i=0;i<t;i++){
        cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
    }
    return 0;
}