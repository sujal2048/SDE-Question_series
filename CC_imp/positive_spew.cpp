#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ll t;cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> a(n,0);
        ll o=0;ll plus=0;ll ans=0;
        vector<ll> indx;
        vector<ll> tindx;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>0){
                plus++;
                indx.push_back(i);
            }
            else{
                o++;
            }
            ans+=a[i];
        }
        if(o==n){
            cout<<0<<endl;
        }
        else if(k==0){
            cout<<ans<<endl;
        }
        else{
            while(k>0 && plus<n){
               // cout<<indx.size()<<" ";
                for(int j=0;j<indx.size();j++){
                    //a[index[j]]
                    ll before=indx[j]-1;
                    if(before==-1){
                        before=n-1;
                    }
                    ll after=indx[j]+1;
                    after=after%n;
                    if((a[before]==0)){
                     plus++;
                     tindx.push_back(before);
                    }
                    if((a[after]==0)){
                     plus++;
                     tindx.push_back(after);
                    }
                    a[before]++;
                    a[after]++;
                    ans+=2;
                }
                for(int q=0;q<tindx.size();q++){
                    indx.push_back(tindx[q]);
                }
                ll w=tindx.size();
                for(int q=0;q<w;q++){
                    tindx.pop_back();
                }

                k--;
            }
            ans=ans+(2*n*k);
            cout<<ans<<endl;
            
        }
    }
   
    return 0;
}