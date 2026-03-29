#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    vector<int> dict(256,-1);
    int maxlen=0,start=-1;
    for(int i=0;i<s.size();i++){
          start=dict[s[i]];
        maxlen = max(maxlen,i-start);
    }
    cout<<maxlen;
    return 0;
}
