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

int* findSubArr(size_t n, int* arr, size_t n1, int* arr1) {
    if (n1 <= n) {
        for (size_t i = 0; i <= n - n1; i++) {
            if (arr[i] == arr1[0]) {
                int f = 1;
                for (size_t j = 1; j < n1; j++) {
                    if (arr[i + j] != arr1[j]) {
                        f = 0;
                        break;
                    }
                }
                if (f == 1) {
                    return &arr[i];
                }
            }
        }
    }
    return NULL;
}

int main() {
    size_t n;
    int* arr = scanArr(&n);
    
    size_t n1;
    int* arr1 = scanArr(&n1);

    int* sub = findSubArr(n, arr, n1, arr1);
    printf("%d", sub);
    free(arr);
    free(arr1);
}