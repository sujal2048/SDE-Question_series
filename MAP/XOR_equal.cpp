#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll k,m;

        unordered_map<ll,ll> a;
        unordered_map<ll,ll> b;
        if(x==0){
          for(ll i=0;i<n;i++){
          cin>>k;
          a[k]++;
          }
          unordered_map<ll, ll>:: iterator q;
          ll as=0;
          for(q=a.begin();q!=a.end();q++){
               
                   as=max(as,q->second);
          }
          cout<<as<<" "<<0<<endl;
        }
        else{
        for(ll i=0;i<n;i++){
          cin>>k;
          a[k]++;m=k^x;
          b[m]++;
        }

        ll mx1=0;ll mx2=0;
        unordered_map<ll, ll>:: iterator i;
        for(i=a.begin();i!=a.end();i++){
          if (a.find(i->first)!=a.end() && b.find(i->first)!=b.end() )
          {
             if((a[i->first]+b[i->first]>=(mx1+mx2))){
               if((a[i->first]+b[i->first]==(mx1+mx2))){
                mx2=min(mx2,b[i->first]);
                mx1=max(mx1,a[i->first]);
               }
               else{
                mx1=a[i->first];
                mx2=b[i->first];
               }
            }
          }
          else if(a.find(i->first)!=a.end() ){
            if(a[i->first] >=(mx1+mx2) ){
              mx1=a[i->first];
              mx2=0;
            }
          }
          else if(b.find(i->first)!=b.end() ){
            if(b[i->first] >(mx1+mx2) ){
              mx1=0;
              mx2=b[i->first];
            }
          }
        }

        for(i=b.begin();i!=b.end();i++){
          if (a.find(i->first)!=a.end() && b.find(i->first)!=b.end()  )
          {
             if((a[i->first]+b[i->first]>=(mx1+mx2))){
               if((a[i->first]+b[i->first]==(mx1+mx2))){
                mx2=min(mx2,b[i->first]);
                mx1=max(mx1,a[i->first]);
               }
               else{
                mx1=a[i->first];
                mx2=b[i->first];
               }
            }
          }
          else if(a.find(i->first)!=a.end() ){
            if(a[i->first] >=(mx1+mx2) ){
              mx1=a[i->first];
              mx2=0;
            }
          }
          else if(b.find(i->first)!=b.end() ){
            if(b[i->first] >(mx1+mx2) ){
              mx1=0;
              mx2=b[i->first];
            }
          }
        }
        
        cout<<mx1+mx2<<" "<<mx2<<endl;
    }
    }
    return 0;
}