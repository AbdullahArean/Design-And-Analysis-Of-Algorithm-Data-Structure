#include <bits/stdc++.h>
using namespace std;

int mat[100][100], dp[100][100];
int r, c;
int rockclimbing_rec(int i, int j)
{
    if (i >= 0 && i < r and j >= 0 && j < c)
    { /// If inside array
        int res = INT_MIN;
        /// Moving to three default direction, also add current cell's point
        res = max(res, rockclimbing_rec(i + 1, j) + mat[i][j]);
        res = max(res, rockclimbing_rec(i + 1, j - 1) + mat[i][j]);
        res = max(res, rockclimbing_rec(i + 1, j + 1) + mat[i][j]);
        return res;
    }
    else
        return 0;
}
int rockclimbing_memo(int i, int j)
{
    if (i >= 0 && i < r and j >= 0 && j < c)
    { /// If inside array
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MIN;
        /// Moving to three default direction, also add current cell's point
        res = max(res, rockclimbing_memo(i + 1, j) + mat[i][j]);
        res = max(res, rockclimbing_memo(i + 1, j - 1) + mat[i][j]);
        res = max(res, rockclimbing_memo(i + 1, j + 1) + mat[i][j]);
        return dp[i][j] = res;
    }
    else
        return 0; /// If outside array
}
int rockclimbing_tabu(int i, int j)
{
    for(int i=0; i<r+2; i++){
        for(int j=0; j<c+2; j++){
            dp[i][j]=0;
        }
    }
    for(int i=1; i<r+1; i++){
        for(int j=1; j<c+1; j++){
            if(i+1)
            dp[i][j]= mat[i][j]+max({dp[i -1][j] ,dp[i - 1][j-1], dp[i -1][ j+1] });
        }
    }
        return dp[r][c]; /// If outside array
}

int main()
{
    int res = 0;
    memset(dp, -1, sizeof(dp));
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << "Maximum Point is: Tabu" << rockclimbing_tabu(0, 0) << endl;
     cout<<"Tabuuuuuuuu\n";
     for(int i=0; i<r+2; i++){
        for(int j=0; j<c+2; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    memset(dp, -1, sizeof(dp));
    cout << "Maximum Point is: Memo" << rockclimbing_memo(0, 0) << endl;
    cout<<"Memoooooooo\n";
    for(int i=0; i<r+2; i++){
        for(int j=0; j<c+2; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout << "Maximum Point is: Rec" << rockclimbing_rec(0, 0) << endl;

    return 0;
}