#include <stdio.h>

// Recursive function to compute Fibonacci
int fibonacci_recursive(int n) 
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Driver function
int main() 
{
    int n = 10;  // Change this to compute different Fibonacci numbers
    
    printf("Fibonacci series (Recursive) up to %d terms:\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci_recursive(i));

    return 0;
}