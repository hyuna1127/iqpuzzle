#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int ** arr;
	int temp; //temp value
	int row = 0, col = 0; // initialize row and col value to zero

	do
	{
		cout << "input odd number large than 2 for magic square (ex. if 5x5 magic square, input 5) : ";
		cin >> temp;
	} while (temp < 3 || temp % 2 == 0);

	col = temp / 2;

	arr = new int*[temp]; // dynamic assignmnet to arr(a two-dimensional array)
	for (int i = 0; i < temp; i++)
	{
		arr[i] = new int[temp];
	}

	for (int i = 0; i < temp; i++) // initialize the array to zero
	{
		for (int k = 0; k < temp; k++)
			arr[i][k] = 0;
	}

	arr[row][col] = 1; // put 1 in the center of first row

	for (int i = 2; i < temp*temp + 1; i++)
	{
		if ((row - 1 < 0) && (col + 1 > temp - 1)) // if column and row of array is exceeded
			arr[++row][col] = i;
		else if (row - 1 < 0) // if row of array is exceeded
		{
			arr[temp - 1][++col] = i;
			row = temp - 1;
		}
		else if (col + 1 > temp - 1) // if column of array is exceeded
		{
			arr[--row][0] = i;
			col = 0;
		}
		else if (arr[row - 1][col + 1] != 0) // if there is another number in the next path
			arr[++row][col] = i;
		else // succestive insert
			arr[--row][++col] = i;

	}

	cout << endl;
	for (int i = 0; i < temp; i++) // print out majic square
	{
		for (int k = 0; k < temp; k++)
			cout << setw(5) << arr[i][k];
		cout << endl;
	}

	for (int i = 0; i < temp; i++)
	{
		delete(arr[i]);
	}
	delete(arr);

	return 0;

}
