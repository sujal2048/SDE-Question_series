//https://atcoder.jp/contests
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n;
    cin >> n;
 
    vector<vector<int>> ip(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++)
    {
        cin >> ip[i][0] >> ip[i][1] >> ip[i][2];
    }
 
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[1][0] = ip[1][0];
    dp[1][1] = ip[1][1];
    dp[1][2] = ip[1][2];
 
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(ip[i][0] + dp[i - 1][1], ip[i][0] + dp[i - 1][2]);
        dp[i][1] = max(ip[i][1] + dp[i - 1][0], ip[i][1] + dp[i - 1][2]);
        dp[i][2] = max(ip[i][2] + dp[i - 1][0], ip[i][2] + dp[i - 1][1]);
    }
 
    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << endl;
    return 0;
}
