#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int MatrixChainRecursion(int p[], int i, int j){

	if (i == j) return 0;

	int k;
	int val = INT_MAX;
	int count;

	for (k = i; k < j; k++){
		count = MatrixChainRecursion(p, i, k) + MatrixChainRecursion(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        val = min(count, val);
	}

	return val;
}


//Time Complexity: O(N^3 )
//Auxiliary Space: O(N^2)
// Function for matrix chain multiplication
int MatrixChainMemoised(int *p, int i, int j){

    if (i == j) return 0;
    
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++){
        dp[i][j] = min(dp[i][j], MatrixChainMemoised(p, i, k)+ MatrixChainMemoised(p, k + 1, j)+ p[i - 1] * p[k] * p[j]);
    }

    return dp[i][j];
}




//Time Complexity: O(N^3 )
//Auxiliary Space: O(N^2)
int MatrixChainBottomUp(int p[], int n){
 
    int m[n][n];
 
    int i, j, k, L, q;
 
    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    // L is chain length.
    for (L = 2; L < n; L++){
        for (i = 1; i < n - L + 1; i++){
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++){
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n - 1];
}

int main(){
	int arr[] = { 1, 2, 3, 4 };
	int N = sizeof(arr) / sizeof(arr[0]);
    memset(dp,-1,sizeof(dp));
	// Function call
	cout << "Minimum number of multiplications is "<< MatrixChainRecursion(arr, 1, N - 1)<<endl;
    cout << "Minimum number of multiplications is "<< MatrixChainMemoised(arr, 1, N - 1)<<endl;
	cout << "Minimum number of multiplications is "<< MatrixChainBottomUp(arr, N)<<endl;

	return 0;
}

// This code is contributed by Shivi_Aggarwal
