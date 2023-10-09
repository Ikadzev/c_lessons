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

int* concat(size_t n, int* arr, size_t n1, int* arr1) {
    int* arr2 = (int*) malloc((n + n1) * sizeof(int));
    nullCheck(arr2);
    for (size_t i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }
    for (size_t i = 0; i < n1; i++) {
        arr2[i + n] = arr1[i];
    }
    return arr2;
}

int main() {
    size_t n;
    int* arr = scanArr(&n);
    
    size_t n1;
    int* arr1 = scanArr(&n1);

    int* arr2 = concat(n, arr, n1, arr1);
    for (size_t i = 0; i < (n + n1); i++) {
        printf("%d ", arr2[i]);
    }
    free(arr);
    free(arr1);
    free(arr2);
}