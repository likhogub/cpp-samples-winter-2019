#include <iostream>
using namespace std;

void pr(int a, int b, int c)
{
	cout << a << " to " << b << " aux " << c << endl;
}



void movet(int n, int a, int b, int c)
{
	if (n != 1) movet(n - 1, a, c, b);
	pr(a, b, c);
	if (n > 1) movet(n - 1, c, b, a);
}

void main()
{
	movet(3, 1, 2, 3);
}
