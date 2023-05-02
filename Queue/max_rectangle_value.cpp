#include<bits/stdc++.h>           //https://www.youtube.com/watch?v=hGl8Boeb7S4&t=49

using namespace std;
int get_max_area(vector<int> a){                //if it is increasing let it be but if it is decreasing then check the 
    int n=a.size(),ans=0,i=0;               //potential rectangle then further
    a.push_back(0);
    stack <int> st;
    while(i<=n){
        while(!st.empty() and a[st.top()] > a[i]){
              int t=st.top();
              int h=a[t];
              st.pop();
              if(st.empty()){
                  ans=max(ans,h*i);
              }
              else
              {
                  int len=i-st.top()-1;
                  ans= max(ans,h*len);
              }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main(){
    vector<int> a={2,1,3,2,5,6};
    cout<<get_max_area(a)<<endl;
    return 0;
}
//{2,1,2,,2,4,6,3,2,7,9,4}