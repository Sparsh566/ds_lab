
#include <stdio.h>

void main() {
    int a[20], i, n, key, flag = 0, pos;
    printf("Enter value of n : ");
    scanf("%d", &n);
    // Write code to read array elements
    for(i = 0; i < n; i++) {
        printf("Enter element for a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    printf("Enter key element : ");
    scanf("%d", &key);
    // Write code for linear search process
    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            flag = 1;
            pos = i;
            break;
        }
    }
    if (flag == 1) { // Write the condition part
        printf("The key element %d is found at the position %d\n", key, pos); // Complete statement
    } else {
        printf("The key element %d is not found in the array\n", key); // Complete the statement
    }
}
