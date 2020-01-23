#include <iostream>
using namespace std;

float X[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
float Y[] = { 6.7, 8.9, 4.3, 3.9, 2.1, 5.9, 4.8, 2.5, 3.7, 8.7 };
float max_diff = 0.001;
bool found = false;
int A1, A2, B1, B2;

float tan(float x1, float x2, float y1, float y2)
{
	float dY = y2 - y1;
	float dX = x2 - x1;
	return dY / dX;
}

float x(int i)
{
	return X[i];
}

float y(int i)
{
	return Y[i];
}

void main()
{
	int size = 10;
	for (int a1 = 0; a1 < size; a1++)
		for (int a2 = 0; a2 < a1; a2++)
		{
			float tg1 = tan(x(a1), x(a2), y(a1), y(a2));
			for (int b1 = 0; b1 < size; b1++)
				for (int b2 = 0; b2 < b1; b2++)
				{
					float tg2 = tan(x(b1), x(b2), y(b1), y(b2));
					if ((abs(tg1 - tg2) < max_diff) && (a1 != b1) && (a2 != b2))
					{
						found = true;
						A1 = a1;
						A2 = a2;
						B1 = b1;
						B2 = b2;
					}
				}
		}
	if (found) 
	{ 
	cout << x(A1) << " " << y(A1) << endl;
	cout << x(A2) << " " << y(A2) << endl;
	cout << x(B1) << " " << y(B1) << endl;
	cout << x(B2) << " " << y(B2) << endl;
	}
	else cout << "Not found" << endl;
}
