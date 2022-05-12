/*Создание и обработка связного списка и сохраниние его в файл*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#define CLS system("cls")
#define FFLUSH while(fgetc(stdin)!='\n')

struct order
{
    int number;
    int sum;
    struct order *next;
};

char * filename = "list.txt";

struct order *first;
struct order *current;
struct order *newNode;

int showMenu(void); //Показать меню
void addNode(void); //Добавить новый узел в конец списка
void removeNode(void); //Удалить узел
void showList(void); //Показать список
struct order *memAlloc(void); //Выделить память под узел
int check(int i); //Проверка на повторность ввода узла
void deletnode(void); //Автоматическое удаление повторного узла
void getInput(int * result, int min, int max, char * welcome);
void loadList(void); //Функция для загрузки существующего связного списка
void saveList(void); //Функция сохранения связного списка

int main(void)
{
    system ("chcp 1251 > 0");
    int choice = 0;
    first = NULL;

    loadList();

 while(choice != 'Q')
 {
     choice = showMenu();
     switch(choice)
     {
         case 'S':
             CLS;
             showList();
             break;
         case 'A':
             CLS;
             addNode();
             break;
         case 'R':
             CLS;
             removeNode();
             break;
         case 'Q':
             CLS;
             puts("Выход");
             saveList();
             system("pause");
             break;

         default:
             CLS;
             puts("Некорректный ввод");
             break;
     }
 }
    return 0;
}

int showMenu(void)
{
    int ch = 0;
    printf("A - добавить новый узел в конец списка, R - удалить узел,"
           " S - показать список, Q - Exit\n");
    ch = getch();
    return(toupper(ch));
}

struct order *memAlloc(void)
{
    struct order *temp;
    temp = (struct order *)malloc(sizeof(struct order));
    if(temp == NULL)
    {
        puts("Ошибка выделения памяти");
        system("pause");
        exit(1);
    }
    return temp;
}

void addNode(void)
{
    int i = 0;

    if(first == NULL)
    {
        first = memAlloc();
        current = first;
    }
    else
    {
        current = first;
        while(current->next != NULL)
        {
            current = current->next;
        }
        newNode = memAlloc();
        current->next = newNode;
        current = current->next;
    }
    current->next = NULL;

    getInput(&current->number, 0, 1000000, "Введите индекс: ");
    i = current->number;
    if (check(i) == 1)
        {
            puts("Такой индекс уже есть, придумайте другой!\n");
            addNode();
            return;
        }
    getInput(&current->sum, 0, 1000000, "Введите сумму: ");
}

void showList()
{
    int count = 1;
    if(first == NULL)
    {
        puts("Список пуст");
        return;
    }
    puts("Список:");
    current = first;
    while(current != NULL)
    {
        printf("Список №%d, индекс %d, сумма счёта %d\n",
               count, current->number, current->sum);
        current = current->next;
        count++;
    }
}

void removeNode(void)
{
    struct order *prev;
    int rem = 0;
    int num;

    if(first == NULL)
    {
        puts("Список пуст, удалять нечего!");
        return;
    }
    showList();
    while(rem < 1 || rem > 1000000)
    {
        puts("Введите номер узла, который хотите удалить");
        scanf("%d", &rem);
        FFLUSH;
    }

    num = 1;
    current = first;
    prev = NULL;
    while(num != rem)
    {
        prev = current;
        current = current->next;
        num++;
        if(current == NULL)
        {
            puts("Нет узла с таким номером");
            return;
        }
    }
    if(prev == NULL)
        first = current->next;
    else
        prev->next = current->next;
    printf("Узел %d удалён\n", rem);
    free(current);
}

int check(int i)
{
    current = first;
    while((current->next != NULL) && (i != current->number))
    {
        current = current->next;
    }
    if((current->next != NULL) && (i == current->number))
    {
        deletnode();
        return 1;
    }

    return 0;
}

void deletnode(void)
{
    current = first;
    struct order *prev;

    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    if(current->next == NULL)
    {
        prev->next = current->next;
    }
    free(current);
}

void loadList(void)
{
    FILE * fptr;
    struct order loaded;
    int records = 0;

    fptr = fopen(filename, "rb");
    if(fptr == NULL)
        return;

    while( fread(&loaded, sizeof(struct order), 1, fptr) )
    {
        if(first == NULL)
        {
            first  = memAlloc();
            current = first;
        }
        else
        {
            current = first;
            while(current->next != NULL)
            {
                current = current->next;
            }
            newNode = memAlloc();
            current->next = newNode;
            current = current->next;
        }
        current->number = loaded.number;
        current->sum = loaded.sum;
        current->next = NULL;
        records++;
    }
    fclose(fptr);
    printf("Было прочитано %d узлов из файла \'%s\'\n", records, filename);
}

void saveList(void)
{
    int records = 0;
    FILE * fptr;

    fptr = fopen(filename, "wb");
    if(fptr == NULL)
    {
        puts("Связный список пуст узлов нет");
        return;
    }

    current = first;
    while(current != NULL)
    {
        fwrite(current, sizeof(struct order), 1, fptr);
        current = current->next;
        records++;
    }
    fclose(fptr);
    printf("В файл /'%s/' записано %d узлов\n", filename, records);
}

void getInput(int * result, int min, int max, char * welcome)
{
    *result = -1;
    while(*result < min || *result > max)
    {
        printf("%s", welcome);
        scanf("%d", result);
        FFLUSH;
    }
}







