#include "string.h"
struct Info{
        char  str_inicial[10];
int  god_rozdenia;
int  math;
  int fiz;
 int inform;
        int chem;
};
struct Stack
{
Info * info;
Stack * next;
};
Stack* InStack(Stack*, Info*);
void View(Stack*);
void Del_All(Stack **);
    
void Zapis(Stack *p) ;