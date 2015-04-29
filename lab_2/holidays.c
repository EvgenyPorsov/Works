#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "streets.h"

void add(FILE* f)
{
    struct Holiday *p = malloc(sizeof(struct Holiday));
    char buf;

    if ((fread(p, sizeof(struct Holiday), 1, f) == 1))
    {
        fseek(f, -sizeof(struct Holiday), SEEK_END);
        do
        {
            if (fread(p, sizeof(struct Holiday), 1, f) != 1)
                break;
            fseek(f, -2*sizeof(struct Holiday), SEEK_CUR);
        } while (p->ID == -1);
        fseek(f, 2*sizeof(struct Holiday), SEEK_CUR);
        (p->ID)++;
    }
    else
        p->ID = 0;
    fseek(f, 0, SEEK_END);
    while(getchar() != '\n');
    printf("\nВведите число и месяц праздника: ");
    gets(p->Date);
    printf("\nВведите описание праздника: ");
    gets(p->Description);
    printf("\nВыходной день? [Д/Н]: ");
    scanf("%c", &buf);
    if ((buf == -124) || (buf == -92))
        p->IsDayOff = 1;
    else
        p->IsDayOff = 0;

    fwrite(p, sizeof(struct Holiday), 1, f);
    free(p);
    fseek(f, 0, SEEK_SET);
}

void del(FILE* f)
{
    int id;
    long pos;

    printf("\nВведите ID строки: ");
    scanf("%d", &id);
    fseek(f, sizeof(struct Holiday) * id, SEEK_SET);

    struct Holiday *p = malloc(sizeof(struct Holiday));
    while ((fread(p, sizeof(struct Holiday), 1, f) == 1) && (p->ID != id));
    if (p->ID == id)
    {
        p->ID = -1;
        pos = ftell(f);
        fseek(f, pos - sizeof(struct Holiday), SEEK_SET);
        fwrite(p, sizeof(struct Holiday), 1, f);
    }
    else
    {
        printf("\nЗапись с данным ID не найдена.");
    }
    free(p);
}

void edit(FILE* f)
{
    int id;
    printf("\nВведите ID строки: ");
    scanf("%d", &id);
    fseek(f, id * sizeof(struct Holiday), SEEK_SET);
    struct Holiday *p = malloc(sizeof(struct Holiday));
    while ((fread(p, sizeof(struct Holiday), 1, f) == 1) && (p->ID != id));
    while (getchar() != '\n');
    if (p->ID == id)
    {
        char buf;
        printf("\nВведите число и месяц праздника: ");
        gets(p->Date);
        printf("\nВведите описание праздника: ");
        gets(p->Description);
        printf("\nВыходной день? [Д/Н]: ");
        scanf("%c", &buf);
        if ((buf == -124) || (buf == -92))
            p->IsDayOff = 1;
        else
            p->IsDayOff = 0;
        fseek(f, - sizeof(struct Holiday), SEEK_CUR);
        fwrite(p, sizeof(struct Holiday), 1, f);
    }
    else
    {
        printf("\nЗапись с данным ID не найдена.");
    }

    free(p);
}

void print(FILE* f)
{
    fseek(f, 0, SEEK_SET);
    struct Holiday *p = malloc(sizeof(struct Holiday));
    printf("\n   ID   Число и месяц   Описание\t\t\t\t Выходной");
    while (fread(p, sizeof(struct Holiday), 1, f) == 1)
    {
        OemToChar(p->Description, p->Description);
        OemToChar(p->Date, p->Date);
        if (p->ID != -1)
        {
            printf("\n%4d\t%-15s %-35s\t %-3s", p->ID, p->Date, p->Description, p->IsDayOff ? "Да" : "Нет");

        }
    }
    printf("\n\n");
    fseek(f, 0, SEEK_SET);
}
