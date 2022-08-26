#include <bits/stdc++.h>
using namespace std;
pair<int, int> numtopos(int num, int n)
{
    int row = (num - 1) / n, col = (num - 1) % n;
    int x = n - 1 - row, y = row % 2 == 0 ? col : n - 1 - col;
    return {x, y};
}
int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    int vis[n * n + 1];
    for (int i = 0; i < n * n + 1; i++)
        vis[i] = 0;
    queue<int> cont;
    vis[1] = 1;
    cont.push(1);
    int step = 1;

    while (!cont.empty())
    {
        int size = cont.size();
        for (int k = 0; k < size; k++)
        {
            int u = cont.front();
            cont.pop();
            if (u == n * n)
                return step;
            for (int i = 1; i <= 6; i++)
            {
                int v = u + i;
                pair<int, int> temp = numtopos(v, n);
                int positional_value = board[temp.first][temp.second];

                if (positional_value > -1)
                {
                    v = positional_value;
                }
                if (v == n * n)
                    return step;
                if (vis[v])
                    continue;
                vis[v] = true;
                cont.push(v);
            }
        }

        step++;
    }
    return -1;
}
