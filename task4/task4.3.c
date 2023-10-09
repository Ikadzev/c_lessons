#include <stdio.h>

int nod(int x, int y) {
    while (x != y) {
        if (x > y) {
            x -= y;
        } else {
            y -= x;
        }
    }
    return x;
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