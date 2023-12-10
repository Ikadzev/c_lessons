// #define DEBUG
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Проверка на выделение памяти
void nullCheck(void* ptr) {
    if (ptr == NULL) {
        printf("OoM!");
        exit(0);
    }
}

// Проверка на палиндром
int palindrom(const char* str) {
    size_t len_s = strlen(str);
    char* new_str = (char*) malloc(sizeof(char) * len_s);
    size_t j = 0;
    for (size_t i = 0; i < len_s; i++) {
        if (str[i] != ' ') {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = 0;
    for (size_t q = 0; q < (j / 2)+1; q++) {
        if (new_str[q] != new_str[j - q - 1]) {
            return 0;
        }
    }
    return 1;
}

// Структура для строк
typedef struct {
    char* data;
    size_t length;
    size_t capacity;
} String;

// Структура для динамического массива строк
typedef struct {
    String* data;
    size_t length;
    size_t capacity;
} DynArrStr;

// Инициализация строки
void initString(String* str) {
    str->length = 0;
    str->capacity = 1;
    str->data = (char*)malloc(str->capacity * sizeof(char));
    nullCheck(str->data);
}

// Инициализация динамического массива строк
void initDynArrStr(DynArrStr* arr) {
    arr->length = 0;
    arr->capacity = 1;
    arr->data = (String*)malloc(arr->capacity * sizeof(String));
    nullCheck(arr->data);
}

// Освобождение памяти, выделенной под строку
void freeString(String* str) {
    free(str->data);
    str->length = 0;
    str->capacity = 0;
}

// Освобождение памяти, выделенной под динамический массив строк
void freeDynArrStr(DynArrStr* arr) {
    for (size_t i = 0; i < arr->length; ++i) {
        freeString(&(arr->data[i]));
    }
    free(arr->data);
    arr->length = 0;
    arr->capacity = 0;
}

// Вывод строки в консоль
void printString(const String* str) {
    #ifdef DEBUG
    printf(">%s< ", str->data);
    #else
    printf("%s", str->data);
    #endif
}

// Вывод динамического массива строк в консоль
void printDynArr(DynArrStr* arr, FILE* out) {
    for (size_t i = 0; i < arr->length; i++) {
        fprintf(out, "%s", arr->data[i].data);   
    }
}

// Добавление символа к строке
void appendString(String* str, char c) {
    if (str->length + 1 >= str->capacity) {
        str->capacity *= 2;
        str->data = (char*)realloc(str->data, str->capacity);
        nullCheck(str->data);
    }
    str->data[str->length++] = c;
    str->data[str->length] = '\0';
}

// Добавление строки к динамическому массиву строк
void appendDynArrStr(DynArrStr* arr, String* str) {
    if (arr->length >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (String*)realloc(arr->data, arr->capacity * sizeof(String));
        nullCheck(arr->data);
    }
    initString(&arr->data[arr->length]);
    for (int i = 0; i < strlen(str->data); i++) {
        appendString(&arr->data[arr->length], str->data[i]);
    }
    arr->length++;
}

// Удаление строки из массива
void removeFromArr(DynArrStr* arr, size_t item) {
    freeString(&(arr->data[item]));
    for (size_t i = item; i < arr->length - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }
    arr->length--;
}

// Добавление строки внутрь массива
void addToArr(DynArrStr* arr, size_t item, String* str) {
    appendDynArrStr(arr, &(arr->data[arr->length - 1]));
    for (size_t i = arr->length - 2; i > item; i--) {
        arr->data[i] = arr->data[i-1];
    }
    arr->data[item] = *str;
}

// Разделение ввода на лексемы
String nextLex(FILE* inp) {
    String lex;
    initString(&lex);
    char c = fgetc(inp);
    if (c == EOF) {}
    else if (isblank(c)) {
        appendString(&lex, c);
    } else if (isalnum(c) || (c == '+') || (c == '-')) {
        appendString(&lex, c);
        while (isalnum(c = fgetc(inp))) {
            appendString(&lex, c);
        }
        ungetc(c, inp);
    } else {
        appendString(&lex, c);
    }
    return lex;
}

void procDelimeter(DynArrStr* arr, size_t item) {
    if ((item == 0) || ((item == arr->length-1) && (arr->data[item].data[0] == ' '))) {
        removeFromArr(arr, item);
        return;
    }
    char str = arr->data[item].data[0];
    char p_str = arr->data[item-1].data[0];
    if ((str == ' ') && ((p_str == '\n') || (p_str == ' '))) {
        removeFromArr(arr, item);
    } else if ((item > 1) && ((str = '\n') && (p_str == '\n') && (arr->data[item-2].data[0] == '\n'))) {
        removeFromArr(arr, item);
    }
}

void procString(DynArrStr* arr, size_t item) {
    String* str = &(arr->data[item]);
    if (palindrom(str->data)) {
        char* pal = "PALINDROM\0";
        char* temp = (char*)malloc(10 * sizeof(char));
        for (size_t i = 0; i < 10; i++) {
            temp[i] = pal[i];
        }
        free(str->data);
        str->data = temp;
        str->length = strlen(pal);
        str->capacity = 10;
    }
}

void procNumber(DynArrStr* arr, size_t item) {
    if (item == arr->length - 1) {return;}
    int i = 0;
    size_t sign = -1;
    size_t digit = -1;
    for (size_t s = item+1; s < arr->length; s++) {
        String* str = &(arr->data[s]);
        if ((isdigit(str->data[0])) && (i == 1)) {
            digit = s;
            break;
        } else if (((str->data[0] == '-') || (str->data[0] == '+') || (str->data[0] == '/') || (str->data[0] == '*')) && (i == 0)) {
            sign = s;
            i = 1;
            continue;
        } else if (str->data[0] == ' ') {
            continue; // if whitespace between lexems
        } else {
            return; // not an expression
            }
    }

    int answ = 0;
    int f = 0;
    String* str = &(arr->data[item]);
    int f_d = atoi(str->data);
    int s_d = atoi(arr->data[digit].data);
    switch (arr->data[sign].data[0]) {
        case '-':
            answ = f_d - s_d;
            break;
        case '+':
            answ = f_d + s_d;
            break;
        case '*':
            answ = f_d * s_d;
            break;
        case '/':
            if (atoi(arr->data[digit].data) != 0) {
                answ = f_d / s_d;
            } else {
                f = 1;
            }
            break;
    }
    for (size_t i = item; i < digit; i++) {
        removeFromArr(arr, item);
    }
    if (f) {
        char* err = "ERROR\0";
        char* answ = (char*)malloc(6 * sizeof(char));
        for (size_t i = 0; i < 10; i++) {
            answ[i] = err[i];
        }
        free(str->data);
        str->data = answ;
        str->length = strlen(err);
        str->capacity = 6;
        return;
    } else {
        String out;
        initString(&out);
        char* s_answ = malloc(20 * sizeof(char));
        sprintf(s_answ, "%d", answ);
        free(str->data);
        str->data = s_answ;
        str->length = strlen(s_answ);
        str->capacity = 20;
    }
}

void strProc(DynArrStr* arr);
void procBkt(DynArrStr* arr, size_t item) {
    DynArrStr n_arr;
    initDynArrStr(&n_arr);
    int bkt = 0;
    size_t end_brk = 0;
    for (size_t i = item + 1; i < arr->length; i++) {
        char c = arr->data[i].data[0];
        if (c == '(') {
            bkt++;
        } else if ((c == ')') && (bkt != 0)) {
            bkt--;
        } else if ((c == ')') && (bkt == 0)) {
            end_brk = i;
            break;
        }
        appendDynArrStr(&n_arr, &(arr->data[i]));
    }
    if (!end_brk) { return; }
    strProc(&n_arr);
    if (n_arr.length == 1) {
        for (size_t i = item; i <= end_brk; i++) {
            removeFromArr(arr, item);
        }
        addToArr(arr, item, &(n_arr.data[0]));
    } else {
        for (size_t i = item+1; i < end_brk; i++) {
            removeFromArr(arr, item+1);
        }
        for (size_t i = 0; i < n_arr.length; i++) {
            addToArr(arr, item+i+1, &(n_arr.data[i]));
        }
    }
}

void strProc(DynArrStr* arr) {
    for (size_t i = 0; i < arr->length; i++) {
        char c = arr->data[i].data[0];
        if ((c == ' ') || (c == '\n')) {
            procDelimeter(arr, i);
        } else if (isalpha(c)) {
            procString(arr, i);
        } else if (isdigit(c)) {
            procNumber(arr, i);
        } else if (c == '(') {
            procBkt(arr, i);
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Error in args");
        exit(1);
    }
    FILE* inp_ptr = fopen(argv[1], "r");
    FILE* out_ptr = fopen(argv[2], "w");
    String str;
    DynArrStr arr;
    initDynArrStr(&arr);
    while ((str = nextLex(inp_ptr)).length > 0) {
        appendDynArrStr(&arr, &str);
    }
    size_t init_len = arr.length;
    strProc(&arr);
    
    while (init_len != arr.length) {
        init_len = arr.length;
        strProc(&arr);
    }
    printDynArr(&arr, out_ptr);
}