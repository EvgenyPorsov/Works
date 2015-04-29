#ifndef HOLIDAYS_H
#define HOLIDAYS_H

struct Holiday
{
    int ID;
    char Date[15];
    char Description[100];
    _Bool IsDayOff;
};

void print(FILE* f);
void edit(FILE* f);
void del(FILE* f);
void add(FILE* f);

#endif // HOLIDAYS_H
