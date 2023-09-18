#include <stdio.h>

int nod(int x, int y) {
    int max_d = 1;
    for (int i = 1; (i <= x && i <= y); i++) {
        if (x % i == 0 && y % i == 0) {max_d = i;}
    }
    return max_d;
}

int main() {
    int x, y;
    printf("X? ");
    scanf("%d", &x);
    printf("Y? ");
    scanf("%d", &y);
    printf("NOD = %d", nod(x, y));
    return 0;
}