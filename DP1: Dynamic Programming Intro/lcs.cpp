#include <bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int lcs_rec(string s1, string s2, int i = 0, int j = 0)
{
    if (i >= s1.length() || j >= s2.length())
        return 0;
    else if (s1[i] == s2[j])
        return 1 + lcs_rec(s1, s2, i + 1, j + 1);
    else
        return max(lcs_rec(s1, s2, i + 1, j), lcs_rec(s1, s2, i, j + 1));
}
int lcs_memo(string s1, string s2, int i = 0, int j = 0)
{
    if (i == 0 && j == 0)
    {
        int n = s1.length();
        int m = s2.length();
        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= m + 1; j++)
            {
                dp[i][j] = -1;
            }
        }
    }
    if (i >= s1.length() || j >= s2.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    else if (s1[i] == s2[j])
        dp[i][j] = 1 + lcs_memo(s1, s2, i + 1, j + 1);
    else
        dp[i][j] = max(lcs_memo(s1, s2, i + 1, j), lcs_memo(s1, s2, i, j + 1));
    return dp[i][j];
}
int lcs_tabu(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
int main()
{
    cout << lcs_rec("abdacbab", "acebfa") << "\n";
    cout << lcs_memo("abdacbab", "acebfa") << "\n";
    cout << lcs_tabu("abdacbab", "acebfa") << "\n";
}