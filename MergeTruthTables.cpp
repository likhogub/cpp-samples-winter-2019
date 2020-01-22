#include <iostream>
using namespace std;

void main()
{
	int F[4][3] =
	{
		{0, 0, 0},
		{0, 1, 1},
		{1, 0, 0},
		{1, 1, 1}
	};
	int G[8][4] =
	{
		{0,0,0,1},
		{0,0,1,0},
		{0,1,0,1},
		{0,1,1,1},
		{1,0,0,0},
		{1,0,1,0},
		{1,1,0,0},
		{1,1,1,1}
	};
	for (int i = 0; i < 4; i++)
		for (int k = 0; k < 2; k++)
		{
			if ((F[i][2] + G[2 * i + k][3]) >= 1) cout << F[i][0] << F[i][1] << k << 1 << endl;
			else cout << F[i][0] << F[i][1] << k << 0 << endl;
		}
}
