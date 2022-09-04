#include <bits/stdc++.h>
using namespace std;
#define meme(arr, x) memset(arr, x, sizeof(arr))
#define Endl '\n'
#define endl '\n'
const int N = 3e4 + 9;
const int mod = 1e9 + 7;
typedef unsigned long long int ull;
typedef long long int ll;
#define INF INT_MAX
#define INF64 INT64_MAX
void run()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
}
vector<int> g[1000006];
vector<bool> vis;
vector<int> path;
int n;
int total = 0;
int pal = 0;
string s;
bool check(vector<int> path)
{
    bool f = true;
    int len = path.size();
    for (int i = 1; i < len and f; ++i)
    {
        if (s[path[i] - 1] != s[(path[len - i - 1] - 1)])
            f = false;
    }
    return f;
}

void bfs(int src)
{
    vis.assign(n + 2, false);
    queue<int> cont;
    cont.push(src);
    vis[src] = true;
    while (!cont.empty())
    {
        ++total;
        int u = cont.front();
        cont.pop();
        path.push_back(u);
        if (check(path))
        {
            ++pal;
        }
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                cont.push(v);
            }
        }
    }
}

void _main()
{
    total = 0;
    pal = 0;
    path.clear();
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i <= n; ++i)
        g[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    bfs(1);
    int gcd = __gcd(pal, total);
    cout << pal / gcd << "/" << total / gcd << endl;
}

int main()
{
    // double st = clock();
    run();

    int tc = 1;
    cin >> tc;
    for (int cs = 1; cs <= tc; ++cs)
    {
        cout << "Case " << cs << ": ";
        _main();
    }
    // double et = clock();
    // cout<<(et-st)/CLOCKS_PER_SEC<<endl;
    return 0;
}