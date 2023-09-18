#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>

int main()
{
  float y;
  printf("Введите y: "); // выводим сообщение
  scanf("%f", &y);     // вводим значения переменной y
  printf("Значение переменной y=%f", y); // выводим значение переменной y
  return 0;
}