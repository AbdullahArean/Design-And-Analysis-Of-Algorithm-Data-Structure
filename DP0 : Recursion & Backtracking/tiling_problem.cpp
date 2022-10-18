#include <bits/stdc++.h>
using namespace std;
int tiling_problem(int n)
{
    if (n < 4)
        return 1;
    return tiling_problem(n - 1) + tiling_problem(n - 4);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    cout << tiling_problem(n);
}