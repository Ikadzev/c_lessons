#define DEBUG
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

// Структура для строк
typedef struct {
    char* data;      // Указатель на строку в динамической памяти
    size_t length;   // Длина строки
    size_t capacity; // Ёмкость строки
} String;

// Структура для динамического массива строк
typedef struct {
    String* data;     // Указатель на массив строк
    size_t length;    // Длина массива
    size_t capacity;  // Ёмкость массива
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
    printf(">%s<\n", str->data);
}

// Вывод динамического массива строк в консоль
void printDynArr(DynArrStr* arr) {
    for (size_t i = 0; i < arr->length; i++) {
        printString(&arr->data[i]);
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
    str->data[str->length] = '\0'; // Обновляем null-терминатор
}

// Добавление строки к динамическому массиву строк
void appendDynArrStr(DynArrStr* arr, const String* str) {
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

char* trim(const char* str) {
    size_t i = 0;
    while (str[i] == ' ') {
        i++;
    }
    size_t j = strlen(str);
    while (str[j-1] == ' ') {
        j--;
    }
    char* new_str = (char*) malloc((j-i+1) * sizeof(char));
    nullCheck(new_str);
    for (size_t q = 0; q < (j-i); q++) {
        new_str[q] = str[i+q];
    }
    new_str[j-i] = 0;
    return new_str;
}

// Разделение ввода на элементы
void split(DynArrStr* arr, String* inp) {
    int type = -1; // 0 - разделитель, 1 - слово, 2 - плюс или минус, 3 - знак препинания
    for (size_t i = 0; i < strlen(inp->data); i++) {
        int new_type = 3;
        char c = inp->data[i];
        if ((c == ' ') || (c == '\n')) {new_type = 0;}
        if (isalpha(c) || isdigit(c)) {new_type = 1;}
        if ((c == '+') || (c == '-')) {new_type = 2;}
        printf("Type is %i, character is '%c'\n", new_type, c);
        if (type == new_type) {
            appendString(&(arr->data[arr->length-1]), c);
        } else if ((type == 2) && (new_type == 1)) {
            appendString(&(arr->data[arr->length-1]), c);
            type = 1;
        } else {        
            String new_word;
            initString(&new_word);
            appendString(&new_word, c);
            appendDynArrStr(arr, &new_word);
            type = new_type;
        }
    }
}

void start() {
    char temp[1024];
    FILE* ptr;
    ptr = fopen("D:\\projects\\c_lessons\\labs\\first-lab\\tests\\1-input.txt", "r");
    if (ptr == NULL) {
        printf("Error while opening file");
        exit(1);
    }
    String str;
    initString(&str);
    while (fgets(temp, 1024, ptr) != NULL) {
        for (int i = 0; i < strlen(temp); i++) {
            appendString(&str, temp[i]);
        }
    }
    fclose(ptr);

    DynArrStr arr;
    initDynArrStr(&arr);
    split(&arr, &str);
    printDynArr(&arr);
}

void debug() {
    char a[3] = "123";
    char b[3] = "456";
    char c[3] = "789";
    String s1, s2, s3;
    initString(&s1);
    initString(&s2);
    initString(&s3);
    for (size_t i = 0; i < 3; i++) {
        appendString(&s1, a[i]);
        appendString(&s2, b[i]);
        appendString(&s3, c[i]);
    }
    DynArrStr da;
    initDynArrStr(&da);
    appendDynArrStr(&da, &s1);
    appendDynArrStr(&da, &s2);
    appendDynArrStr(&da, &s3);
    printDynArr(&da);
}

int main() {
    start();
}
