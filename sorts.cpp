int binarySearch(int a[], int item, int low, int high) {
    if (high <= low)
        return (item > a[low])? (low + 1): low;

    int mid = (low + high)/2;

    if(item == a[mid])
        return mid+1;

    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}

// Function to sort an array a[] of size 'n'
void binary_insertionSort(int a[], int n, long long &iterations, long long &compares) {
    int i, loc, j, selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];

        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);
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

void insertion_sort (int arr[], int length, long long &iterations, long long &compares) {
    int j, temp;
    for (int i = 0; i < length; i++) {
        j = i;

        while (j > 0 && arr[j] < arr[j-1]) {
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
void ShellSort(int a[], int n, long long &iterations, long long &compares)
{
    int i, j, k, temp;
    // Gap 'i' between index of the element to be compared, initially n/2.
    for(i = n/2; i > 0; i = i/2) {
        for(j = i; j < n; j++) {
            for(k = j-i; k >= 0; k = k-i) {
                iterations++;
                compares++;
                // If value at higher index is greater, then break the loop.
                if(a[k+i] >= a[k]) {
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

void quickSort(int *numbers, int left, int right, long long &iterations, long long &compares) {

    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];

    while (left < right) {
      while ((numbers[right] >= pivot) && (left < right)) {
        right--;
        iterations++;
      }
      if (left != right) {
        numbers[left] = numbers[right];
        left++;
        compares++;
      }
      while ((numbers[left] <= pivot) && (left < right)) {
        left++;
        iterations++;
      }
      if (left != right) {
        numbers[right] = numbers[left];
        right--;
        compares++;
      }
      iterations++;
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    compares++;

//    static long long *iters_comps = new long long[2];
//    iters_comps[0] = 0;
//    iters_comps[1] = 0;

    if (left < pivot)
      quickSort(numbers, left, pivot - 1, iterations, compares);
    if (right > pivot)
      quickSort(numbers, pivot + 1, right, iterations, compares);

//    if (!(left < pivot) && !(right > pivot)) {
//        iters_comps[0] = iterations;
//        iters_comps[1] = compares;
//        return iters_comps;
//    }

//    return iters_comps;

}
