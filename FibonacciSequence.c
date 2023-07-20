// WAP to find fibonacci sequences using a recursive function.
#include <stdio.h>

int fibonacci_recursive(int n) {
    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return -1; // Indicating an error
    } else if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int main() {
    int n;

    printf("Enter the value of 'n' to generate the Fibonacci sequence: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1; // Indicating an error
    } else {
        printf("Fibonacci sequence up to the %d-th term:\n", n);
        for (int i = 1; i <= n; i++) {
            printf("%d ", fibonacci_recursive(i));
        }
        printf("\n");
    }

    return 0;
}
