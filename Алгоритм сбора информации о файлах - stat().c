// ������������� ������� stat � ���� ���������� � ������
#include <stdio.h>
#include <stdlib.h> // ��� MAX_PATH
#include <dirent.h> // opendir � �.�.
#include <sys/stat.h> // ��� stat() � struct stat
#include <string.h> // ��� strcpy() � strcat()
#include <time.h>
#include <windows.h>
#define N 100000000

char * getstring(char * str, unsigned num, char * welcom)
{
    fflush(stdin);
    unsigned ctr;
    int chr;
    printf("%s\n������ ������ �� ����� %u ��������.\n", welcom, num-1);

    for(ctr = 0; ctr < num-1; ctr++)
    {
        chr = getchar();
        if(chr != '\n')
            str[ctr] = chr;
        else
            return str;
    }
    str[ctr] = '\0';
    return str;
}

DIR * dirOpen(char * pathDir)
{
    DIR * dir = 0;

    while(dir == 0)
    {
        getstring(pathDir, 260, "������� ���� �� ����������");
        if((dir = opendir(pathDir)) == 0)
        {
            printf("���������� ������� ����������\n");
            system("pause");
            system("cls");
        }
    }
    printf("\n������� ������� ����������\"%s\"\n\n", pathDir);
    return dir;
}

int main()
{
    int maxf;
    system("chcp 1251>0");
    char pathDir[MAX_PATH] = ".";
    char pathFull[MAX_PATH + FILENAME_MAX - 2]; // ������ ���� � �����
    DIR * folder;
    folder = dirOpen(pathDir);
    struct dirent * file;
    struct stat fileStat;
    printf("%2s %10s %30s %24s\n", "N", "������", "��� �����", "����� ���������");
    while((file = readdir(folder)) != NULL)
        {
        strcpy(pathFull, pathDir);
        strcat(pathFull,"/");
        strcat(pathFull, file->d_name);
        maxf += fileStat.st_size;
        if (stat(pathFull, &fileStat) == 0)
        {
            printf("%2ld ",telldir(folder));
            if(S_ISDIR(fileStat.st_mode))
                printf("%10s", "<DIR>");
            else if(((long)fileStat.st_size >= 1024) && ((long)fileStat.st_size < 1048576))
                printf("%7ld kb", (long)fileStat.st_size/1024);
            else
                printf("%7ld mb", (long)fileStat.st_size/1048576);

            printf (" %30s %s", file->d_name, ctime(&fileStat.st_mtime));
        }
        else
        {
            puts("�� ������� �������� ������ � ��������� stat");
            exit(2);
        }
    }

    printf("\n����� ������ ���� ������ � ���������� (��� ������������) %d ����\n", maxf);
    closedir(folder);
    system ("pause");
    return 0;
}
