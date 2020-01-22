#include <iostream>
using namespace std;


void main()
{
	int gaps = 0;
	int points = 4;
	float precision = 0.0001; 
	float X[] = { 0,1,2,3 };
	float A[] = { 1,2,-1,-2 };
	float B[] = { 0,-1,5,8};

	//----------------------------//

	for (int point = 1; point < points; point++)
	{
		int offset = abs((X[point] * A[point - 1] + B[point - 1]) - (X[point] * A[point] + B[point]));
		if (offset >= precision) gaps++;
	} 
	cout << gaps << endl;

}
