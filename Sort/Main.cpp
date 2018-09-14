#include "Sort.h"

int main() {
	Sort s;

	//cout << "Insertion Sort Descend: " << endl;
	//s.Init();
	//s.insertionSortDescend();
	//s.Print();
	//cout << endl;

	//cout << "Insertion Sort Ascend: " << endl;
	//s.Init();
	//s.insertionSortAscend();
	//s.Print();
	//cout << endl;

	//cout << "Merge Sort Descend: " << endl;
	//s.Init();
	//s.mergeSortDescend(0, Length-1);
	//s.Print();
	//cout << endl;

	//cout << "Merge Sort Ascend: " << endl;
	//s.Init();
	//s.mergeSortAscend(0, Length-1);
	//s.Print();
	//cout << endl;

	//cout << "Shell Sort Ascend: " << endl;
	//s.Init();
	//s.shellSort(Length);
	//s.Print();
	//cout << endl;

	//cout << "Quick Sort Ascend: " << endl;
	//s.Init();
	//s.quickSort(0, Length - 1);
	//s.Print();
	//cout << endl;

	//cout << "Quick Sort Ascend not Recursive: " << endl;
	//s.Init();
	//s.quickSortNotR(0, Length - 1);
	//s.Print();
	//cout << endl;

	//cout << "Heap Sort Ascend: " << endl;
	//s.Init();
	//s.HeapSort();
	//s.Print();
	//cout << endl;

	cout << "Counting Sort Ascend: " << endl;
	s.Init();
	s.countSort();
	s.Print();
	cout << endl;
	return 0;
}