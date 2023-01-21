#include <bits/stdc++.h>
using namespace std;
bool oddeven(int n)
{
    // odd returns true, even returns false
    if (n & 1) // is same as (n % 2)
        return 1;
    return 0;
}
bool getith(int n, int i)
{
    // here int mask = 1<<i;
    return n & (1 << i);
}
void setith(int &n, int i)
{
    int mask = i << i;
    n = n | mask;
}
void clearith(int &n, int i)
{
    int mask = i << i;
    n = n | ~mask;
}

int main()
{
    for (int i = 2; i < 20; i++)
    {
        cout << oddeven(i) << endl;
    }
    getith(21, 0);
}