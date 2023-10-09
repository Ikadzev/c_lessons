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
        int* nArr = (int*) malloc(n * sizeof(int));
        nullCheck(nArr);
        for (size_t i = 0; i < n - 1; i++) {
            nArr[i] = arr[i];
        }
        free(arr);
        arr = nArr;
        scanf("%d", &arr[n - 1]);
    } while (arr[n-1] != 0);
    *size_addr = n;
    return arr;
}

void printArr(size_t len, int arr[]) {
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void revertArr(size_t len, int arr[]) {
    for (size_t i = 0; i < (int) len / 2; i++) {
        int c = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = c;
    }
}

int maxInArr(size_t len, int arr[]) {
    int max = arr[0];
    for (size_t i = 1; i < len; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int findInArr(size_t len, int arr[0], int x) {
    for (size_t i = 0; i < len; i++) {
        if (x == arr[i]) {
            return i;
        }
    }
    return -1;
}

void extractDigits(size_t len, int arr[0], int n) {
    int len_n = 0;
    for (int i = n; i != 0; i /= 10) {
        len_n++;
    }
    int extr[len_n];
    for (int i = 0; i < n; i++) {
        extr[i] = n % 10;
        n /= 10;
    }
    printf("%d", extr[3]);
    revertArr(len_n, extr);
    for (int i = 0; i < len_n && i < len; i++) {
        arr[i] = extr[i];
    }
}

void compareArrays(size_t l1, size_t l2, int a1[], int a2[0]) {
    for (size_t i = 0; i < l1 && i < l2; i++) {
        if (a1[i] < a2[i]) {
            printf("First array is smaller than the second\n");
            return;
        } else
        if (a2[i] < a1[i]) {
            printf("First array is bigger than the second\n");
            return;
        }
    }
    if (l1 < l2) {
        printf("First array is smaller than the second\n");
        return;
    } else
    if (l2 < l1) {
        printf("First array is bigger than the second\n");
        return;
    }
    printf("Arrays are equal\n");
}


int main() {
    size_t n;
    int* arr = scanArr(&n);
    
    size_t n1;
    int* arr1 = scanArr(&n1);

    int i;
    while (1) {
        printf("Choose function:\n");
        printf("1. printArr\n");
        printf("2. revertArr\n");
        printf("3. maxInArr\n");
        printf("4. findInArr\n");
        printf("5. extractDigits\n");
        printf("6. compareArrays\n");
        printf("0. Exit\n");
        scanf("%d", &i);
        switch (i) {
            case 1:
                printArr(n, arr);
                break;
            case 2:
                revertArr(n, arr);
                break;
            case 3:
                printf("%d\n", maxInArr(n, arr));
                break;
            case 4:
                printf("X? ");
                int x;
                scanf("%d", &x);
                printf("%d\n", findInArr(n, arr, x));
                break;
            case 5:
                printf("Y? ");
                int y;
                scanf("%d", &y);
                extractDigits(n, arr, y);
                break;
            case 6:
                compareArrays(n, n1, arr, arr1);
                break;
            case 0:
                free(arr);
                free(arr1);
                printf("Arrays are freed!");
                return 0;
        }
    }
}