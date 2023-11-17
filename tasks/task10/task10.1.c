#include <stdio.h>
#include <string.h>

int palindrom(const char* str, size_t len_s) {
    char new_str[len_s]; // char new_str = (char*) malloc(len_s)
    size_t j = 0;
    for (size_t i = 0; i < len_s; i++) {
        if (str[i] != ' ') {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = 0;
    int f = 1;
    for (size_t q = 0; q < (j / 2)+1; q++) {
        if (new_str[q] != new_str[j - q - 1]) {
            f = 0; // сразу сделать ретурн
        }
    }
    return f;
}

int main() {
    const char* str = " a   b a            ";
    size_t len_s = strlen(str);
    int f = palindrom(str, len_s);
    if (f) {
        printf("Palindrom");
    } else {
        printf("Not palindrom");
    }
    return 0;
}
