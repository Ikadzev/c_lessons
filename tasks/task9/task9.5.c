#include <stdio.h>
#include <stdlib.h>

void nullCheck(void* ptr) {
    if (ptr == NULL) {
        printf("OoM!");
        exit(0);
    }
}

int* scanArr(size_t* size_addr) {
    printf("Array? ");
    int* arr = NULL;
    size_t n = 0;
    do {
        n++;
        arr = (int*) realloc(arr, n * sizeof(int));
        nullCheck(arr);
        scanf("%d", &arr[n - 1]);
    } while (arr[n-1] != 0);
    *size_addr = n;
    return arr;
}

int main() {
    size_t* n;
    int* arr = scanArr(n);
    for (size_t i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }
}