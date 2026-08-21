#include "mySort.h"

void merge(int arr[], unsigned int l, unsigned int m, unsigned int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    /* copy data to temp arrays */
    for (i = 0; i < n1; i++) {
        myCopy(&arr[l + i], &L[i]);
    }
    for (j = 0; j < n2; j++) {
        myCopy(&arr[m + 1 + j], &R[j]);
    }

    i = 0;
    j = 0;
    k = l;

    /* merge temp arrays back into arr[l..r] */
    while (i < n1 && j < n2) {
        if (myCompare(L[i], R[j]) <= 0) {
            myCopy(&L[i], &arr[k]);
            i++;
        } else {
            myCopy(&R[j], &arr[k]);
            j++;
        }
        k++;
    }

    /* copy remaining elements */
    while (i < n1) {
        myCopy(&L[i], &arr[k]);
        i++;
        k++;
    }

    while (j < n2) {
        myCopy(&R[j], &arr[k]);
        j++;
        k++;
    }
}

void mySort(int array[], unsigned int first, unsigned int last)
{
    if (first < last) {
        unsigned int middle = first + (last - first) / 2;
        mySort(array, first, middle);
        mySort(array, middle + 1, last);
        merge(array, first, middle, last);
    }
}
