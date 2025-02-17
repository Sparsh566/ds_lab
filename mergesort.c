
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int nl = mid - left + 1;
    int n2 = right - mid;

    int leftArr[nl], rightArr[n2];

    for (int i = 0; i < nl; i++) {
        leftArr[i] = arr[left + i];
    }
    
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    
    while (i < nl && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
}

while (j < n2) {
    arr[k] = rightarr[j];
    j++;
    k++;
}

void splitAndMerge(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        splitAndMerge(arr, left, mid);
        splitAndMerge(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
