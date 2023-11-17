#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int x;
    printf("X? ");
    scanf("%d", &x);
    
    int y;
    printf("Y? ");
    scanf("%d", &y);
    while (y == 0) {
        printf("Вы ввели ноль. В операции деления будет ошибка. Введите другое число.\nY? ");
        scanf("%d", &y);
    }
    
    printf("X + Y == %d\n", x + y);
    printf("X - Y == %d\n", x - y);
    printf("X * Y == %d\n", x * y);
    printf("X / Y == %d\n", x / y);
    printf("X % Y == %d\n\n", x % y);
    
    printf("X == Y? %d\n", x == y);
    printf("X != Y? %d\n", x != y);
    printf("X > Y? %d\n", x > y);
    printf("X < Y? %d\n", x < y);
    printf("X >= Y? %d\n", x >= y);
    printf("X <= Y? %d\n\n", x <= y);
    
    printf("X && Y == %d\n", x && y);
    printf("X || Y == %d\n", x || y);
    printf("!X == %d\n", !x);
    printf("!Y == %d\n\n", !y);
    
    printf("X & Y == %d\n", x & y);
    printf("X | Y == %d\n", x | y);
    printf("X ^ Y == %d\n", x ^ y);
    printf("~X == %d\n\n", ~x);
    
    printf("X << Y == %d\n", x << y);
    printf("X >> Y == %d\n", x >> y);
    return 0;
}