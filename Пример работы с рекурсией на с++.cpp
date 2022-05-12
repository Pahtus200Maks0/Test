// Пример работы с рекурсией

#include <iostream>
#include <windows.h>

void subdivide(char ar[], int minimal, int maximum, int level);

const int Len = 66;
const int Divs = 6;

int main()
{
    system("chcp 1251 > 0");

    char ruler[Len];
    int i;
    for (i = 1; i < Len - 2; i++)
        ruler[i] = ' ';
    ruler[Len - 1] = '\0';
    int max = Len - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    std::cout << ruler << std::endl;
    for (i = 1; i <= Divs; i++)
    {
        subdivide(ruler,min ,max, i);
        std::cout << ruler << std::endl;
    }

    return 0;
}

void subdivide(char ar[], int minimal, int maximum, int level)
{
    if (level == 0)
        return;
    int mid = (maximum + minimal) / 2;
    ar[mid] = '|';
    subdivide(ar, minimal, mid, level - 1);
    subdivide(ar, mid, maximum, level - 1);
}
