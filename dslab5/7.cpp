#include <iostream>
using namespace std;

#define N 4

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col, int &maxFlags)
{
    if (col >= N)
    {
        int count = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] == 1)
                    count++;
        maxFlags = max(maxFlags, count);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1, maxFlags) || res;
            board[i][col] = 0;
        }
    }
    res = solveNQUtil(board, col + 1, maxFlags) || res;
    return res;
}

int main()
{
    int board[N][N] = {0};
    int maxFlags = 0;
    solveNQUtil(board, 0, maxFlags);
    cout << "Maximum number of flags that can be placed: " << maxFlags << endl;
    return 0;
}
