#include <bits/stdc++.h>
using namespace std;
void solve(int i)
{
    int aaa, bbb, ccc, kkk;
    cin >> aaa >> bbb >> ccc >> kkk;
    int summation = aaa + bbb + ccc;
    if (summation % 3 == 0)
    {
        int avg = summation / 3;
        if (abs(aaa - avg) % kkk == 0 && abs(bbb - avg) % kkk == 0 && abs(ccc - avg) % kkk == 0)
        {
            cout << "Case " << i << ": "
                 << "Peaceful\n";
            return;
        }
        else
        {

            cout << "Case " << i << ": "
                 << "Fight\n";
            return;
        }
    }
    cout << "Case " << i << ": "
         << "Fight\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }

    return 0;
}
