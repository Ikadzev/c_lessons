#include <stdio.h>
#include <stdlib.h>

void nullCheck(void* ptr) {
    if (ptr == NULL) {
        printf("OoM!");
        exit(0);
    }
}

void fillArr(int** arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        arr[i][i] = 1;
        arr[i][0] = 1;
        for (size_t j = 1; j < i; j++) {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
}

void printArr(int** arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < 1+i; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("N? ");
    size_t n;
    scanf("%llu", &n);
    int** arr = (int**) malloc(n * sizeof(int*));
    nullCheck(arr);
    for (size_t i = 0; i < n; i++) {
        arr[i] = (int*) malloc((1+i) * sizeof(int));
        nullCheck(arr[i]);
    }
    fillArr(arr, n);
    printArr(arr, n);
    for (size_t i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    printf("Arrays are freed!");
}