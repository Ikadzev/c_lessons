#include <stdio.h>
#include <math.h>
int isPrime();

int main() {
    unsigned long long n;
    printf("N? ");
    scanf("%llu", &n);
    while (n < 2) {
        printf("N меньше двух. Повторите ввод: ");
        scanf("%llu", &n);
    }
    for (unsigned long long x = 2; x <= n; x++) {
        if (isPrime(x) == 0) {printf("%llu ", x);}
    }
}

int isPrime(unsigned long long number) {
    int f = 0;
    for (unsigned long long i = 2; i < (int)sqrt(number) + 1; i++) {
        if (number % i == 0) {f = 1;}
    }
    return f;
}