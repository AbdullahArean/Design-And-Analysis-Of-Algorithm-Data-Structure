#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int solve2(int n)
{
    dp.resize(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = 1* dp[i - 1] + (i- 1) * dp[i - 2];
    return dp[n];
}

int main()
{
    for (int n = 0; n < 15; n++)
    {

        cout << n << ":dp:  " << solve2(n) << "\n";
    }
}