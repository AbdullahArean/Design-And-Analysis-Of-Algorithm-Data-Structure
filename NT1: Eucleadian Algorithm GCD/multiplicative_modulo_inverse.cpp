/*
Multiplicative Modulo Inverse
==================================
Given two integers 'a' and 'm', find modular multiplicative inverse of 'a' under modulo
'm'. The modular multiplicative inverse is an integer5 'x' sucht that

a x = 1 (mod m);
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> extended_gcd(int a, int b)
{
    if (b == 0)
    {
        return {1, 0, a};
    }
    vector<int> result = extended_gcd(b, a % b);

    // after recursive call is over
    int smallx = result[0];
    int smally = result[1];
    int gcd = result[2];

    int x = smally;
    int y = smallx - (a / b) * smally;

    return {x, y, gcd};
}
int modInverse(int a, int m)
{
    vector<int> result = extended_gcd(a, m);
    int x = result[0];
    int gcd = result[2];

    if (gcd != 1)
    {
        cout << "Multiplicative Modulo Inverse doesn't exists";
        return -1;
    }
    int ans = (x % m + m) % m; // x can be negative also;
    return ans;
}

int main()
{
    cout << modInverse(6, 7) << endl;
    return 0;
}