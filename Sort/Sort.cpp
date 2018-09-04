#include "Sort.h"

void Sort::Init()
{
	a = new int[Length];
	for (int i = 0; i < Length; i++)
	{
		int b = rand() % 30;
		a[i] = b;
		cout << b << " ";
	}
	cout << endl;
}

void Sort::Print()
{
	for (int i = 0; i < Length; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void Sort::insertionSortDescend()
{
	int key;
	for (int i = 1; i < Length; i++)
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
		cout << "Sorting: ";
		Print();
	}

}

void Sort::insertionSortAscend()
{
	int key;
	for (int i = 1; i < Length; i++) {
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
		cout << "Sorting: ";
		Print();
	}
}

void Sort::mergeSortDescend(int l, int r)
{
	//if l< r, the array has been divided to the smallest array
	if (l != r)
	{
		int m = floor((float)(l + r) / 2);
		mergeSortDescend(l, m);
		mergeSortDescend(m+1, r);
		mergeDescend(l, m, r);
		//mergeAscend(l, m, r);
	}
}

void Sort::mergeSortAscend(int l, int r) {
	//if l< r, the array has been divided to the smallest array
	if (l != r)
	{
		int m = floor((float)(l + r) / 2);
		mergeSortAscend(l, m);
		mergeSortAscend(m + 1, r);
		mergeAscend(l, m, r);
		//mergeAscend(l, m, r);
	}
}

void Sort::mergeDescend(int l, int m, int r)
{
	//the length of left array
	int len1 = m - l + 1;
	//the length of right array
	int len2 = r - m;
	int *left = new int[len1 + 1];
	int *right = new int[len2 + 1];
	left[len1] = -1;
	right[len2] = -1;
	for (int i = 0; i < len1; i++)
	{
		left[i] = a[l + i];
	}
	for (int i = 0; i < len2; i++)
	{
		right[i] = a[m + i + 1];
	}
	int i = 0;
	int j = 0;
	cout << "Sorting:";
	for (int k = l; k <= r; k++)
	{
		if (left[i] > right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		cout << a[k] << " ";
	}
	cout << endl;
	delete []left;
	delete []right;
}

void Sort::mergeAscend(int l, int m, int r)
{
	//the length of left array
	int len1 = m - l + 1;
	//the length of right array
	int len2 = r - m;
	int *left = new int[len1 + 1];
	int *right = new int[len2 + 1];
	left[len1] = 1000000;
	right[len2] = 1000000; 
	cout << "Sorting: ";
	for (int i = 0; i < len1; i++)
	{
		left[i] = a[l + i];
	}
	for (int i = 0; i < len2; i++)
	{
		right[i] = a[m + i + 1];
	}
	int i = 0;
	int j = 0;
	for (int k = l; k <= r; k++)
	{
		if (left[i] < right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		cout << a[k] << " ";
	}
	cout << endl;
	delete []left;
	delete []right;
}
