#include<bits/stdc++.h>
using namespace std;
void countsort(int a[],int n){ //1,3,2,3,4,1,6,4,3
    int k=a[0];
    for(int i=0;i<n;i++){
        k=max(k,a[i]);         //k=6
    }
    int count[10]={0};         //we can not allocate dynamic memory to array;
    for(int i=0;i<n;i++){
       count[a[i]]++;          // 0 2 1 3 2 0 1 0 0 0 
    }
    for(int i=1;i<k+1;i++){    // 0 2 3 6 8 8 9 0 0 0 
       count[i]+=count[i-1];
    }
    int outputa[9];
    for(int i=n-1;i>=0;i--){        //i=0;i<n;i++
        outputa[--count[a[i]]]=a[i];
    }
     for(int i=0;i<n;i++){
       a[i]=outputa[i];
    }

}
int main(){
   int arr[]={1,3,2,3,4,1,6,4,3};
   countsort(arr,9);
     for(int i=0;i<9;i++){
         cout<<arr[i]<<" ";
     }

    return 0;
}
#include<bits/stdc++.h>

int countKAverageSubarrays(vector<int> &arr, int n, int k)
{
    int res = 0, currSum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        currSum += (arr[i] - k);
        if (currSum == 0)
            res++;
        if (mp.find(currSum) != mp.end())
            res += mp[currSum];
        mp[currSum]++;
    }
    return res;
}

int solution(vector<int> &A, int S) {
    int n = A.size();
    int res = countKAverageSubarrays(A, n, S);
    if(res>1000000000){res=1000000000;}    return res;
}