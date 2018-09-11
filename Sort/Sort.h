#pragma once

#include <iostream>
#include <stack>

const int Length = 8;

using namespace std;

class Sort {
private:
	int* a;

	//heap sort
	//Heap size
	int heap_size;
	//array length
	int array_length;
public:
	Sort() { };
	~Sort() { delete a; };
	//initialize the array
	void Init();
	//print the array
	void Print();
	//swap positions of two element
	void Swap(int l, int r);
	void insertionSortDescend();
	void insertionSortAscend();
	void mergeSortDescend(int l,  int r);
	void mergeSortAscend(int l, int r);
	void mergeDescend(int l, int m, int r);
	void mergeAscend(int l, int m, int r);
	void shellInsert(int n, int incree);
	void shellSort(int n);
	void quickSort(int left, int right);
	int partSort(int left, int right);
	void quickSortNotR(int left, int right);

	//Heap Sort
	int getParent(int i);
	int getLeftChild(int i);
	int getRightChild(int i);
	void MaxHeapify(int i);
	void BuildMaxHeap();
	void HeapSort();
};