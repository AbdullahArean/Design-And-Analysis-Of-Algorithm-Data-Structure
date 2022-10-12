#include <bits/stdc++.h>
using namespace std;
int rodcutting(int price[], int n)
{
    if (n <= 0)
        return 0;
    int max_val = INT_MIN; // set maximum value to negative infinity
    for (int i = 0; i < n; ++i)
        max_val = max(max_val, price[i] + rodcutting(price, n - i - 1));
    return max_val;
}
int main()
{
    int price[6]={1, 4, 1,2, 5,3};
    cout<<rodcutting(price, 6)<<endl;
}