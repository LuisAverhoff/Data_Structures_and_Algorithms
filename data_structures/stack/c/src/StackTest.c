#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    int val;
    Stack s;

    createStack(&s, sizeof(int));

    for(val = 1; val <= 10; val++)
    {
        StackPush(&s, &val);
    }

    while(!isStackEmpty(&s))
    {
        StackPop(&s, &val);
        printf("%d has been popped off the stack.\n", val);
    }

    freeStack(&s);

    return 0;
}
