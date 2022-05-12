/*������ � ���������� �� ��������� � ������� ���������� (��������)*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define CLS system("cls")
#define MAX 30

typedef struct
{
    char beginning[50]; //�������� ���������� ������ ��������;
    char end[50]; //�������� ��������� ������ ��������;
    int num; //����� ��������.

} marsh;

void Q_Sort(marsh* , int, int); //������� ����������
char* s_gets(char* st, int n); //��������� �����
void getinfo(marsh *,  int); //������ �����
void printMass(marsh *, int); //����� ������
void request(marsh *, int); //��������� �������
void initializ(void); //�������������

int x_max = 0;
marsh *ptr = NULL;

int main (void)
{
    system("chcp 1251 > 0");
    initializ(); //������������� � ��������� ������
    getinfo(ptr, x_max); //������ �����
    Q_Sort(ptr, 0, x_max - 1); //���������� ���������� ��������
    printMass(ptr, x_max); //����� ������
    request(ptr, x_max); //��������� �������
    free(ptr);

    return 0;
}

void initializ()
{
    puts("������� �������� ����������, ��������� � ����� ��������\n");
    puts("����� ����������� ��������� �� ������ ���������������� (�� ������ 30!)?");
    scanf("%d", &x_max);
    while (x_max > MAX)
    {
        puts("��������� �� ������ 30! ������� ��� ���:");
        scanf("%d", &x_max);
    }
    ptr = (marsh*)malloc(x_max * sizeof(marsh));
}

void getinfo(marsh * ptr,  int x_max) //������ �����
{
    getchar();
    for (int i = 0; i < x_max; i++)
    {
        puts("������� �������� ���������� ������ ��������");
        s_gets((ptr + i)->beginning, 50);
        CLS;

        puts("������� �������� ��������� ������ ��������");
        s_gets((ptr + i)->end, 50);
        CLS;

        puts("������� ����� ��������");
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
        find = strchr(st, '\n'); // ����� ����� ������
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue; // ��������� ������� ������
    }
    return ret_val;
}

void Q_Sort(marsh* point, int first, int last) //������� ����������
{
    if (first < last)
    {
        int left = first, right = last, middle = (point+(left + right)/2)->num; //������� �������
        do
        {
            while ((point+left)->num < middle)
                left++; //���� ������ �������� ��������
            while ((point+right)->num > middle)
                right--; //���� ������ �������� ���������
            if (left <= right) //���� �� �����������
            {
                marsh tmp = *(point + left);
                *(point + left) = *(point + right);
                *(point + right) = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        Q_Sort(point, first, right); //����������� ����� ��� ����� �����
        Q_Sort(point, left, last); //����������� ����� ��� ������ �����
    }
}

void printMass(marsh *ptr, int x_max) //����� ������
{
    for (int i = 0; i < x_max; i++)
    {
        printf("�%d - ��������� ����� �������� \"%s\", �������� ����� �������� \"%s\", ��� ����� - %d\n\n", i + 1, (i + ptr)->beginning,
               (i + ptr)->end, (i + ptr)->num);
    }
}

void request(marsh *ptr, int x_max) //��������� �������
{
    int nums = 0;
    int i = 0;

    printf("\n������� � ��������, ������� ������ �������. ��� ������� ����� \"exit\" ��� ������ �� ���������\n");
    while((scanf("%d", &nums)) != 0)
    {
        getchar();
        while (nums != (i + ptr)->num)
        {
            ++i;
            if(i > x_max)
            {
                i = 0;
                printf("������ �������� ��� � ������\n");
                printf("���������� ��� ���!\n");
                printf("������� � ��������, ������� ������ �������. ��� ������� ����� \"exit\" ��� ������ �� ���������\n");
                if ((scanf("%d", &nums)) == 0)
                {
                    puts("��������� ���������");
                    system("pause");
                    exit(EXIT_SUCCESS);
                }
                CLS;
            }
        }
        if(nums == (i + ptr)->num)
        {
            printf("�%d - ��������� ����� �������� \"%s\", �������� ����� �������� \"%s\", ��� ����� - %d\n\n", i + 1, (i + ptr)->beginning,
                    (i + ptr)->end, (i + ptr)->num);
            puts("���������� ����� ��� \"exit\" ��� ������");
            i = 0;
        }
    }
    puts("��������� ���������");
    system("pause");
    exit(EXIT_SUCCESS);
}














