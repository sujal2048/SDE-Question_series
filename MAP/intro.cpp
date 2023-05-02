#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll k,m;
        unordered_map<int,int> a;
      
        for(int i=0;i<n;i++){
          
          a[i+1]++;
         
        }
        a[3]++;
         unordered_map<int, int>:: iterator i;
        for(i=a.begin();i!=a.end();i++){
            cout<<i->first<<" "<<a[i->first]<<endl;
        }
    }
}
