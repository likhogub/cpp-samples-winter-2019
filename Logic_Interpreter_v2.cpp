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

/*bool detect(char exp[], bool tmp, int index, int x, int y, int z)
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
*/
bool detect(char exp[], bool tmp, int index, int x, int y, int z)
{
	if (exp[index] == '\0') return tmp;

	if (exp[index] == 'N')
	{
		cout << "exp[index]=" << exp[index] << " tmp =" << tmp << endl;
		return detect(exp, NOT(detect(exp, tmp, index + 3, x, y, z)), index + 4, x, y, z);
	}
		
	if (exp[index] == 'A')
	{
		cout << "exp[index]=" << exp[index] << " tmp =" << tmp << endl;
		return detect(exp, AND(tmp, detect(exp, tmp, index + 3, x, y, z)), index + 4, x, y, z);
	}
		
	if (exp[index] == 'O')
	{
		cout << "exp[index]=" << exp[index] << " tmp =" << tmp << endl;
		return detect(exp, OR(tmp, detect(exp, tmp, index + 2, x, y, z)), index + 3, x, y, z);
	}
		
	cout << "exp[index]=" << exp[index] << " tmp =" << tmp << endl;
	return detect(exp, char_to_bool(exp[index], x, y, z), index + 1, x, y, z);
}



void main()
{
	char exp_test[] = { 'N','O','T','x','O','R','y','A','N','D','z', '\0' };
	char exp_test2[] = { 'N','O','T','x','O','R','N','O','T','y','A','N','D','z', '\0' };
	char exp_test3[] = { 'x','O','R','y','A','N','D','z', '\0' };

	//char exp[50];
	//cin >> exp;
	int x, y, z;
	for (int i = 0; i < 8; i++)
	{
		x = i / 4; y = i % 4 / 2; z = i % 2;
		cout << x << y << z << detect(exp_test2, false, 0, x, y, z) << endl;
	}
}

