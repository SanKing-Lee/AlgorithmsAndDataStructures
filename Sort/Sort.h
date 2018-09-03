#pragma once

#include <iostream>

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
};