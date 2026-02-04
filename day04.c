/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays
*/
#include <stdio.h>

int main() {
    int n, i;
    
    // Read array size
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    
    // Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Two-Pointer Approach
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        // Swap elements at left and right pointers
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        // Move pointers closer to the middle
        left++;
        right--;
    }
    
    // Print the reversed array
    for (i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");
    
    return 0;
}
