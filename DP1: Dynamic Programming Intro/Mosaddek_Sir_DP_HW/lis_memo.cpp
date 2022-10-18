#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace std::chrono;
int lis(int idx, int prev_idx, int n, int a[],vector<vector<int>> &dp)
{
    if (idx == n)
    {
        return 0;
    }
    if (dp[idx][prev_idx + 1] != -1)
    {
        return dp[idx][prev_idx + 1];
    }
    int notTake = 0 + lis(idx + 1, prev_idx, n, a, dp);
    int take = INT_MIN;
    if (prev_idx == -1 || a[idx] > a[prev_idx])
    {
        take = 1 + lis(idx + 1, idx, n, a, dp);
    }
    return dp[idx][prev_idx + 1] = max(take, notTake);
}
int main()
{
freopen("inp.txt", "r", stdin);
    freopen("output.txt", "a", stdout);
    auto start = high_resolution_clock::now();
    long long int ans=0;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        int a[10000];
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        for (int j = 0; j < m; j++)
        {
            cin >> a[j];
        }
        ans+=lis(0, -1, m, a, dp);;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Top Down/ Memoization: "<<ans<<" "<< duration.count() << endl;
}