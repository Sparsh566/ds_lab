
#include <stdio.h>

void main() {
    int a[20], n, j, temp, pos;
    printf("Enter value of n : ");
    scanf("%d", &n);
    
    // write the for loop to read array elements
    for (int i = 0; i < n; i++) {
        printf("Enter element for a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    // write the for loop to display array elements before sorting
    printf("Before sorting the elements in the array are\n");
    for (int i = 0; i < n; i++) {
        printf("Value of a[%d] = %d\n", i, a[i]);
    }

    // write the code to sort elements
    for (int i = 1; i < n; i++) {
        temp = a[i];
        pos = i;

        while (pos > 0 && a[pos - 1] > temp) {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = temp;
    }

    // write the for loop to display array elements after sorting
    printf("After sorting the elements in the array are\n");
    for (int i = 0; i < n; i++) {
        printf("Value of a[%d] = %d\n", i, a[i]);
    }
}
