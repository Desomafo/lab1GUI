#ifndef STRUCTSORTS_H
#define STRUCTSORTS_H

#include "structsorts.cpp"
#include "mainwindow.h"

int binarySearchYear(int a[], int item, int low, int high, long long &iterations, long long &compares);
int binarySearchPopulation(int a[], int item, int low, int high, long long &iterations, long long &compares);
void insertionSortPopulation(MainWindow::city arr[], int length, long long &iterations, long long &compares);
void insertionSortYear(MainWindow::city arr[], int length, long long &iterations, long long &compares);
void binaryInsertionSortPopulation(MainWindow::city a[], int n, long long &iterations, long long &compares);
void binaryInsertionSortYear(MainWindow::city a[], int n, long long &iterations, long long &compares);
void shellSortPopulation(MainWindow::city a[], int n, long long &iterations, long long &compares);
void shellSortYear(MainWindow::city a[], int n, long long &iterations, long long &compares);
void quickSortPopulation(MainWindow::city *numbers, int left, int right, long long &iterations, long long &compares);
void quickSortYear(MainWindow::city *arr, int left, int right, long long &iterations, long long &compares);

#endif // STRUCTSORTS_H
