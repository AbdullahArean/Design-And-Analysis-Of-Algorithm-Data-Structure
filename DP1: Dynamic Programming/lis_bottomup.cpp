#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int lis(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
 
    return *max_element(lis, lis + n);
}
int main()
{
freopen("inp.txt", "r", stdin);
    freopen("output.txt", "a", stdout);
    auto start = high_resolution_clock::now();
    long long int ans=0;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        int a[1000000];
        for (int j = 0; j < m; j++)
        {
            cin >> a[j];
        }
        ans+=lis(a,m);;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Bottom Up/ Tabulation: "<<ans<<" "<< duration.count() << endl;
}