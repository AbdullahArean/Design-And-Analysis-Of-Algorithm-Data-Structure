#bugggggggggg
#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int weight[1001],profit[1001];
int Mat[1001][1001];
int knapsack_tabu(int N, int W)
{
    memset(Mat,0,sizeof(Mat));
    int res;
    for(int i = 0 ; i <= N ; i++)
    {
        for(int j = 0; j <= W ; j++)
        {
            if(i == 0 || j == 0)
            {
                Mat[i][j] = 0;
            }

            else if(weight[i-1] > j)
            {
                Mat[i][j] = Mat[i-1][j];
            }
            else
            {
                Mat[i][j] = max(Mat[i-1][j], profit[i-1] + Mat[i-1][j-weight[i-1]]);
            }
        }
    }
    return Mat[N][W];
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "a", stdout);
    auto start = high_resolution_clock::now();
    int N, W;
    memset(Mat,-1,sizeof(Mat));
    cin >> N >> W; // N = number of item, W = total weight to be considered(#knapsack_tabu_rec's Weight)
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> profit[i];
    }
    int ans = knapsack_tabu(W, N);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Bottom Up/Tabulation: "<<ans<<" "<< duration.count() << endl;
}