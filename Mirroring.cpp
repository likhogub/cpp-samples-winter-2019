#include <iostream>
using namespace std;


int image[10][10] = {
{0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,1,0},
{0,0,1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{1,1,1,1,1,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0} };


void main()
{
	int size = 10;
	int row = 0;
	int col = 0;
	int cCol = -1;
	while (cCol == -1)
	{
		if (image[row][col] == 1)
		{
			bool found = true;
			for (int test_row = row; test_row < 5; test_row++) if (image[test_row][col] == 0) found = false;
			if (found) cCol = col;
		}
		col++;
		if (col == 10)
		{
			row++;
			col = 0;
		}
	}
	cout << cCol << endl;
	int ARow = -1;
	int ACol = -1;
	row = 0;
	col = 0;
	while (ARow == -1)
	{
		if (image[row][col] == 1)
		{
			bool found1 = true;
			for (int test_col = col; test_col < col + 3; test_col++) if (image[row][test_col] == 0) found1 = false;
			if (found1)
			{
				ARow = row;
				ACol = col;
			}
		}
		col++;
		if (col == cCol)
		{
			row++;
			col = 0;
		}
	}
	cout << ARow << " " << ACol << endl;
	int offset = cCol - ACol;
	int result[10][10];
	for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) result[i][j] = 0;
	for (int j = 0; j < size; j++) result[j][9 - cCol] = image[j][cCol];
	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size; j++)
		{
			result[i][9 - j] = image[i][j];
		}






	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) cout << image[i][j];
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) cout << result[i][j];
		cout << endl;
	}
}
