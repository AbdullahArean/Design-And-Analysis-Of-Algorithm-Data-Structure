#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int given[10][10];
vector<vector<int> > ansv;
int f(int i, int j, int n, vector<int> store)
{
    if (i > n || j > n)
        return 0;
    store.push_back(given[i][j]);
    if (i == n && j == n)
    {
        vector<int> tempv;
        int sum = 0;
        for (auto i : store)
        {
            sum += i;
            tempv.push_back(i);
        }
        tempv.push_back(sum);
        ansv.push_back(tempv);
        return given[i][j];
    }
    else
        return given[i][j] + max(f(i + 1, j, n, store), f(i, j + 1, n, store));
    store.pop_back();
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    cin >> N; // N = number of item, W = total weight to be considered(#knapsack_tabu_rec's Weight)
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> given[i][j];
        }
    }
    vector<int> temp;
    int ans2 = f(1, 1, N, temp);
    for (auto ii : ansv)
    {
    if(ii[ii.size()-1]==ans2){
            for (auto jj : ii)
            {
                cout << jj << " ";
            }
            cout << endl;
    }
    }
    cout << ans2;
}