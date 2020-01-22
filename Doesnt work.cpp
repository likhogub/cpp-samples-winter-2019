#include <iostream>
using namespace std;


float dist(float x1, float x2, float y1, float y2)
{
	return sqrt((x1-x2)* (x1 - x2) + (y1 - y2)* (y1 - y2));
}

float max_dist(float X[], float Y[], float x1, float y1)
{
	float max_r = 10000.0;
	for (int point = 0; point < 6; point++)
	{
		float range = dist(x1, X[point], y1, Y[point]);
		if ((max_r / 2) < range) max_r = range * 2;
	}
	return max_r;
}

void main()
{
	int points = 6;
	int p1;
	int p2;
	float X[] = { 0, 1, 0, 1, 1, 3};
	float Y[] = { 0, 0, 2, 2, 4, 2};
	float max_r = -1;
	//----------------------------//

	for (int point1 = 0; point1 < points; point1++)
	{
		for (int point2 = 0; point2 < point1; point2++)
		{
			float range = dist(X[point1], X[point2], Y[point1], Y[point2]);
			if (max_r < range)
			{
				max_r = range;
				p1 = point1;
				p2 = point2;
			}
		}
	}
	
	float midPX = (X[p1] + X[p2]) / 2;
	float midPY = (Y[p1] + Y[p2]) / 2;
	for (int point = 0; point < points; point++)
		{
			float range = dist(midPX, X[point], midPY, Y[point]);
			if ((max_r / 2) < range) max_r = range * 2;
		}
	cout << "midX=" << midPX << " midY=" << midPY << " range=" << max_r<< endl;
}
