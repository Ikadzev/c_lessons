#include <stdio.h>
#include <math.h>
int isPrime();

int main() {
    unsigned long long n;
    printf("N? ");
    scanf("%llu", &n);
    if (n < 2) {
        printf("Error");
        return -1;
    }
    for (unsigned long long x = 2; x <= n; x++) {
        if (isPrime(x)) {
            printf("%llu ", x);
        }
    }
    return 0;
}

int isPrime(unsigned long long number) {
    int f = 1;
    for (unsigned long long i = 2; i < (int)sqrt(number) + 1; i++) {
        if (number % i == 0) {
            f = 0;
        }
    }
    return f;
}