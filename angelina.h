struct Stack {				// Декларация структурного типа
        int info;
        Stack * next;
} ;
Stack* InStack(Stack*, int);
void View(Stack*);
void Del_All(Stack **,Stack **);