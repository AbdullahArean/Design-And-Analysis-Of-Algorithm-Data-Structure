#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int lis_rec(int idx, int prev_idx, int n, int a[])
{
    if (idx == n)
        return 0;
    int notTake = 0 + lis_rec(idx + 1, prev_idx, n, a);
    int take = INT_MIN;
    if (prev_idx == -1 || a[idx] > a[prev_idx])
    {
        take = 1 + lis_rec(idx + 1, idx, n, a);
    }
    return max(take, notTake);
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
        int a[1000000];
        for (int j = 0; j < m; j++)
        {
            cin >> a[j];
        }
        ans+=lis_rec(0, -1, m, a);;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Recursion: "<<ans<<" "<< duration.count() << endl;
}