#include <stdio.h>

int swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int x = 12, y = 8;
    swap(&x, &y);
    printf("X = %d, Y = %d", x, y);
}