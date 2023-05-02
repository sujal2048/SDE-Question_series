#include<bits/stdc++.h>          //https://www.youtube.com/watch?v=BsPbCLj4_Mw&t=34s
using namespace std;             //brute force     A=..... l=......  R=.......   MIN(L,R)=.....    ANS=max(MIN(L,R)-A,0) =..... <-final ans
int rain_water(vector <int> a){
    int n=a.size();
    int ans=0;
    stack <int> st;
                           
    for(int i=0;i<n;i++){
      while(!st.empty() and a[st.top()]<a[i]){
          int cur = st.top();
          st.pop();
          if(st.empty()){
              break;
          }
          int diff=i-st.top()-1;
          ans+=(min(a[st.top()],a[i])-a[cur])*diff;
      }
      st.push(i);
    }
    return ans;
}
int main(){
    vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rain_water(a);
    
    return 0;
}