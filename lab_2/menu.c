#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "menu.h"
#include "holidays.h"

int menu(void)
{
    setlocale(0, "rus");
    FILE *holidays = fopen("holidays.tab", "rb+");
    if (!holidays)
        holidays = fopen("holidays.tab", "wb+");
    char ch;

    do
    {
        while (getchar() != '\n');
        print_menu();
        ch = getchar();
        switch (ch)
        {
        case '1':
            add(holidays);
            break;
        case '2':
            del(holidays);
            break;
        case '3':
            edit(holidays);
            break;
        case '4':
            print(holidays);
            break;
        }
    } while (ch != '0');

    return 0;
}

void print_menu()
{
    printf("\n1: �������� ������");
    printf("\n2: ������� ������");
    printf("\n3: �������� ������");
    printf("\n4: ���������� �������");
    printf("\n0: �����\n");
}


