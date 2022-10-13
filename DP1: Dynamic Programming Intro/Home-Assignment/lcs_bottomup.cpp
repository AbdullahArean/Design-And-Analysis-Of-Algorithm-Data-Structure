#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int dp[100][100];
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
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "a", stdout);
    auto start = high_resolution_clock::now();
    int n;
    long long int ans=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {   memset(dp,-1,sizeof(dp));
            string str1, str2;
            cin >> str1>>str2;
            ans+=lcs_tabu(str1, str2);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout  <<"Bottom Up/ Tabulation: "<<ans<<  duration.count() << endl;
}