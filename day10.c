/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000]; // Buffer for string input

    // Input: single line string
    if (scanf("%s", str) != 1) return 0;

    int n = strlen(str);
    int left = 0;
    int right = n - 1;
    int is_palindrome = 1; // Assume it's a palindrome (True)

    // Two-pointer comparison logic
    while (left < right) {
        if (str[left] != str[right]) {
            is_palindrome = 0; // Found a mismatch
            break;
        }
        left++;
        right--;
    }

    // Output: YES or NO
    if (is_palindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
