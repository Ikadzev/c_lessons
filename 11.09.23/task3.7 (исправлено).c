#include <stdio.h>
void land();

int main() {
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int k = 0;
    unsigned int input;
    unsigned int n;
    printf("N? ");
    scanf("%i", &n);

    land(n, 0, 0);
    while (x != n-1 || y != n - 1) {
        scanf("%i", &input);
        if (input == 2) {y++;} else if (input == 4) {x--;} else if (input == 6) {x++;} else if (input == 8) {y--;} else {
            printf("Неверная команда. Выход из игры...\n");
            break;
        }
        if (x == -1) {
            x = 0;
        }
        if (y == -1) {
            y = 0;
        }
        if (y >= n) {
            y = n-1;
        }
        if (x >= n) {
            x = n-1;
        }
        land(n, x, y);
        k++;
    }
    printf("Ваш результат: %i", k);
}

void land(int n, int pac_x, int pac_y) {
    for (unsigned int y = 0; y < n; y++) {
        for (unsigned int x = 0; x < n; x++) {
            if (x == pac_x && y == pac_y) {
                printf("@ ");
            } else if (x == n - 1 && y == n - 1) {
                printf("+ ");
            } else {
                printf("' ");
            }
        }
        printf("\n");
    }
}