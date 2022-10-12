#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int weight[1001],profit[1001];
int Mat[1001][1001];
int knapsack_memo(int W, int n)
{
    if (n == 0 || W == 0)
		return 0;
    else if(Mat[n][W] != -1)
        return Mat[n][W];
	else if (weight[n - 1] > W)
		return Mat[n][W] = knapsack_memo(W, n - 1);
	else
		return Mat[n][W] = max(profit[n - 1] + knapsack_memo(W - weight[n - 1],  n - 1), knapsack_memo(W,  n - 1));
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "a", stdout);
    auto start = high_resolution_clock::now();
    int N, W;
    memset(Mat,-1,sizeof(Mat));
    cin >> N >> W; // N = number of item, W = total weight to be considered(#knapsack_rec's Weight)
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> profit[i];
    }
    int ans=knapsack_memo(W, N);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Top Down/Memoization: "<<ans<< " "<< duration.count() << endl;
}