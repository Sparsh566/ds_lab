
#include <stdio.h>
#include <string.h>

void main() {
    char a[20][20];
    int n, i;
    char temp[20];
    printf("Enter value of n: ");
    scanf("%d", &n);

    // Write the code to read n strings.
    for (i = 0; i < n; i++) {
        printf("Enter string for a[%d]: ", i);
        scanf("%s", a[i]);
    }

    printf("Before sorting the strings in the array are:\n");
    // Write the code to print the strings before sorting
    for (i = 0; i < n; i++) {
        printf("String at a[%d] = %s\n", i, a[i]);
    }

    // Write the code to sort the strings using bubble sort technique
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(a[j], a[j + 1]) > 0) {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }

    printf("After sorting the strings in the array are:\n");
    // Write the code to print the strings after sorting
    for (i = 0; i < n; i++) {
        printf("String at a[%d] = %s\n", i, a[i]);
    }
}
