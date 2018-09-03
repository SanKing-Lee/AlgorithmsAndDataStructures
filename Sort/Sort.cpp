#include "Sort.h"

void Sort::Init()
{
	a = new int[10];
	for (int i = 0; i < 10; i++)
	{
		int b = rand() % 30;
		a[i] = b;
		cout << b << " ";
	}
	cout << endl;
}

void Sort::Print()
{
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void Sort::insertionSortDescend()
{
	int key;
	for (int i = 1; i < 10; i++)
	{
		key = a[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			//if this number is less than the present number, put it back
			if (a[j] < key)
			{
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = key;
	}

}

void Sort::insertionSortAscend()
{
	int key;
	for (int i = 1; i < 10; i++) {
		key = a[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (a[j] > key)
			{
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = key;
	}
}
