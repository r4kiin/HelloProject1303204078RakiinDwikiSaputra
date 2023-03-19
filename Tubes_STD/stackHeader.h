#ifndef STACKHEADER_H_INCLUDED
#define STACKHEADER_H_INCLUDED

using namespace std;
#include <iostream>

#define top(L) L.top
#define tail(L) L.tail
#define next(P) P->next
#define info(P) P->info
#define null NULL

struct data {
    char ekspresi;
};

typedef struct elm *adr;
struct elm {
    data info;
    adr next;
};

struct stack{
    adr top;
    adr tail;
};

void createStack(stack &L);
adr createItem(char X);
void pushStack(stack &L, adr P);
void popStack(stack &L);
bool emptyStack(stack &L);
int getSize(stack L);
adr getTop(stack L);
#endif // STACKHEADER_H_INCLUDED
