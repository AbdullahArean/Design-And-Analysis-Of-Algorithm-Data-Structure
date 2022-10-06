#include <iostream>
#include <vector>
using namespace std;
#define Max 20
void printBoard(int n, int board[][Max])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                cout << board[i][j] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
bool canPlace(int board[][Max], int n, int x, int y)
{
    // Column
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
        {
            return false;
        }
    }

    // Left Diagonal
    int i = x, j = y;
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    // right diagonal
    i = x;
    j = y;
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}
bool solveNQueen(int n, int board[][Max], int i)
{
    // base case
    if (i == n)
    {
        // Print the Board
        printBoard(n, board);
        return true;
    }

    // recursive case
    // try to place a queen in every row
    for (int j = 0; j < n; j++)
    {
        // whether the current position is safe or not
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solveNQueen(n, board, i + 1);
            if (success)
            {
                return true;
            }
            // backtrack
            board[i][j] = 0;
        }
    }
    return false;
}
int main()
{
    
    char input[100];
    int n = 5;
    while(n<20){
    int board[Max][Max]={0};
    solveNQueen(n, board, 0);
    n++;
    }
    return 0;
}