#include <bits/stdc++.h>
using namespace std;
int snakesAndLadders(vector<vector<int>> &board)
{
    queue<int> container;
    int nn = board.size();
    int n = nn * nn + 1;
    int vis[n];
    int dis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        dis[i] = INT_MAX;
    }
    container.push(1);
    dis[1] = 0;
    vis[1] = 1;
    while (container.empty())
    {

        int u = container.front();
        container.pop();
        for (int i = 1; i <= 6; i++)
        {
            int v = u + i;
            int pos_n = v / nn,pos_m;
            if (pos_n % 2 == 0)
            {
                pos_m = (nn - v % nn);
            }
            else
            {
                pos_m = (v % nn);
            }
            int val = board[pos_n][pos_m];
            if (val != -1)
                v = val;

            if (vis[v] == 0)
            {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                container.push(v);
            }
        }
    }
}
