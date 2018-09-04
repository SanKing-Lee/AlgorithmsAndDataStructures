#include "Sort.h"

int main() {
	Sort s;
	cout << "Insertion Sort Descend: " << endl;
	s.insertionSortDescend();
	s.Print();
	cout << endl;
	s.Init();
	cout << "Insertion Sort Ascend: " << endl;
	s.insertionSortAscend();
	s.Print();
	cout << endl;
	s.Init();
	cout << "Merge Sort Descend: " << endl;
	s.mergeSortDescend(0, Length-1);
	s.Print();
	cout << endl;
	s.Init();
	cout << "Merge Sort Ascend: " << endl;
	s.mergeSortAscend(0, Length-1);
	s.Print();
	return 0;
}