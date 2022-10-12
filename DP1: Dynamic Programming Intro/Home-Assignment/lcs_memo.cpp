#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int dp[10000][10000];
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
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = high_resolution_clock::now();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
            string str1, str2;
            cin >> str1>>str2;
            lcs_memo(str1, str2);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Recursion: "<< duration.count() << endl;
}