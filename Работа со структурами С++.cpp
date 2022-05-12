#include <iostream>
#include <windows.h>


const int SLEN = 30;

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel1;
};

int getinfo(student ptr[], int clas);
void display1(student ptr);
void display2(const student *ptr);
void display3(const student ptr[], int n);

int main (void)
{
    system("chcp 1251 > 0");
    std::cout << "����� ����������� �������� �� ������ ����������������? ";
    int clas;
    std::cin >> clas;
    while (std::cin.get() != '\n')
        continue;
    student *ptr = new student[clas];
    int entered = getinfo(ptr, clas);
    for (int i = 0; i < entered; ++i)
    {
        display1(ptr[i]);
    }
    for (int i = 0; i < entered; ++i)
    {
        display2(&ptr[i]);
    }

    display3(ptr, entered);
    delete [] ptr;
    std::cout << "\n�����";
    return 0;
}

int getinfo(student ptr[], int clas)
{
    int coun = 0;
    std::cout << "\n������� ���������� � " << clas << " ���������\n\n";
    for (int i = 0; i < clas; ++i)
    {
        std::cout << "������� ��� �������� N" << i + 1 << ' ';
        std::cin.getline(ptr[i].fullname, SLEN);
        if (strlen(ptr[i].fullname) == 0)
            break;
        std::cout << "\n������� ��� ����� ";
        std::cin.getline(ptr[i].hobby, SLEN);
        std::cout << "\n������� ��� ������� ";
        std::cin >> ptr[i].ooplevel1;
        std::cin.get();
        std::cout << '\n';
        coun++;
    }
    return coun;
}

void display1(student ptr)
{
    std::cout << ' ' << ptr.fullname << ' ' << ptr.hobby << ' ' << ptr.ooplevel1 << '\n';
}

void display2(const student *ptr)
{
    std::cout << ' ' << ptr->fullname << ' ' << ptr->hobby << ' ' << ptr->ooplevel1 << '\n';
}

void display3(const student ptr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << ' ' << ptr[i].fullname << ' ' << ptr[i].hobby << ' ' << ptr[i].ooplevel1 << '\n';
    }

}

















