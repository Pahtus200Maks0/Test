/*работа с указателем на структуру и быстрая сортировка (рекурсия)*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define CLS system("cls")
#define MAX 30

typedef struct
{
    char beginning[50]; //название начального пункта маршрута;
    char end[50]; //название конечного пункта маршрута;
    int num; //номер маршрута.

} marsh;

void Q_Sort(marsh* , int, int); //быстрая сортировка
char* s_gets(char* st, int n); //обработка строк
void getinfo(marsh *,  int); //запрос ввода
void printMass(marsh *, int); //вывод списка
void request(marsh *, int); //обработка запроса
void initializ(void); //инициализация

int x_max = 0;
marsh *ptr = NULL;

int main (void)
{
    system("chcp 1251 > 0");
    initializ(); //инициализация и выделение памяти
    getinfo(ptr, x_max); //запрос ввода
    Q_Sort(ptr, 0, x_max - 1); //сортировка полученных значений
    printMass(ptr, x_max); //вывод списка
    request(ptr, x_max); //обработка запроса
    free(ptr);

    return 0;
}

void initializ()
{
    puts("Введите название начального, конечного и номер маршрута\n");
    puts("Какое колличество маршрутов Вы хотите инициализировать (не больше 30!)?");
    scanf("%d", &x_max);
    while (x_max > MAX)
    {
        puts("Разрешено не больше 30! Введите ещё раз:");
        scanf("%d", &x_max);
    }
    ptr = (marsh*)malloc(x_max * sizeof(marsh));
}

void getinfo(marsh * ptr,  int x_max) //запрос ввода
{
    getchar();
    for (int i = 0; i < x_max; i++)
    {
        puts("Введите название начального пункта маршрута");
        s_gets((ptr + i)->beginning, 50);
        CLS;

        puts("Введите название конечного пункта маршрута");
        s_gets((ptr + i)->end, 50);
        CLS;

        puts("Введите номер маршрута");
        scanf("%d", &(ptr + i)->num);
        getchar();
        CLS;
    }
}

char *s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // поиск новой строки
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue; // отбросить остаток строки
    }
    return ret_val;
}

void Q_Sort(marsh* point, int first, int last) //Быстрая сортировка
{
    if (first < last)
    {
        int left = first, right = last, middle = (point+(left + right)/2)->num; //опорный элемент
        do
        {
            while ((point+left)->num < middle)
                left++; //если меньше опорного элемента
            while ((point+right)->num > middle)
                right--; //если больше опорного эелемента
            if (left <= right) //если не пересеклись
            {
                marsh tmp = *(point + left);
                *(point + left) = *(point + right);
                *(point + right) = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        Q_Sort(point, first, right); //рекурсивный вызов для левой части
        Q_Sort(point, left, last); //рекурсивный вызов для правой части
    }
}

void printMass(marsh *ptr, int x_max) //вывод списка
{
    for (int i = 0; i < x_max; i++)
    {
        printf("№%d - Начальный пункт маршрута \"%s\", Конечный пункт маршрута \"%s\", Его номер - %d\n\n", i + 1, (i + ptr)->beginning,
               (i + ptr)->end, (i + ptr)->num);
    }
}

void request(marsh *ptr, int x_max) //обработка запроса
{
    int nums = 0;
    int i = 0;

    printf("\nВведите № маршрута, который хотите увидеть. Или введите слово \"exit\" для выхода из программы\n");
    while((scanf("%d", &nums)) != 0)
    {
        getchar();
        while (nums != (i + ptr)->num)
        {
            ++i;
            if(i > x_max)
            {
                i = 0;
                printf("Такого маршрута нет в списке\n");
                printf("Попробуйте ещё раз!\n");
                printf("Введите № маршрута, который хотите увидеть. Или введите слово \"exit\" для выхода из программы\n");
                if ((scanf("%d", &nums)) == 0)
                {
                    puts("Программа завершена");
                    system("pause");
                    exit(EXIT_SUCCESS);
                }
                CLS;
            }
        }
        if(nums == (i + ptr)->num)
        {
            printf("№%d - Начальный пункт маршрута \"%s\", Конечный пункт маршрута \"%s\", Его номер - %d\n\n", i + 1, (i + ptr)->beginning,
                    (i + ptr)->end, (i + ptr)->num);
            puts("Продолжить поиск или \"exit\" для выхода");
            i = 0;
        }
    }
    puts("Программа завершена");
    system("pause");
    exit(EXIT_SUCCESS);
}














