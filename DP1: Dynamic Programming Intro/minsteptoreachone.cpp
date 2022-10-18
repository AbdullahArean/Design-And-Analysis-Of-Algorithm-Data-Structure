#include <bits/stdc++.h>
using namespace std;

int f(int n){
    if(n==1) return 0;
    int ans=INT_MAX;
    if(n%2==0){
        ans= min(ans, f(n/2));
    }
    if(n%3==0){
        ans= min(ans, f(n/3));
    }
    ans = min(ans, f(n-1));

    return ans+1;
}
int main()
{
    int n = 8;
}