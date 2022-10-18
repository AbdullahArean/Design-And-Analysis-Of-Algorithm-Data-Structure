#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int solve(int prev, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
    {
        if (prev == 0)
            return 2;
        if (prev == 1)
            return 1;
    }
    if (prev == 0)
        return solve(0, n - 1) + solve(1, n - 1);
    if (prev == 1)
        return solve(0, n - 1);
    return -1;
}
int solve2(int n)
{
    dp.resize(n + 1);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
int countStrings(int n)
{

    return solve(0, n);
}
int main()
{
    auto start = std::chrono::system_clock::now();
    // Some computation here
    for (int n = 1; n < 40; n++)
    {
        cout << n << ": " << countStrings(n) << "\n";
    }
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;

    start = std::chrono::system_clock::now();
    for (int n = 1; n < 40; n++)
    {

        cout << n << ":dp:  " << solve2(n) << "\n";
    }
    end = std::chrono::system_clock::now();

    elapsed_seconds = end - start;
    end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;
}