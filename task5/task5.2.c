#include <stdio.h>

void evilScanf(int* p0, int* p1, int* p2) {
    int n0, n1, n2;
    scanf("%d%d%d", &n0, &n1, &n2);
    int a = *p0, b = *p1, c = *p2;
    *p0 = n0;
    if (n0 > 0) {
        *p1 = n1;
        *p2 = n2;
    } else {
        *p1 = a;
        *p2 = n0 * n1 * n2 * b * c;
    }
}

int  main() {
    int a = 0, b = 1, c = 2;
    evilScanf(&a, &b, &c);
    printf("%d %d %d", a, b, c);
    return 0;
}