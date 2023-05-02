/*#include<bits/stdc++.h>           //https://www.youtube.com/watch?v=nDPo9hsDNvU&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=36
using namespace std;
void primsieve(int n){
    int prime[100]={0};
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }cout<<endl;
}
void primefactor(int n){
    int spf[100]={0};
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }

}
int main(){
    int n;
    cin>>n;
    primsieve(n);cout<<endl;
    primefactor(n);cout<<endl;
    return 0;
}*/
#include <bits/stdc++.h>                              //https://www.geeksforgeeks.org/count-divisors-n-on13/
using namespace std;
 
void SieveOfEratosthenes(int n, bool prime[],bool primesquare[], int a[])
{
    for (int i = 2; i <= n; i++)
        prime[i] = true;
    for (int i = 0; i <= (n * n + 1); i++)
        primesquare[i] = false;
 
    prime[1] = false;
 
    for (int p = 2; p * p <= n; p++) {           //prime[i]=true means i prime
        if (prime[p] == true) {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
    int j = 0;
    for (int p = 2; p <= n; p++) {        //a will have all prime number ..primesquare is true at square of prime
        if (prime[p]) {
            a[j] = p;
            primesquare[p * p] = true;
            j++;
        }
    }
}
 
int countDivisors(int n)
{
    if (n == 1)
        return 1;
    bool prime[1000 + 1], primesquare[1000 * 1000 + 1];   //n=1000
    int a[1000]; 
    SieveOfEratosthenes(n, prime, primesquare, a);
    int ans = 1;
    for (int i = 0;; i++) {
        if (a[i] * a[i] * a[i] > n)
            break;
        int cnt = 1; 
        while (n % a[i] == 0) 
        {
            n = n / a[i];
            cnt = cnt + 1;
        }
        ans = ans * cnt;
    }
    if (prime[n])
        ans = ans * 2;
    else if (primesquare[n])
        ans = ans * 3;
    else if (n != 1)
        ans = ans * 4;
    return ans; 
}
int main()
{
    cout << "Total distinct divisors of 100 are : " << countDivisors(100) << endl;
    return 0;
}