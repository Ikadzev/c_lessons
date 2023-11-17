#include <stdio.h>
#include <stdlib.h>

void nullCheck(void* ptr) {
    if (ptr == NULL) {
        printf("OoM!");
        exit(0);
    }
}

int* scanArr(size_t* size_addr) {
    printf("N? ");
    size_t n;
    scanf("%llu", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    nullCheck(arr);
    printf("Array? ");
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    *size_addr = n;
    return arr;
}

void removeSubArr(size_t n, int* arr, size_t n1, int* arr1, size_t* size_addr) {
    if (n1 <= n) {
        for (size_t i = 0; i <= n; i++) {
            if (arr[i] == arr1[0]) {
                int f = 1;
                for (size_t j = 1; j < n1; j++) {
                    if (arr[i + j] != arr1[j]) {
                        f = 0;
                        break;
                    }
                }
                if (f == 1) {
                    for (size_t j = i; j < n; j++) {
                        arr[j] = arr[j+n1];
                    }
                    arr = (int*) realloc(arr, (n-n1) * sizeof(int));
                    nullCheck(arr);
                    n -= n1;
                }
            }
        }
    }
    *size_addr = n;
}

int main() {
    size_t n, n1;
    int* arr = scanArr(&n);
    int* arr1 = scanArr(&n1);

    size_t n_old, n_new;
    do {
        removeSubArr(n, arr, n1, arr1, &n);
        n_old = n;

        removeSubArr(n, arr, n1, arr1, &n);
        n_new = n;
    } while (n_old != n_new);
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    free(arr1);
}