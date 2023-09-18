#include <stdio.h>

int del(int n) {
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {k++;}
    }
    return k;
}

int main() {
    int n;
    printf("N? ");
    scanf("%d", &n);
    printf("Number of divisors: %d", del(n));
    return 0;
}