#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#define ALLOCSIZE 5 /*Starting size of the stack*/

int createStack(Stack *s, size_t memSize)
{
    void *data = malloc(ALLOCSIZE * memSize);

    if(data != NULL) /*In case calloc fails*/
    {
      s->data = data;
      s->memSize = memSize;
      s->stackSize = 0;
      s->allocSize = ALLOCSIZE;
      return 1;
    }

    return -1;
}

void freeStack(Stack *s)
{
    free(s->data);
}

int isStackEmpty(const Stack *s)
{
    return s->stackSize == 0;
}

int StackPush(Stack *s, const void *data)
{
    void *dataAddr;

    if(s->stackSize == s->allocSize) /*The stack is full*/
    {
       void *tmp = realloc(s->data, (s->allocSize * 2) * s->memSize); /*Attempt to allocate more space for the stack.*/

       if(tmp != NULL) /*If successful, update allocSize and data*/
       {
           s->allocSize *= 2;
           s->data = tmp;
       }
       else
            return -1; /*Else return -1 to denote that we were unsuccessful in pushing a new element to the stack.*/
    }

    dataAddr = (char *)s->data + s->stackSize * s->memSize; /*Calculate the next available spot to push.*/
    memcpy(dataAddr, data, s->memSize);
    s->stackSize++;
    return 1;
}

void StackPop(Stack *s, void *data)
{
    if(!isStackEmpty(s))
    {
      const void *dataAddr;
      s->stackSize--;
      dataAddr = (const char *)s->data + s->stackSize * s->memSize;
      memcpy(data, dataAddr, s->memSize);
    }
}
