/*Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left*/
#include <stdio.h>

int main() {
    int n, pos, i;

    // Read the number of elements
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // Read n integers into the array
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the 1-based position to delete
    scanf("%d", &pos);

    // Validate position and shift elements to the left
    if (pos >= 1 && pos <= n) {
        for (i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        // Print the updated array with n-1 elements
        for (i = 0; i < n - 1; i++) {
            printf("%d%s", arr[i], (i == n - 2) ? "" : " ");
        }
        printf("\n");
    }

    return 0;
}
