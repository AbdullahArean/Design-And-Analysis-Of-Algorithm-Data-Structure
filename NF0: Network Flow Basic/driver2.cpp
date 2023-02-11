#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("inp.txt", "r", stdin);
    freopen("in.txt", "w", stdout);
    srand(time(0));

    int n = rand() % 100 + 1;
    int n2 = rand() % 50 + 1;
    int n1 = n-n2 -2;
    int m = rand() % 500 + 1;
    
    cout << n << ' ' <<n1<<' '<< n2<<' '<<m << '\n';
    for (int i = 0; i < m; ++i) {
        int u = rand() % n1 + 1;
        int v = n1+ rand() % n2 + 1;
        while (u == v) v = rand() % n + 1;
        cout << u << ' ' << v << ' ';
        cout <<"1"<< '\n';
    }
}