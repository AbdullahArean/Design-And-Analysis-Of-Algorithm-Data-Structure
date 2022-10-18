#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> gr[N];
int vis[N];
int n, m;
bool hamiltonian_path = 0;
void pathsprint()
{
}
void paths(int cur, int cnt)
{
    if (cnt == n)
    {
        hamiltonian_path = 1;
        return;
    }
    vis[cur] = 1;
    for (auto x : gr[cur])
    {
        if (!vis[x])
        {
            paths(x, cnt + 1);
        }
    }
    vis[cur] = 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        paths(i, 1);
}