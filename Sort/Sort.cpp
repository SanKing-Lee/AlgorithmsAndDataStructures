#include "Sort.h"

void Sort::Init()
{
	for (int i = 0; i < Length; i++)
	{
		a[i] = rand() % UpBound;

		cout <<a[i] << " ";
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

void Sort::Swap(int l, int r)
{
	int temp = a[l];
	a[l] = a[r];
	a[r] = temp;
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
	//the small array, its length is len1 + 1, because we need the last integer to be a canary
	int *left = new int[len1 + 1];
	int *right = new int[len2 + 1];
	//the last integer was set to the minium number
	left[len1] = -1;
	right[len2] = -1;
	//copy the left subarray
	for (int i = 0; i < len1; i++)
	{
		left[i] = a[l + i];
	}
	//copy the right subarray
	for (int i = 0; i < len2; i++)
	{
		right[i] = a[m + i + 1];
	}
	//the counter in the left and right array
	int i = 0;
	int j = 0;
	cout << "Sorting:";
	for (int k = l; k <= r; k++)
	{
		//compare the present integer in left subarray and that in right subarray
		//set the present array integer to the bigger one
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
	//delete the new arrays
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

//insertion sort sublist
void Sort::shellInsert(int n, int incree)
{
	int key;
	//the last position of the sublist 
	//march down the adjacent sublists
	for (int i = n - 1; i >= incree; i -= incree) {
		//insertion sort each element of the sublist
		//march down sublist from tail to head
		int j;
		//insertion sort
		for (j = i - incree; j >= 0; j -= incree) {
			key = a[j];
			int k;
			//march down the elements after the present element
			//if march down the sublist from head to tail 
			//march down elemets after  the present element
			for (k = j; k < i; k += incree) {
				//if the previous element is smaller than the present element
				//the present element was set to the previous element
				//ascend, if >, descend
				if (a[k+incree] < key) {
					a[k] = a[k + incree];
				}
				//if not, break;
				else
					break;
			}
			a[k] = key;
		}
		cout << "Sorting: ";
		Print();
	}
}

void Sort::shellSort(int n)
{
	for (int i = n / 2; i > 2; i /= 2) {
		for (int j = 0; j < i; j++) {
			cout << "i = " << i << ": " << endl;
			cout << "j = " << j << ": " << endl;
			shellInsert(n - j, i);
		}
	}
	//the last sort for the whole array
	cout << "i = " << 2 << ": " << endl;
	shellInsert(n, 1);
}

void Sort::quickSort(int left, int right)
{
	if (left >= right)
		return;
	int index = partSort(left, right);
	quickSort(left, index - 1);
	quickSort(index + 1, right);
}

int Sort::partSort(int left, int right)
{
	int pivot = right;
	while (left < right) {
		while (left < right && a[left] < a[pivot]) {
			left++;
		}
		while (left < right && a[right] >= a[pivot]) {
			right--;
		}
		Swap(left, right);
		cout << "Left: " << left << " Right: " << right << endl;
		cout << "Sorting: ";
		Print();
		cout << endl;
	}

	Swap(left, pivot);
	cout << "Sorting: ";
	Print();
	return left;
}

void Sort::quickSortNotR(int left, int right)
{
	stack<int> s;
	s.push(left);
	s.push(right);
	while (!s.empty()) {
		int r = s.top();
		s.pop();
		int l = s.top();
		s.pop();
		int index = partSort(l, r);
		if (index - 1 > l)
		{
			s.push(l);
			s.push(index - 1);
		}
		if (index + 1 < r) {
			s.push(index + 1);
			s.push(r);
		}
	}
}

//Heap Sort
int Sort::getParent(int i)
{
	return (int)floor(i / 2);
}

int Sort::getLeftChild(int i)
{
	if (i == 0)
		return 1;
	return 2 * i + 1;
}

int Sort::getRightChild(int i)
{
	if (i == 0)
		return 2;
	return 2 * i + 2;
}

void Sort::MaxHeapify(int i)
{
	int l = getLeftChild(i);
	int r = getRightChild(i);
	int Largest;
	//get the Largest element in this child tree
	if (l <= heap_size && a[l] > a[i]) {
		Largest = l;
	}
	else
		Largest = i;
	if (r <= heap_size && a[r] > a[Largest])
	{
		Largest = r;
	}
	//if the largest element is not the root, swap their position and go on maxHeapify on the
	//present largest elment
	if (Largest != i) {
		Swap(i, Largest);
		MaxHeapify(Largest);
	}
}

void Sort::BuildMaxHeap()
{
	heap_size = Length - 1;
	array_length = Length - 1;
	//march down all the root elements
	for (int i = (int)floor(array_length / 2); i >= 0; i--) {
		MaxHeapify(i);
	}
}

void Sort::HeapSort()
{
	BuildMaxHeap();
	Print();
	for (int i = array_length; i >= 1; i--) {
		Swap(i, 0);
		heap_size--;
		MaxHeapify(0);
		Print();
	}
}

void Sort::countSort()
{
	int b[Length];
	int c[UpBound]; 
	//initial the c array
	for (int i = 0; i < UpBound; i++)
	{
		c[i] = 0;
	}

	for (int i = 0; i < Length; i++)
	{
		c[a[i]]++;
	}
	for (int i = 1; i < UpBound; i++) {
		c[i] = c[i] + c[i - 1];
	}
	for (int i = 0; i < Length; i++)
	{
		//此处与书上的伪代码不一致，因为书上的数组是从1开始的
		c[a[i]]--;
		b[c[a[i]]] = a[i];
	}
	for (int i = 0; i < Length; i++)
	{
		a[i] = b[i];
	}
}
