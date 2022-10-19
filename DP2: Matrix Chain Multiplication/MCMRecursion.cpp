#include <bits/stdc++.h>
using namespace std;



int MCM(int i, int j , vector<int> &arr)
{
    if(i == j)
        return 0;
    int res = INT_MAX;
    for(int k = i; k < j ; k++)
    {
        int TotalOperations = arr[i-1]*arr[k]*arr[j] + MCM(i,k,arr) + MCM(k+1,j,arr);
        if(TotalOperations < res)
            res = TotalOperations;
    }
    return res;
    
}

int main()
{
    int N;
    cin>>N;
    vector<int>arr(N+1);
    for(int i = 0 ; i <= N ; i++)
    {
        cin>>arr[i];
    }
    int ans = MCM(1,N,arr);
    cout<<"Total Number of Minimum Operation is : "<<ans<<"\n";
    return 0;
}