#include <iostream>
using namespace std;


int main()
{
	//------Var's section--------------------------------//

	char phrase[50];
	char phrase1[] = { 'l','o','l','e','r', '\0' };
	char phrase2[] = { 'k','e','k','e','r', '\0' };

	//------Algo---------------------------------//
	int i = 0;
	while (phrase1[i] != '\0')
	{
		phrase[i] = phrase1[i];
		i++;
	}
	int j = 0;
	while (phrase2[j] != '\0')
	{
		phrase[i] = phrase2[j];
		i++;
		j++;
	}
	for (int k = 0; k < i; k++) cout << phrase[k];
	cout << endl;
	
}
