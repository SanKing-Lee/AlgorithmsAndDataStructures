#pragma once

#include <iostream>

const int Length = 10;

using namespace std;

class Sort {
private:
	int* a;
public:
	Sort() { Init(); };
	~Sort() { delete a; };
	void Init();
	void Print();
	void insertionSortDescend();
	void insertionSortAscend();
	void mergeSortDescend(int l,  int r);
	void mergeSortAscend(int l, int r);
	void mergeDescend(int l, int m, int r);
	void mergeAscend(int l, int m, int r);
};