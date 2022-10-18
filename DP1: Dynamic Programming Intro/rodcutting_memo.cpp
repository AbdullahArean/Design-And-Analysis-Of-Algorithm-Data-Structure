#include <bits/stdc++.h>
using namespace std;
int dp[10000];
int rodcutting(int price[], int n)
{
    if (n <= 0)
        return 0;
    if(dp[n]!=-1) return dp[n];
    int max_val = -999999; // set maximum value to negative infinity
    for (int i = 0; i < n; ++i)
        max_val = max(max_val, price[i] + rodcutting(price, n - i - 1));
    return dp[n]=max_val;
}
int main()
{
    int price[6]={1, 4, 1,2, 5,3};
    for(int i=1; i<=6; i++){
        dp[i]=-1;

    }
    cout<<rodcutting(price, 6)<<endl;
}