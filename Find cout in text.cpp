#include <iostream>
using namespace std;

int start = -1;
int stop = -1;

char text[] = { 'q','e','w','r','g','h','i','k','s','d','f','j','g','b','i','p','j','w','e','k','e','s','j','g','k','e','s','j','g','k','e','s','j','g','k','e','s','j','g','k','e','s','j','g','k','e','s','j','g','b','p','i','e','s','j','c','o',
					'u','t','<','<','s','a','r','c','i','s','k','e','k',
					';','g','h','e','g','h','i','u','e','h','g',   '\0' };

char target[] = { 'c','o','u','t','\0' };

void find()
{
	int i = 0;
	while ((target[0] != text[i]) && (target[1] != text[i + 1]) && (target[2] != text[i + 2]) && (target[3] != text[i + 3])) i++;
	start = i + 6;
	while (text[i] != ';') i++;
	stop = i;
	cout << start << " " << stop << endl;
}

void main()
{
	find();
	for (int i = start; i < stop; i++) cout << text[i];
}
