#include<bits/stdc++.h>
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> a(n);
        vector<ll> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b.begin(),b.end());
        ll bg=0;ll sm=0;ll me=0;ll nme=1;
        if(k%2==0){
            ll x=k/2;
            bg=k/2;
            sm=k/2-1;
            me=b[n-1-x];
            cout<<b[n-1-x]<<endl;
        }
        else{
            ll x=k-(k/2);
            bg=k/2;
            sm=bg;
            me=b[n-x];
            cout<<me<<endl;
        }
        for(int i=0;i<n;i++){
            if(a[i]==me && nme){
                nme--;
                cout<<a[i]<<" ";
            }
            else if(a[i]<=me){
                if(sm){
                    sm--;
                    cout<<a[i]<<" ";
                }
            }
            else if(a[i]>=me){
                if(bg){
                    bg--;
                    cout<<a[i]<<" ";
                }
            }
            if(nme==0 && bg==0 && sm==0){
                break;
            }
        }
        cout<<endl;
    }
    return 0;
} 
