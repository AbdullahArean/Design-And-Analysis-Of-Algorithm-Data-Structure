#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "a", stdout);
    auto start = high_resolution_clock::now();
    int N, W;
    int weight[1001], profit[1001];
    int dp[1001][1001];
    cin >> N >> W; // N = number of item, W = total weight to be considered(#knapsack_tabu_rec's Weight)
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> profit[i];
    }
    for (int i = 0; i <= N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i] > w)
                dp[i][w] = dp[i - 1][w];
            else
                dp[i][w] = max(profit[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
        }
    }
    long long int ans = dp[N][W];
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Bottom Up/Tabulation: " << ans << " " << duration.count() << endl;
}