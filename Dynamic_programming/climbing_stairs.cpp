#include<bits/stdc++.h>        //https://www.youtube.com/watch?v=3rDA1D_qGEY
using namespace std;           //no of way a man can climb n stairs if can take only one or two step
int main(){                    //iterative approach using dynamic programming
    int n;cin>>n;              //bottom to top approach
    int a[100]={0};                    //optimal substructure
     a[0]=1;                              //overlaping subproblem
     a[1]=1;
     for(int i=2;i<=n;i++){
         a[i]=a[i-1]+a[i-2];
     }
     cout<<a[n]<<endl;
}