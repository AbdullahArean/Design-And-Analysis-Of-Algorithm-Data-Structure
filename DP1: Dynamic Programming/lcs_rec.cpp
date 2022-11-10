#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int lcs_rec(string s1, string s2, int i = 0, int j = 0)
{
    if (i >= s1.length() || j >= s2.length())
        return 0;
    else if (s1[i] == s2[j])
        return 1 + lcs_rec(s1, s2, i + 1, j + 1);
    else
        return max(lcs_rec(s1, s2, i + 1, j), lcs_rec(s1, s2, i, j + 1));
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = high_resolution_clock::now();
    int n;
    cin >> n;
    long long int ans=0;
    for (int i = 0; i < n; i++)
    {
        //memset(dp,-1,sizeof(dp));
            string str1, str2;
            cin >> str1>>str2;
            ans+=lcs_rec(str1, str2);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Recursion: "<<ans<< " "<< duration.count() << endl;
}