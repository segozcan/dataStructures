//
// Created by ezgi on 29.12.2018.
//

#include <DataStructures/LinkedList/LinkedList.h>

static char *const STR_LINKED_LIST = "LinkedList";

void linkedListTestAddition() {
    LinkedList *list = linkedListNew();

    linkedListAdd(list, 4);
    linkedListAdd(list, 6);
    linkedListAdd(list, 23);
    linkedListAdd(list, 45);


    assert(linkedListGet(list, 2) == 23);
    assert(linkedListGet(list, 3) == 45);
}


void linkedListTestRemoveFromHead(){

    LinkedList *list = linkedListNew();

    linkedListAdd(list, 4);
    linkedListAdd(list, 6);
    linkedListAdd(list, 23);
    linkedListAdd(list, 45);

    linkedListDelete(list,0);

    assert(linkedListGet(list, 0) == 6);
}


void linkedListTestRemoveFromMiddle(){

    LinkedList *list = linkedListNew();

    linkedListAdd(list, 4);
    linkedListAdd(list, 6);
    linkedListAdd(list, 23);
    linkedListAdd(list, 45);

    linkedListDelete(list,1);


    assert(linkedListGet(list, 1) == 23);
    assert(linkedListGet(list, 2) == 45);
}


void linkedListTestRemoveFromTail(){

    LinkedList *list = linkedListNew();

    linkedListAdd(list, 4);
    linkedListAdd(list, 6);
    linkedListAdd(list, 23);
    linkedListAdd(list, 45);

    linkedListDelete(list,list->size -1);

    assert(linkedListGet(list, list->size -1) == 23);
}


void linkedListTestAll(){
    log(STR_LINKED_LIST, "Started testing linked list");
    linkedListTestAddition();
    linkedListTestRemoveFromHead();
    linkedListTestRemoveFromMiddle();
    linkedListTestRemoveFromTail();
    log(STR_LINKED_LIST, "Finished testing linked list");
}