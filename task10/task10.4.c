#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <stdio.h>

int c2i(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else {
        return -1;
    }
}

int s2i(const char *str, int base, jmp_buf *env) { // jmp_buf уже указатель, * не нужен
    if (base < 2 || base > 16) {
        longjmp(*env, 1);
    }

    int len = strlen(str);
    int sign = 1;
    int startId = 0;

    if (str[0] == '-') {
        sign = -1;
        startId = 1;
    }

    int result = 0;
    int power = 1;
    for (int i = len - 1; i >= startId; i--) {
        int digit = c2i(str[i]);
        if (digit == -1 || digit >= base) {
            longjmp(*env, 2);
        }
        result += digit * power;
        power *= base;
    }

    return sign * result;
}

int main() {
    const char* input = "1B";
    int base = 16;

    int value;
    jmp_buf env;

    switch (setjmp(env)) {
        case 0:
            value = s2i(input, base, &env);
            printf("Результат: %d\n", value);
            break;
        case 1:
            printf("Ошибка: Некорректная система счисления\n");
            break;
        case 2:
            printf("Ошибка: Некорректный символ в строке\n");
            break;
    }
    return 0;
}
