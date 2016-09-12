#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/*Defining the node structure*/
typedef struct
{
    void *data;
    size_t memSize;
    int stackSize;
    int allocSize;
}Stack;

/*Prototypes*/
int createStack(Stack *, size_t);
void freeStack(Stack *);
int isStackEmpty(const Stack *);
int StackPush(Stack *, const void *);
void StackPop(Stack *, void *);

#endif /* STACK_H_INCLUDED */
