#include <stdio.h>
#include <math.h>

int main() {
    unsigned long x;
    unsigned long y = 0;
    unsigned long n;
    //int f;
    printf("N? ");
    scanf("%lu", &n);

    while (y < n) {
        x = y*n;
        while (x < y*n+n) {
            printf("%lu\t", x);
            x = x + 1;
        }
        printf("\n");
        y = y + 1;
    }
    return 0;
}