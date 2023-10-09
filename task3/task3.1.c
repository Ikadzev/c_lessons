#include <stdio.h>

int main() {
    unsigned short x;
    unsigned short n;
    int f;
    printf("N? ");
    scanf("%hu", &n);

    for(x = 0; x <= n; x++) {
        if (x % 15 == 0) {
            printf("fizz buzz ");
            f++;
        }
        if (x % 3 == 0 && f == 0) {
            printf("fizz ");
            f++;
        }
        if (x % 5 == 0 && f == 0) {
            printf("buzz ");
            f++;
        }
        if (f == 0) {
            printf("%hu ", x);
        }
        f = 0;
    }
}