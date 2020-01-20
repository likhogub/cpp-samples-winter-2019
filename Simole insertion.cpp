#include <iostream>
using namespace std;


int main()
{
	//------Var's section--------------------------------//

	int seq[] = { 1, 3, 2, 4, 6, 5, 9, 7, 10 };
	int ops = 0;
	//------Show Seq----------------------------------//

	for (int i = 0; i < 9; i++) cout << seq[i] << " ";
	cout << endl;

	//------Algo---------------------------------//
	for (int k = 0; k < 9; k++)
		for (int i = 0; i < 9; i++)
			for (int j = i; j > 0 && seq[j - 1] > seq[i]; j--)
			{ 
				int tmp = seq[j];
				seq[j] = seq[j - 1];
				seq[j - 1] = tmp;
				ops++;
			}

	//------Show Seq----------------------------------//

	for (int i = 0; i < 9; i++) cout << seq[i] << " ";
	cout << endl << ops << endl;

}
