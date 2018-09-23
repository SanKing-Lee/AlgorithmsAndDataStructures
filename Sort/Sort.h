#pragma once

#include <iostream>
#include <stack>
#include <cmath>

const int Length = 8;
const int UpBound = 20;
const int SingleDigitUpBound =  10;

using namespace std;

class Sort {
private:
    int a[Length];

    //heap sort
    //Heap size
    int heap_size;
    //array length
    int array_length;
public:
    Sort() { };
    ~Sort() {  };
    //initialize the array
    void Init();
    //print the array
    void Print();
    //swap positions of two element
    void Swap(int l, int r);
    //get the largest number

    //insertion Sort
    void insertionSortDescend();
    void insertionSortAscend();

    //merge Sort
    void mergeSortDescend(int l,  int r);
    void mergeSortAscend(int l, int r);
    void mergeDescend(int l, int m, int r);
    void mergeAscend(int l, int m, int r);

    //Shell Sort
    void shellInsert(int n, int incree);
    void shellSort(int n);

    //Quick Sort
    void quickSort(int left, int right);
    int partSort(int left, int right);
    void quickSortNotR(int left, int right);

    //Heap Sort
    int getParent(int i);
    int getLeftChild(int i);
    int getRightChild(int i);
    void MaxHeapify(int i);
    void BuildMaxHeap();
    void heapSort();

    //Count Sort
    void countSort();

    //Radix Sort
    void radixSort();
    void countSortforRadixSort(int d);
};
