#include <iostream>
using namespace std;

int matrix[6][6] = { 
	{ 0,0,0,0,0,0 },
	{ 0,1,0,0,0,0 },
	{ 0,1,0,0,0,0 },
	{ 0,1,1,1,0,0 },
	{ 0,1,0,0,1,0 },
	{ 0,1,1,1,0,0 } };

void show_m()
{
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 6; col++) cout << matrix[row][col];
		cout << endl;
	}
}


void main()
{
	int PRow = -1;
	int PCol = -1;
	int row, col;
	row = col = 0;
	while (PRow == -1)
	{
		if (matrix[row][col] == 1)
		{
			PRow = row;
			PCol = col;
		}
		col++;
		if (col == 6)
		{ 
			row++;
			col = 0;
		}
		
	}
	cout << PRow << "" << PCol << endl;
	row = 5;
	col = 5;
	int RCol = 0;
	while (row > PRow)
	{
		if ((matrix[row][col] == 1)&& (RCol < col)) RCol = col;
		col--;
		if (col == -1)
		{
			row--;
			col = 5;
		}
	}
	cout << RCol << endl;
	for (int i = PCol; i <= RCol; i++) (matrix[PRow][i] = 1);
	show_m();

}
