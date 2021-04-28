#include<bits/stdc++.h>
using namespace std;

//BackTracking is used
//You can only move Down or Right 
//x and y are the current position of the rat
//This code will check if x and y is less than n which means that the given position is inside the constraints given
bool isSafe(int **arr, int x, int y, int n)
{
	//arr[x][y]==1 will check if it can go there as rat can only move on the elements which are 1
	if (x < n and y < n and arr[x][y] == 1)
	{
		return true;
	}
	return false;
	//The given position is not safe and hence the rat cannot go there
}
bool ratInMaze(int **arr, int x, int y, int n, int **solArr)
{
	//Base condition - the rat has reached its destination
	if (x == n - 1 and y == n - 1)
	{
		solArr[x][y] = 1;
		return true;
	}
	if (isSafe(arr, x, y, n))
	{
		solArr[x][y] = 1;
        //To move Right
		if (ratInMaze(arr, x + 1, y, n, solArr))
		{
			return true;
		}
        //To move Down
		if (ratInMaze(arr, x, y + 1, n, solArr))
		{
			return true;
		}
		solArr[x][y] = 0;
		//BackTracking
		return false;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
    //Creating a 2D dynamic array 
	int **arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
    //Taking input
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
    //Creating a Solution Array
	int **solArr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		solArr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			solArr[i][j] = 0;
		}
	}
    //Printing out the path that Rat will take
    cout<<"The answer is "<<endl;
	if (ratInMaze(arr, 0, 0, n, solArr))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << solArr[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
/* Sample Input */
/*

4

1 0 0 0
1 1 0 1 
1 1 0 0
0 1 1 1

*/