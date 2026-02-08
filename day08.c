/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32 */
#include <stdio.h>

// Recursive function to compute a^b
long long power(int a, int b) {
    // Base case: any number to the power of 0 is 1
    if (b == 0) return 1;
    
    // Recursive step: a^b = a * a^(b-1)
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    
    // Input: two space-separated integers a and b
    if (scanf("%d %d", &a, &b) != 2) return 0;
    
    // Output: a raised to the power of b
    printf("%lld\n", power(a, b));
    
    return 0;
}
