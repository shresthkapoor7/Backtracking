#include <bits/stdc++.h>
using namespace std;

// We are moving Row wise

/* 
    (arr) arr is the board
    (x,y) x and y represents our current position on the board
    (n) the board is of the size nXn
*/

/*
(isSafe) isSafe function is used to check if we can place a queen at x,y position without getting 
attacked from the queens in the previous rows
*/

bool isSafe(int **arr, int x, int y, int n)
{

    //Checking if there is any queen in the same row
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }
    //Checking Diagnols
    int row = x;
    int col = y;
    /*Checking the Left diagnol \ */
    while (row >= 0 and col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    // Reinitialize
    row = x;
    col = y;
    /*Checking the Right diagnol / */
    // col < n to make sure we are still inside the board
    while (row >= 0 and col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    /*
    We didn't check the diagnols below x and y because we are moving row wise and we haven't 
    reached those rows yet
    */
    // The position is safe you can place a queen here
    return true;
}

/*
(nQueen) the nQueen function is the main function it will use isSafe function to see if a queen can be 
placed at a position x(x will remain same because we are looking for the position of column),col after 
that it will check if a queen can be placed in the next row if this queen is placed at x,col 
*/
bool nQueen(int **arr, int x, int n)
{
    if (x >= n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            if (nQueen(arr, x + 1, n))
            {
                return true;
            }
            // Since by putting a queen at x,col you cannot place a queen in the next row it will backtrack
            // BackTracking
            arr[x][col] = 0;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    if (nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout<<"The "<<n<<" Queens cannot be placed on the board without attacking each other";
    }
    return 0;
}