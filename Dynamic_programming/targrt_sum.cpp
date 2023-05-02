#include<bits/stdc++.h>      //https://www.youtube.com/watch?v=bzk4KHuTuBc&t=186s
using namespace std;         //basic and recursive approach becoz many overlapping sub problem is formed
int total=0;                 //apply DP
void target(vector<int> &a,int s,int t,int i){
    if(i==a.size()){
        if(t==s)
         total++;
    }
    else{
        target(a,s,t-a[i],i+1);
        target(a,s,t+a[i],i+1);
    }
}
int findtarget(vector<int> & nums,int s){
    if(s>1000)
      return 0;
    int limitsum=2001;   //-1000..0...+1000
    int origin=1000;
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(limitsum,0));      //kind of 2D vector  row=n+1;column=limtsum;==0 //
    dp[0][0+origin]=1;                 // column = 0...2000    ->  origin=1000  //row = 0...n
    for(int i=1;i<=n;i++){             //this approach is better becoz limitsum is constant therefore.. time=o(n);
        for(int t=0;t<limitsum;t++){
            if(dp[i-1][t] > 0){
                dp[i][t+nums[i-1]]+=dp[i-1][t];
                dp[i][t-nums[i-1]]+=dp[i-1][t];
            }
        }
    }
    return dp[n][s+origin];
}
int main(){
    vector<int> a={5,2,1,5,8,4,9};
    int s=6;
    target(a,s,0,0);
    cout<<total<<endl;
    cout<<findtarget(a,s);
    return 0;
}