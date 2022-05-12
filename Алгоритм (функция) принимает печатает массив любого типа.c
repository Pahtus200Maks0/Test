/*Функция печатает массив любого типа*/

#include <stdio.h>
#include <string.h>
#include <windows.h>

#define COUNT(x) (sizeof(x)/sizeof(x[0]))

void printArray (void *ptr, unsigned count, char *type)
{
    for(unsigned n = 0; n < count; n++)
    {
        if((strcmp(type, "int")) == 0) // то же самое что (!strcmp(type, "int"))
            printf("%d ", *((int*)ptr+n));
        else if((strcmp(type, "unsigned")) == 0)
            printf("%u ", *((unsigned*)ptr+n));
        else if((strcmp(type, "double")) == 0)
            printf("%.3f ", *((double*)ptr+n));
        else
        {
            printf("\nОшибка! Нет такого спецификатора как \'%s\'\n", type);
            break;
        }
    }
}

int main()
{
    system("chcp 1251 > 0");

    unsigned uArr[] = {12, 45, 667, 221, 345};
    int iArr[] = {34, 43, 34, 456};
    double dArr[] = {12.2, 0.45, 6.67, 22.1, 3.45};

    printArray(uArr, COUNT(uArr), "unsigned");
    fputc('\n', stdout);
    printArray(iArr, COUNT(iArr), "int");
    fputc('\n', stdout);
    printArray(dArr, COUNT(dArr), "double");
    fputc('\n', stdout);
    printArray(dArr, COUNT(dArr), "double2");

    return 0;
}
