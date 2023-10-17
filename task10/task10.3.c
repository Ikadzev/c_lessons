#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* trim(char* str, size_t len_s) {
    size_t i = 0;
    while (str[i] == 32) {
        i++;
    }
    size_t j = len_s;
    while (str[j-1] == 32) {
        j--;
    }
    char* new_str = (char*) malloc((j-1) * sizeof(char));
    for (size_t q = 0; q < (j-i); q++) {
        new_str[q] = str[i+q];
    }
    new_str[j-i] = 0;
    return new_str;
}

char* split(char* str, size_t len_s, size_t* size_array) {
    char* nw_str = trim(str, len_s);
    printf("%s", nw_str);
    printf("\n");
    size_t j = strlen(nw_str);
    char temp_str[j];
    size_t size_temp = 0;
    char arry[j][j];
    size_t size_arry = 0;
    for (size_t i = 0; i < j + 1; i++) {
        if ((nw_str[i] != 32) && (nw_str[i] != 0)) {
            temp_str[size_temp++] = nw_str[i];
        } else if (nw_str[i] == 32) {
            temp_str[size_temp] = 0;
            for (size_t q = 0; q < size_temp; q++) {
                arry[size_arry][q] = temp_str[q];
            }
            size_temp = 0;
            size_arry++;
        } else {
            temp_str[size_temp] = 0;
            for (size_t q = 0; q < size_temp; q++) {
                arry[size_arry++][q] = temp_str[q];
            }
            size_temp = 0;
            arry[size_arry][0] = 0;
        }
    }
    for (size_t i = 0; i < size_arry; i++) {
        printf("%s ", arry[i]);
    }
    *size_array = size_arry; 
    return arry;
}

int main() {
    char* str = "   ab cd e      ";
    size_t len_s = strlen(str);
    size_t size_arry;
    char* arry = split(str, len_s, &size_arry);
    for (size_t i = 0; i < size_arry; i++) {
        printf("%s ", arry[i]);
    }
    // char* new_str = trim(str, len_s);
    // printf("%s ", new_str);
    // free(new_str);
}
