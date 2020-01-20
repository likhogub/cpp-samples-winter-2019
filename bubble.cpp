int main()
{
	//------Var's section--------------------------------//

	int seq[] = { 1, 3, 2, 4, 6, 5, 9, 7, 10 };

	//------Show Seq----------------------------------//

	for (int i = 0; i < 9; i++) cout << seq[i] << " ";
	cout << endl;
	//------Algo---------------------------------//

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (seq[j - 1] > seq[j])
			{
				int tmp = seq[j];
				seq[j] = seq[j - 1];
				seq[j - 1] = tmp;
			}

	//------Show Seq----------------------------------//

	for (int i = 0; i < 9; i++) cout << seq[i] << " ";


}
