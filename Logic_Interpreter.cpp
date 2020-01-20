#include <iostream>
using namespace std;

bool AND(bool a, bool b)
{
	return a && b;
}

bool OR(bool a, bool b)
{
	return a || b;
}

bool NOT(bool a)
{
	return !a;
}


int int_to_bool(int a)
{
	if (a == 0) return false;
	return true;
}

bool char_to_bool(char a, int x, int y, int z)
{
	if (a == 'x') return int_to_bool(x);
	if (a == 'y') return int_to_bool(y);
	if (a == 'z') return int_to_bool(z);
}

bool detect(char exp[], bool tmp, int index, int x, int y, int z)
{
	if (exp[index] == '\0') return tmp;

	if (exp[index] == 'N')
		detect(exp, NOT(char_to_bool(exp[index + 3], x, y, z)), index + 4, x, y, z);
	if (exp[index] == 'A')
		detect(exp, AND(tmp, char_to_bool(exp[index + 3], x, y, z)), index + 4, x, y, z);
	if (exp[index] == 'O')
		detect(exp, OR(tmp, char_to_bool(exp[index + 2], x, y, z)), index + 3, x, y, z);

	return detect(exp, char_to_bool(exp[index], x, y, z), index + 1, x, y, z);
}





void main()
{
	char exp[] = { 'N','O','T','x','O','R','y','A','N','D','z', '\0' };

	cout << detect(exp, false, 0, 0, 1, 1) << endl;
}
