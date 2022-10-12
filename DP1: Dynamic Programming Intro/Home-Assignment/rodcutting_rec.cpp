#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int rodcutting(int price[], int n)
{
    if (n <= 0)
        return 0;
    int max_val = INT_MIN; // set maximum value to negative infinity
    for (int i = 0; i < n; ++i)
        max_val = max(max_val, price[i] + rodcutting(price, n - i - 1));
    return max_val;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = high_resolution_clock::now();
    long long int ans=0;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        int price[1000000];
        for (int j = 0; j < m; j++)
        {
            cin >> price[j];
        }
        ans+=rodcutting(price, m) ;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Recursion: "<<ans<<" "<< duration.count() << endl;
}