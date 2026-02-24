#include<bits/stdc++.h>
using namespace std;
ll dist(ll x1,ll x2,ll y1,ll y2)
{
    
    if(abs(x1-x2)==abs(y1-y2)){
        return 1;
    }
    if(x1==x2 || y1==y2){
        return 1;
    }
    return 2;
}
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> a(n);
        vector<ll> b(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        ll mn=0;ll final=2*(n-1);
            for(ll i=0;i<n;i++)
            {  
                for(ll k=0;k<n;k++)
                {
                   
                    for(ll j=0;j<n;j++){
                             mn+=dist(a[i],a[j],b[k],b[j]);    // x1,x2,y1,y2   poll=x1,y1 yup
                    } 
                    final=min(final,mn);mn=0;
                    for(ll j=0;j<n;j++){
                             mn+=dist(a[k],a[j],b[i],b[j]);    // x1,x2,y1,y2   poll=x1,y1 yup
                    }
                    final=min(final,mn);mn=0;
                    for(ll j=0;j<n;j++){
                             mn+=dist(a[k],a[j],a[k]+b[i]-a[i],b[j]);    // x1,x2,y1,y2   poll=x1,y1//1 yup
                    } 
                    final=min(final,mn);mn=0;
                    for(ll j=0;j<n;j++){
                             mn+=dist(a[i],a[j],a[i]+b[k]-a[k],b[j]);    // x1,x2,y1,y2   poll=x1,y1//1 yup
                    } 
                    final=min(final,mn);mn=0;
                    for(ll j=0;j<n;j++){
                             mn+=dist(((a[k]+b[k]-b[i]+a[i])/2),a[j],((a[k]+b[k]+b[i]-a[i])/2),b[j]);// x1,x2,y1,y2 poll=x1,y1  //diag-diaag
                    } 
                    final=min(final,mn);mn=0;
                    for(ll j=0;j<n;j++){
                             mn+=dist((a[i]+b[i]-b[k]+a[k])/2,a[j],(a[i]+b[i]+b[k]-a[k])/2,b[j]);    // x1,x2,y1,y2 //diag-diag
                    } 
                    final=min(final,mn);mn=0;
                   
                     for(ll j=0;j<n;j++){
                             mn+=dist(b[k]+a[k]-b[i],a[j],b[i],b[j]);// x1,x2,y1,y2 poll=x1,y1  //diag-diaag//y2
                    } 
                    final=min(final,mn);mn=0;
                    for(ll j=0;j<n;j++){
                             mn+=dist(b[i]-b[k]+a[k],a[j],b[i],b[j]);// x1,x2,y1,y2 poll=x1,y1  //diag-diaag//y3
                    } 
                    final=min(final,mn);mn=0;
                    
                    
                    
                   
                }
            }
            cout<<final<<endl;
    }
    ll as=5;
    ll ad=as/2;
    cout<<ad;
    return 0;
}
