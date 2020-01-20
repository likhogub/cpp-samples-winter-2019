#include <iostream>
using namespace std;


int main()
{
	//------Var's section--------------------------------//
	const int size = 50;
	int row_with_line = 27;
	int left_pos = 8;
	int right_pos = 33;
	int image[size][size];
	//------Matrix init----------------------------------//
	for (int row = 0; row < size; row++)
		for (int col = 0; col < size; col++)
			image[row][col] = 0;

	//------Line draw------------------------------------//
	for (int col = left_pos; col <= right_pos; col++) image[row_with_line][col] = 1;
	
	//------Show Matrix----------------------------------//
	
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++) cout << image[row][col];
		cout << endl;
	}
	
	//------Algo---------------------------------//
	//------Detecting row with line---------------//
	int target_row = -1;
	int middle_col = size / 2;
	for (int row = 0; row < size; row++)
		if (image[row][middle_col] == 1) target_row = row;
	cout << target_row << endl;						//----Show number of row with line
	//------Binary search of the line beginning
	int left_point = 1;
	int right_point = size - 2;
	int pointer = middle_col;
	while ((pointer - left_point) > 1)				
	{
		if (image[target_row][(left_point + pointer) / 2] == 1) pointer = (left_point + pointer) / 2;
		else left_point = (left_point + pointer) / 2;
	}
	cout << "Left point is " << pointer << endl;
	//------Binary search of the line ending
	while ((right_point - pointer) > 1)
	{
		if (image[target_row][(right_point + pointer) / 2] == 1) pointer = (right_point + pointer) / 2;
		else right_point = (right_point + pointer) / 2;
	}
	cout << "Right point is " << pointer << endl;
}
