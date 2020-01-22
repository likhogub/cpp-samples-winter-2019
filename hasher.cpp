#include <iostream>
using namespace std;




struct Table
{
	char name[10];
	int refer_to = -1;
};
Table table[20];

int ord(char a)
{
	char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int i = 0;
	while (a != alphabet[i]) i++;
	return i;
}

int hasher(char name[])
{
	int i = 0;
	int mult = 1;
	while (name[i] != '\0')
	{
		int val = ord(name[i]);
		mult *= (val + i);
		i++;
	}
	int value = mult % 20;
	if (table[value].refer_to == -1)
	{
		int k = 0;
		while (name[k] != '\0')
		{
			table[value].name[k] = name[k];
			k++;
		}
		table[value].refer_to = value + 1 % 20;
	}
	else 
	{
		while (table[value].refer_to != -1) value = table[value].refer_to;
		int k = 0;
		while (name[k] != '\0')
		{
			table[value].name[k] = name[k];
			k++;
		}
		table[value].refer_to = value + 1 % 20;
	}
	return value;
}

void main()
{
	char test[] = { 'l', 'o', 'l', '\0' };
	char test1[] = { 'l', 'l', 'l', '\0' };
	char test2[] = { 'l', 'o', 'l', '\0' };
	int x = hasher(test);
	cout << x << endl;
	x = hasher(test1);
	cout << x << endl;
	x = hasher(test2);
	cout << x << endl;

}
