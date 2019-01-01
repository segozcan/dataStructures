//
// Created by ezgi on 29.12.2018.
//
#include <DataStructures/Stack/Stack.h>

static char *const STR_STACK = "Stack";

void stackTestAdd()
{
    Stack * self= createStack();
    stackPush(self, 3);
    assert(stackPeek(self)==3);
    stackPush(self, 4);
    assert(stackPeek(self)==4);
    stackPush(self, 5);
    assert(stackPeek(self)==5);
}

void stackTestRemove()
{
    Stack * self= createStack();
    stackPush(self, 4);
    stackPush(self, 5);
    stackPush(self, 7);
    stackPop(self);
    assert(stackPeek(self)==5);

}

void stackTestEmpty()
{

    Stack * self= createStack();
    stackPush(self, 3);
    assert(stackEmpty(self)==FALSE);
    stackPop(self);
    assert(stackEmpty(self)==TRUE);
}

void stackTestAll()
{
    log(STR_STACK, "Started testing stack");
    stackTestAdd();
    stackTestRemove();
    stackTestEmpty();
    log(STR_STACK, "Finished testing stack");
}