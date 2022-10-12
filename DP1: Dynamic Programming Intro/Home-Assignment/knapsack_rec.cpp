#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int weight[1001], profit[1001];

int knapsack_rec(int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (weight[n - 1] > W)
        return knapsack_rec(W, n - 1);
    else
        return max(profit[n - 1] + knapsack_rec(W - weight[n - 1], n - 1), knapsack_rec(W, n - 1));
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = high_resolution_clock::now();
    int N, W;
    cin >> N >> W; // N = number of item, W = total weight to be considered(#knapsack_tabu_rec's Weight)
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> profit[i];
    }
   int ans= knapsack_rec(W, N);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Recursion: " <<ans<<" "<< duration.count() << endl;
}