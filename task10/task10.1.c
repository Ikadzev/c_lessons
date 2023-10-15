#include <stdio.h>
#include <string.h>

int palindrom(char* str, size_t len_s) {
    char new_str[len_s];
    size_t j = 0;
    for (size_t i = 0; i < len_s; i++) {
        if (str[i] != ' ') {
            new_str[j] = str[i];
            printf("%c %c\n", str[i], new_str[j]);
            j++;
        }
    }
    new_str[j] = 0;
    int f = 1;
    printf("%s\n", new_str);
    for (size_t q = 0; q < (j / 2)+1; q++) {
        if (new_str[q] != new_str[j - q - 1]) {
            f = 0;
        }
    }
    return f;
}

int main() {
    char* str = "aba";
    size_t len_s = strlen(str);
    int f = palindrom(str, len_s);
    printf("%d ", f);
}
