#ifndef SORTS_H
#define SORTS_H

#include "sorts.cpp"

int binarySearch(int a[], int item, int low, int high, long long &iterations, long long &compares);
void binary_insertionSort(int a[], int n);

void insertion_sort (int arr[], int length, long long &iterations, long long &compares);

void ShellSort(int a[], int n, long long &iterations, long long &compares);

void quickSort(int *numbers, int left, int right, long long &iterations, long long &compares);

#endif // SORTS_H
