//
// Created by ezgi on 29.12.2018.
//

#include <common.h>
#include "LinkedListTester.c"
#include "QueueTester.c"
#include "StackTester.c"
#include "TreeTester.c"
#include "GraphTester.c"

static const char *const STR_TESTER = "Tester";

int main(){

    log(STR_TESTER, "started testing");
    linkedListTestAll();
    queueTestAll();
    stackTestAll();
    treeTestAll();
    graphTestAll();
    log(STR_TESTER, "tests are passed");

    return 0;
}