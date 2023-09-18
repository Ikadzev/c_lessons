#include <stdio.h>

int main() {
    unsigned long n;
    unsigned long y = 0;
    unsigned long z;
    unsigned long x = 0;
    printf("N? ");
    scanf("%lu", &n);

    while (y < n) {
        for (z = 0; z < (y + 1); z++) {
            printf("%lu ", x);
            x++;
        }
        printf("\n");
        y++;
    }
    return 0;
}