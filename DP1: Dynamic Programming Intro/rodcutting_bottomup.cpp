#include <bits/stdc++.h>
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
    int price[6] = {1, 4, 1, 2, 5, 3};
    cout << rodcutting(price, 6) << endl;
}