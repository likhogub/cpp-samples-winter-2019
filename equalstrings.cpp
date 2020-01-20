#include <iostream>
using namespace std;


int main()
{
	//------Var's section--------------------------------//

	char phrase1[] = { 'l','o','l','e','r', '\0' };
	char phrase2[] = { 'l','o','l','e','r', '\0' };
	char phrase3[] = { 'k','e','k','e','r', '\0' };

	//------Algo---------------------------------//
	int i = 0;
	bool equal = true;
	while (equal && phrase1[i] != '\0' && phrase2[i] != '\0')
	{
		if (phrase1[i] != phrase2[i]) equal = false;
		i++;
	}
	if (phrase1[i] == '\0' && phrase2[i] == '\0' && equal) cout << "Equal" << endl;
	else cout << "Not equal" << endl;
}
