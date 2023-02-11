#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace std::chrono;
int dp[10000];
int rodcutting(int price[], int n)
{
    if (n <= 0)
        return 0;
    if(dp[n]!=-1) return dp[n];
    int max_val = INT_MIN; // set maximum value to negative infinity
    for (int i = 0; i < n; ++i)
        max_val = max(max_val, price[i] + rodcutting(price, n - i - 1));
    return dp[n]=max_val;
}
int main()
{
   freopen("inp.txt", "r", stdin);
    freopen("output.txt", "a", stdout);

    auto start = high_resolution_clock::now();
    int price[1000000];
    int n, m;
    long long int ans=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            memset(dp,-1,sizeof(dp));
            cin >> price[j];
        }
            ans+=rodcutting(price, m) ;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Top Down/Memoization : "<<ans<<" "<< duration.count() << endl;

}