#include<bits/stdc++.h>
using namespace std;

int MCM(vector<int> &arr, int N)
{
    int arr2D[N][N];
    memset(arr2D,0,sizeof(arr2D));
    for(int i = N-1 ; i >= 1 ; i--)
    {
        for(int j = i+1; j < N ; j++)
        {
            int res = INT_MAX;
            for(int k = i ; k < j; k++)
            {
                int Totaloperations = arr[i-1]*arr[k]*arr[j] + arr2D[i][k] + arr2D[k+1][j];
                if(Totaloperations < res)
                    res = Totaloperations;
            }
            arr2D[i][j] = res;
        }
    }
    return arr2D[1][N-1];
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
    int ans = MCM(arr,N+1);
    cout<<"Total Number of Minimum Operation is : "<<ans<<"\n";
    return 0;
}