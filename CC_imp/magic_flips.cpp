#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        vector <ll> a(n);
        vector <ll> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        vector<int> s(n,0);
        
        ll ans=0;ll card=0;ll card2=0;
        for(int i=29;i>=0;i--){
            vector<int> flip;
            bool result=true;
            for(int j=0;j<n;j++){
                ll ac=0;ll bc=0;
                if(a[j]&1<<i){
                    ac=1;
                }
                if(b[j]&1<<i){
                    bc=1;
                }
                if(s[j]==0){
                    if(ac==1 && bc==0){
                        s[j]=1;flip.push_back(j);

                    }
                    else if(ac==0 && bc==1){
                        s[j]=2;flip.push_back(j);card2++;card++;

                    }
                    else if(ac==0 && bc==0){
                         result=false;
                         break;
                    }
                }
                else{
                   if(s[j]==1){
                       if(ac==0){
                          result=false;
                          break;
                       }
                   }
                   else{
                       if(bc==0){
                           result=false;
                           break;
                       }
                   }
                }

            }
            if(result){
              ans=ans+(1<<i);
              card2=0;
            }
            else{
                for(auto q:flip){
                    s[q]=0;
                }
                card=card-card2;
                card2=0;
            }
        }
        cout<<ans<<" "<<card<<endl;

    }
    return 0;
}
