/*?????? ????????? ??????????, ??????? ??????? ????? ????????? ?? ??????? ????? 1 ? N ? ??????? ?? ?????.
??????? ?????, ??? ?? ?????, ??????? ??????? ??? ??????? ?????? ???? ?? ???? ? ?? ???????. ?????? ?? ?????, ?????????,
????????? ????? ?????????, ???? ?? ? ????? ???????? ????? 1 ? ?????? ????. ???? ??????? ?????????, ?? ????? ?????????,
???? ???, ?? ??? ??????? ? ????????? ??????? ??? ?? ?????*/

// 1 000 000 - ?????????? ?? 0.400 s

#include <stdio.h>
#include <windows.h>

#define MAX 10000 // ????????? ?? ???? ??????? MAX


int main ()
{
    system("chcp 1251 > null");

    register int one = 0; // ??????????? ?????
    int total = 2; // ?????? ? ???? ????? ??????????? ??????? ????? ?? ???????????? ???????
    static int mass[MAX] = {2, 3}; // ??????, ??????? ?????? ? ???? ??? ????????? ??????? ?????

    if (MAX >= 1000000)
    {
        mass[MAX/10]; // ???? ????? ??????? ???????
    }
    int iout; // ??????? ?? ????? ??? ??????? ?????

    for(one = 5; one <= MAX; one+=2) // ???? ????????? ???????? ?????? ?????
    {
        int check = 1; // ???? ????????, ???? 1, ?? ???????
        register int ctr = 1; // ??????? ????????? ??????? ??????? ?????

        while((mass[ctr]*mass[ctr]) <= one)
        {
            if(one%mass[ctr] == 0) // ???????? ?????????? ??????? ????? ??? ?????????
            {
                check = 0; // ???? ??????? ?????, ?? ????? ?????????
                break; // ? ?????? ??? ?????? ?????????? ????????
            }
            ctr++;
        }

        if(check != 0) // ????? ?? ????? ??????? ?????
        {
            mass[total] = one;
            total++; // ??????? ?????? ??????????? ??????? ?????
        }
    }
        for (iout = 0; iout < total; iout++) // ????????????? ??? ??????? ?????
            printf(" %d", mass[iout]);

        printf(" \n\n????? ??????????? ??????? ????? ????? %d!", total);

        system ("pause > null");

    return 0;
}
