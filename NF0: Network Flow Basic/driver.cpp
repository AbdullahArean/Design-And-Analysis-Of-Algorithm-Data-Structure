#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("inp.txt", "r", stdin);
    freopen("in.txt", "w", stdout);
    srand(time(0));

    int n = rand() % 100 + 1;
    int m = rand() % 500 + 1;
    
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < m; ++i) {
        int u = rand() % n + 1;
        int v = rand() % n + 1;
        while (u == v) v = rand() % n + 1;
        cout << u << ' ' << v << ' ';
        cout << rand() % 500 << '\n';
    }
}