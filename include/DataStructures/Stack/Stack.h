//
// Created by ezgi on 29.12.2018.
//

#ifndef RAS111_STACK_H
#define RAS111_STACK_H

#include "../LinkedList/LinkedList.h"

typedef LinkedList Stack;

Stack* createStack()
{
    return linkedListNew();
}

int stackEmpty(Stack* self)
{
    return self->size==0;
}

Stack * stackPush(Stack *self, int data)
{
    if(!self)
    {
        errorAndExit("stack not existent");
    }
    linkedListAdd(self, data);
    return self;
}

Stack* stackPop(Stack *self)
{
    if(self->size==0)
    {
        errorAndExit("stack was empty");
    }
    linkedListDelete(self, self->size-1);
    return self;
}

int stackPeek(Stack *self)
{
    if(self->size==0)
    {
        errorAndExit("stack was empty");
    }

    return self->tail->value;
}




#endif //RAS111_STACK_H
