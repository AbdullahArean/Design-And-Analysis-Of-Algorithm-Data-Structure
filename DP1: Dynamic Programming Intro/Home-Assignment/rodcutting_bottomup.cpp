#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int rodcutting(int price[], int n)
{
    int revs[n + 1];
    revs[0] = 0; // the revenue of a rod of length 0 is 0.
    int maxi = -99999;
    for (int j = 1; j <= n; j++)
    { // revs[j] indicates maximum revenue of a rod of length j.
        maxi = -99999;;
        for (int i = 0; i < j; i++)
        {
            maxi = max(maxi, price[i] + revs[j - i - 1]);
        }
        revs[j] = maxi;
    }
    return revs[n];
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
            cin >> price[j];
        }
            ans+=rodcutting(price, m) ;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Bottom Up/ Tabulation: "<<ans<<" "<< duration.count() << endl;
}