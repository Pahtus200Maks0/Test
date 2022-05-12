#include <iostream>
#include <windows.h>

void showmenu(void);

const int strsize = 30;
const int ArSize = 3;

struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preferensce;
};

int main (void)
{
    system("chcp 1251 > 0");
    char choice;
    int count1;
    showmenu();
    std::cin >> choice;

    bop names1[ArSize]
    {
        {"\nМаксим", "\nИнженер", "\nРейнджер", 1},
        {"Вадик", "Программист", "Прогер", 2},
        {"Александр", "Бухгалтер", "Считавод", 3}
    };

    while (choice != 'q')
    {
        switch(choice)
        {
            case 'a' :  for (int i = 0; i < ArSize; ++i)
                            std::cout << names1[i].fullname << ' ';
                break;
            case 'b' :  for (int i = 0; i < ArSize; ++i)
                            std::cout << names1[i].bopname << ' ';
                break;
            case 'c' :  for (int i = 0; i < ArSize; ++i)
                            std::cout << names1[i].title << ' ';
                break;
            case 'd' : std::cout << "Сделайте предпочтение: \n"
                                    "1 - fullname\n"
                                    "2 - bopname\n"
                                    "3 - title\n";
                                    std::cin >> count1;
                                    if (count1 == 1)
                                    {
                                        std::cout << "Предпочтение " << names1[0].preferensce << ' ';
                                        for (int i = 0; i < ArSize; ++i)
                                            std::cout << names1[i].fullname << ' ';
                                    }
                                    else if (count1 == 2)
                                    {
                                        std::cout << "Предпочтение " << names1[1].preferensce << ' ';
                                        for (int i = 0; i < ArSize; ++i)
                                            std::cout << names1[i].bopname << ' ';
                                    }
                                    else
                                    {
                                        std::cout << "Предпочтение " << names1[2].preferensce << ' ';
                                        for (int i = 0; i < ArSize; ++i)
                                            std::cout << names1[i].title << ' ';
                                    }

                break;
                default : std::cout << "\nТакого нет в списке!!\n";
        }


        showmenu();
        std::cin >> choice;
    }

    std::cout << "Пока!";

    return 0;
}

void showmenu()
{
    std::cout << "\n\n\nСделайте свой выбор!\n"
                 "a - реальное имя  b - псевдоним\n"
                 "c - должность  q - выход\n"
                 "d - по предпочтению\n\n";
}

