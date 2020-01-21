#include <iostream>
using namespace std;

int matrix[20][20];

void make_m()
{
	for (int row = 0; row < 20; row++) for (int col = 0; col < 20; col++) matrix[row][col] = 0;
}

void show_m()
{
	for (int row = 0; row < 20; row++)
	{
		for (int col = 0; col < 20; col++) cout << matrix[row][col];
		cout << endl;
	}
	cout << endl;
}

void draw(int x1, int y1, int x2, int y2)
{
	int dX = x2 - x1;
	int dY = y2 - y1;
	int Y = y1;
	int X = x1;
	float tan = dY / dX;
	float offset = 0;
	for (int X = x1; X <= x2; X++)
	{
		matrix[Y][X] = 1;
		offset += tan;
		if (offset > 0.5)
		{
			offset = 1 - offset;
			Y++;
		}
	}

}


void main()
{
	show_m();
	draw(0, 0, 15, 5);
	show_m();





}
