#include <stdio.h>

int main() {
    unsigned short age;
    int f;
    printf("Год? ");
    scanf("%hu", &age);
    if (age % 4 == 0) {
        if (age % 400 == 0) {
            printf("Год високосный");
            f = 1;
        }
        if ((age % 100 == 0) && (f != 1)) {
            printf("Год невисокосный (x %% 100 == 0)");
            f = 1;
        }
        if (f != 1) {
            printf("Год високосный");
        }
    } else {
        printf("Год невисокосный");
    }
}