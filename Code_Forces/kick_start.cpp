#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;cin>>t; ll d,n,k; ll mx=0;ll tmx=0; ll x,y,z;vector<vector<ll> > day(1000,vector<ll> (10,0));vector<ll> temp(d+1,0);
    for(int q=1;q<=t;q++){
        cin>>d>>n>>k;
        for(int i=0;i<d;i++){
            day[i][0]=0;day[i][1]=0;temp[i]=0;
        }
        temp[d]=0;
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            temp[y]+=x;
            if(z<d){
                temp[z+1]+=-x;
            }
            for(int j=y;j<=z;j++){
                day[j-1][1]++;
                day[j-1][1+day[j-1][1]]=x;      //day[j][1]
            }
        }
        day[1-1][0]=temp[1];
        for(int i=2;i<=d;i++){
            day[i-1][0]=day[i-1-1][0]+temp[i];
        }
        
        mx=0;tmx=0;
        for(int i=1;i<=d;i++){
            if(day[i-1][0]>=mx){
                if(day[i-1][1]<=k){
                    mx=day[i-1][0];
                }
                else{
                    sort(day[i-1].begin()+2,day[i-1].begin()+1+day[i-1][1]+1,greater<ll>());
                    tmx=0;
                    for(int w=1;w<=k;w++){
                        tmx=tmx+day[i-1][1+w];
                    }
                    if(tmx>mx){
                        mx=tmx;
                    }
                }
            }            
        }
        cout<<"Case #"<<q<<": "<<mx<<endl;
       
    }
    
    return 0;
}
/*
bool compare(pair<ll,pair<ll,ll>> p1,pair<ll,pair<ll,ll>> p2){
    
    return p1.first>p2.first;
}

int main(){
    ll t;cin>>t;
    for(ll q=1;q<=t;q++){
        ll d,n,k;cin>>d>>n>>k;
        vector<pair<ll,pair<ll,ll>>> a(n,pair<ll,pair<ll,ll>> () );
        for(int i=0;i<n;i++){
            cin>>a[i].first>>a[i].second.first>>a[i].second.second;
        }
        sort(a.begin(),a.end(),compare);ll tk=0;ll counter=0;ll tans=0;ll ans=0;
        for(int i=1;i<=d;i++){
            tk=0;counter=0;tans=0;
            while(tk<k && counter<n){
                if(a[counter].second.first<=i && a[counter].second.second>=i){
                    tans+=a[counter].first;
                    tk++;
                }
                counter++;
            }
            if(tans>=ans){
                ans=tans; 
            }
        }
        cout<<"Case #"<<q<<": "<<ans<<endl;
    }
    return 0;
}

int main(){
    ll t;cin>>t;
    for(ll q=1;q<=t;q++){
        ll d,n,k;cin>>d>>n>>k;
        vector<pair<ll,pair<ll,ll>>> a(n,pair<ll,pair<ll,ll>> () );
        for(int i=0;i<n;i++){
            cin>>a[i].first>>a[i].second.first>>a[i].second.second;
        }
        sort(a.begin(),a.end(),compare);ll tk=0;ll counter=0;ll tans=0;ll ans=0;
        multiset<ll> m,n;
        for(int i=1;i<=d;i++){


        }
        cout<<"Case #"<<q<<": "<<ans<<endl;
    }
    return 0;
}*/