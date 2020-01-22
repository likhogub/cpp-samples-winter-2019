#include <iostream>
using namespace std;

int arr[] = { 1, 0, 5, 2, 4, 3, 6 };
int size = 7;

void qsort(int *arr, int first, int last)
{
	cout << "first=" << first << " second=" << last << endl;
	int i = first;
	int j = last;
	int mid = arr[(first + last) / 2];
	while (arr[i] < mid) i++;
	while (arr[j] > mid) j--;
	while (j >= i)
	{
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
	if (j > first) qsort(arr, first, j + 1); 
	if (last > i) qsort(arr, i - 1, last);
}

void main()
{
	for (int i = 0; i < 7; i++) cout << arr[i] << " ";
	cout << endl;
	qsort(arr, 0, 6);
	for (int i = 0; i < 7; i++) cout << arr[i] << " ";
	cout << endl;
}
