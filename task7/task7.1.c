#include <stdio.h>

int main() {
    int arr[4][4];
    printf("Array? ");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            int c = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = c;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}