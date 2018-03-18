#include "mainwindow.h"

int binarySearchYear(MainWindow::city a[], int item, int low, int high) {
    if (high <= low)
        return (item > a[low].foundationYear)? (low + 1): low;

    int mid = (low + high)/2;

    if(item == a[mid].foundationYear)
        return mid+1;

    if(item > a[mid].foundationYear)
        return binarySearchYear(a, item, mid+1, high);
    return binarySearchYear(a, item, low, mid-1);
}

// Function to sort an array a[] of size 'n'
void binaryInsertionSortYear(MainWindow::city a[], int n, long long &iterations, long long &compares) {
    int i, loc, j;
    MainWindow::city selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];

        // find location where selected sould be inseretd
        loc = binarySearchYear(a, selected.foundationYear, 0, j);
        compares+=3;

        // Move all elements after location to create space
        while (j >= loc) {
            iterations++;
            a[j+1] = a[j];
            j--;
        }
        iterations++;
        a[j+1] = selected;
    }
}

void insertionSortYear(MainWindow::city arr[], int length, long long &iterations, long long &compares) {
    int j;
    MainWindow::city temp;
    for (int i = 0; i < length; i++) {
        j = i;

        while (j > 0 && arr[j].foundationYear < arr[j-1].foundationYear) {
            iterations++;
            compares+=2;
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
     }
}

// A function implementing Shell sort.
void shellSortYear(MainWindow::city a[], int n, long long &iterations, long long &compares)
{
    int i, j, k;
    MainWindow::city temp;
    // Gap 'i' between index of the element to be compared, initially n/2.
    for(i = n/2; i > 0; i = i/2) {
        for(j = i; j < n; j++) {
            for(k = j-i; k >= 0; k = k-i) {
                iterations++;
                compares++;
                // If value at higher index is greater, then break the loop.
                if(a[k+i].foundationYear >= a[k].foundationYear) {
                    break;
                // Switch the values otherwise.
                } else {
                    temp = a[k];
                    a[k] = a[k+i];
                    a[k+i] = temp;
                }
            }
        }
    }
}

void quickSortYear(MainWindow::city *arr, int left, int right, long long &iterations, long long &compares) {
    MainWindow::city pivot, tmp;
    int i = left, j = right;
    pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j) {
        iterations++;
        while (arr[i].foundationYear < pivot.foundationYear) {
            i++;
            iterations++;
        }
        while (arr[j].foundationYear > pivot.foundationYear) {
            j--;
            iterations++;
        }
        if (i <= j) {
            compares++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    /* recursion */
    if (left < j)
        quickSortYear(arr, left, j, iterations, compares);
    if (i < right)
        quickSortYear(arr, i, right, iterations, compares);
}



int binarySearchPopulation(MainWindow::city a[], int item, int low, int high) {
    if (high <= low)
        return (item > a[low].population)? (low + 1): low;

    int mid = (low + high)/2;

    if(item == a[mid].population)
        return mid+1;

    if(item > a[mid].population)
        return binarySearchPopulation(a, item, mid+1, high);
    return binarySearchPopulation(a, item, low, mid-1);
}

// Function to sort an array a[] of size 'n'
void binaryInsertionSortPopulation(MainWindow::city a[], int n, long long &iterations, long long &compares) {
    int i, loc, j;
    MainWindow::city selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];

        // find location where selected sould be inseretd
        loc = binarySearchPopulation(a, selected.population, 0, j);
        compares+=3;

        // Move all elements after location to create space
        while (j >= loc) {
            iterations++;
            a[j+1] = a[j];
            j--;
        }
        iterations++;
        a[j+1] = selected;
    }
}

void insertionSortPopulation(MainWindow::city arr[], int length, long long &iterations, long long &compares) {
    int j;
    MainWindow::city temp;
    for (int i = 0; i < length; i++) {
        j = i;

        while (j > 0 && arr[j].population < arr[j-1].population) {
            iterations++;
            compares+=2;
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
     }
}

// A function implementing Shell sort.
void shellSortPopulation(MainWindow::city a[], int n, long long &iterations, long long &compares)
{
    int i, j, k;
    MainWindow::city temp;
    // Gap 'i' between index of the element to be compared, initially n/2.
    for(i = n/2; i > 0; i = i/2) {
        for(j = i; j < n; j++) {
            for(k = j-i; k >= 0; k = k-i) {
                iterations++;
                compares++;
                // If value at higher index is greater, then break the loop.
                if(a[k+i].population >= a[k].population) {
                    break;
                // Switch the values otherwise.
                } else {
                    temp = a[k];
                    a[k] = a[k+i];
                    a[k+i] = temp;
                }
            }
        }
    }
}

void quickSortPopulation(MainWindow::city *arr, int left, int right, long long &iterations, long long &compares) {
    MainWindow::city pivot, tmp;
    int i = left, j = right;
    pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j) {
        iterations++;
        while (arr[i].population < pivot.population) {
            i++;
            iterations++;
        }
        while (arr[j].population > pivot.population) {
            j--;
            iterations++;
        }
        if (i <= j) {
            compares++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    /* recursion */
    if (left < j)
        quickSortPopulation(arr, left, j, iterations, compares);
    if (i < right)
        quickSortPopulation(arr, i, right, iterations, compares);
}

