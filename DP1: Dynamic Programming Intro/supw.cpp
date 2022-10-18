#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=8;
    //cin>>n;
    int a[n]={3, 2, 3, 2, 3, 5, 1 ,3}, dp[n];
    // for(int i=0; i<n; i++){
    //     cin>>a[i];
    // }
    dp[0]=a[0];
    dp[1]=a[1];
    dp[2]=a[2];
    for(int i=3; i<n; i++){
        dp[i]=min({dp[i-1], dp[i-2], dp[i-3]})+a[i];
    }
    cout<<min({dp[n-1], dp[n-2], dp[n-3]});
}