#include <stdio.h>
int isLuck();

int main() {
    unsigned long l;
    unsigned long r;
    printf("L? ");
    scanf("%lu", &l);
    printf("R? ");
    scanf("%lu", &r);
    while (l > r) {
        printf("L больше R. Повторите ввод\n");
        printf("L? ");
        scanf("%lu", &l);
        printf("R? ");
        scanf("%lu", &r);
    }
    for (l; l < r; l++) {
        if (isLuck(l) == 1) {
            printf("%d\n", l);
        }
    }
}

int isLuck(unsigned long number) {
    int m[6];
    if (number > 999999) {return -1;}
    for (int i = 0; number != 0; i++) {
        m[i] = number % 10;
        number /= 10;
    }
    if (m[0] + m[1] + m[2] == m[3] + m[4] + m[5]) {
        return 1;
    } else {
        return 0;
    }
}