#include <iostream>
using namespace std;
void printBoard(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++) 
            cout << board[i][j] << " ";
        cout << endl;
    }
}
bool isSafe(int board[9][9], int row, int col, int num) 
{  
    for (int i = 0; i < 9; i++)
        if (board[row][i] == num || board[i][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num) 
                return false;

    return true;
}
bool isSolvable(int board[9][9]) {
    int row, col;

    bool isEmpty = false;
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
            if (board[row][col] == 0) 
            {
                isEmpty = true;
                break;
            }
        if (isEmpty)
            break;
    }
    if (!isEmpty)
        return true;
    for (int num = 1; num <= 9; num++)
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;
            if (isSolvable(board)) 
                return true;
            board[row][col] = 0;
        }
    return false;
}
int main() 
{
    string choice;
    int board[9][9] = 
    {
        {1, 0, 0, 0, 2, 0, 0, 0, 8},
        {0, 8, 0, 0, 0, 4, 0, 0, 0},
        {0, 0, 3, 0, 1, 8, 5, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 2, 0},
        {0, 0, 4, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 5, 0, 0, 0, 6},
        {2, 7, 0, 0, 0, 0, 0, 0, 3},
        {0, 9, 8, 0, 7, 3, 2, 0, 0},
        {4, 0, 0, 0, 0, 0, 6, 5, 0}
    };
    cout << "Sudoku Puzzle:" << endl;
    printBoard(board);
    cout << endl << endl;
    if (isSolvable(board))
    {
        cout << "Solution:" << endl;
        printBoard(board);
    }
    else
        cout << "No Solution Exists!\n";
        
    return 0;
}