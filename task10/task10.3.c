#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char** split(const char* str, size_t len_s, size_t* size_array) { // len_s не нужен, см. прошлую задачу
    const char** arry = malloc((len_s + 1) * sizeof(char*));
    //nullCheck!!!!!!!!!!!!
    size_t size_temp = 0; // перенести вперёд
    size_t size_arry = 0;

    for (size_t i = 0; i < len_s; i++) {        
        if ((str[i] != ' ') && (str[i] != 0)) {
            char* temp_str = malloc((len_s + 1) * sizeof(char));
            //перенести вызов сюда
            for (; str[i] != ' ' && str[i] != 0; i++) {
                temp_str[size_temp++] = str[i];
            }
            temp_str[size_temp] = 0;
            size_temp = 0; // перенести назад
            arry[size_arry++] = temp_str;
        }
    }
    *size_array = size_arry; 
    return arry;
}

int main() {
    const char* str = "ab cd e";
    size_t len_s = strlen(str);
    printf("%d\n", len_s);
    size_t size_arry;
    const char** arry = split(str, len_s, &size_arry);
    for (size_t i = 0; i < size_arry; i++) {
        printf("%s\n", arry[i]);
    }
    return 0;
}
