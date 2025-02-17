
#include <stdio.h>

void main() {
    int a[20], i, n, index, large, temp;

    printf("Enter value of n: ");
    scanf("%d", &n);

    // Write the code to read array elements
    for (i = 0; i < n; i++) {
        printf("Enter element for a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Before sorting the elements in the array are:\n");
    // Write the code to print the given array elements before sorting
    for (i = 0; i < n; i++) {
        printf("Value of a[%d] = %d\n", i, a[i]);
    }

    // Write the code for selection sort largest element method
    for (i = 0; i < n - 1; i++) {
        index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[index]) {
                index = j;
            }
        }
        // Swap the largest element with the first element
        if (index != i) {
            temp = a[i];
            a[i] = a[index];
            a[index] = temp;
        }
    }

    printf("After sorting the elements in the array are:\n");
    // Write the code to print the given array elements after sorting
    for (i = 0; i < n; i++) {
        printf("Value of a[%d] = %d\n", i, a[i]);
    }
}
