#include <iostream>
#include <cmath>
using namespace std;
#define N 9
void printMat(int mat[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
bool isSafe(int mat[][N], int i, int j, int no, int n)
{
    // check for row and column
    for (int k = 0; k < n; k++)
    {
        if (mat[k][j] == no || mat[i][k] == no)
            return false;
    }
    // check for grid
    int sqrtn = sqrt(n);
    int sx = (i / sqrtn) * sqrtn;
    int sy = (j / sqrtn) * sqrtn;
    for (int x = sx; x < sx + sqrtn; x++)
    {
        for (int y = sy; y < sy + sqrtn; y++)
        {
            if (mat[x][y] == no)
                return false;
        }
    }
    return true;
}
bool solveSudoku(int mat[][N], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        // print the solution later
        printMat(mat, n);
        return true;
    }
    // recursive case
    if (j == n)
    {
        return solveSudoku(mat, i + 1, 0, n);
    }
    // skip prefilled cell
    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j + 1, n);
    }
    // cell to be filled
    for (int no = 1; no <= n; no++)
    {
        // whether it is safe or not
        if (isSafe(mat, i, j, no, n))
        {
            mat[i][j] = no;
            bool solveSubProblem = solveSudoku(mat, i, j + 1, n);
            if (solveSubProblem == true)
            {
                return true;
            }
        }
    }
    // if no option works
    mat[i][j] = 0;
    return false;
}
int main()
{
    int mat[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    if (!solveSudoku(mat, 0, 0, N))
    {
        cout << "Solution Does Not Exists\n";
    }
}