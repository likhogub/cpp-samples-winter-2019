#include <iostream>
using namespace std;


void main()
{
	int points_q = 6;
	int X[] = { 1, 3, 2, 4, 5, 7 };
	int Y[] = { 2, 4, 5, 4, 3, 2 };
	int targetY;
	cin >> targetY;
	int index = -1;
	for (int i = 0; i < points_q; i++)
	{
		if (targetY == Y[i])
		{
			index = i;
			cout << X[i] << endl;
		}
	}
	if (index == -1) cout << " There is no such points" << endl;
}
