//
// Created by ezgi on 29.12.2018.
//

#ifndef RAS111_LINKEDLIST_H
#define RAS111_LINKEDLIST_H


#include <zconf.h>

typedef struct LinkedListNode {
    struct LinkedListNode *next;
    union {
        int value;
        void* genericPointerValue;
    };
} LinkedListNode;

typedef struct LinkedList {
    LinkedListNode *head;
    LinkedListNode *tail;
    int size;
} LinkedList;


LinkedList *linkedListNew() {
    LinkedList *self = (LinkedList *) malloc(sizeof(LinkedList));
    if (!self) {
        errorAndExit("malloc returned null");
    } else {
        self->size = 0;
        self->head = NULL;
        self->tail = NULL;
    }
    return self;
}

void linkedListAdd(LinkedList *self, int data) {
    LinkedListNode *newData = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    newData->value = data;
    newData->next = NULL;
    self->size++;

    if (self->tail == NULL) {
        self->tail = self->head = newData;
    } else {
        self->tail->next = newData;
        self->tail = newData;
    }
}
void linkedListAddGeneric(LinkedList *self, void* data) {
    LinkedListNode *newData = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    newData->genericPointerValue = data;
    newData->next = NULL;
    self->size++;

    if (self->tail == NULL) {
        self->tail = self->head = newData;
    } else {
        self->tail->next = newData;
        self->tail = newData;
    }
}

int linkedListIndex(LinkedList* self,int  data)
{
    if(!self)
    {
        errorAndExit("list is null");
    }
    int index=-1;
    LinkedListNode* currentNode=self->head;
    while(currentNode!=NULL)
    {
        if(currentNode->value==data)
        {
            index++;
            break;
        }
        index++;
        currentNode=currentNode->next;
    }

    return index;
}

int linkedListGet(LinkedList *self, int index) {
    if (self->size <= index) {
        errorAndExit("array index out of bounds");
    } else {
        int counter = 0;
        LinkedListNode *currentNode = self->head;
        while (currentNode != NULL) {
            if (counter == index) {
                return currentNode->value;
            }
            currentNode = currentNode->next;
            counter++;
        }
    }
}

void* linkedListGetGeneric(LinkedList *self, int index) {
    if (self->size <= index) {
        errorAndExit("array index out of bounds");
    } else {
        int counter = 0;
        LinkedListNode *currentNode = self->head;
        while (currentNode != NULL) {
            if (counter == index) {
                return currentNode->genericPointerValue;
            }
            currentNode = currentNode->next;
            counter++;
        }
    }
}

void linkedListDelete(LinkedList *self, int index) {
    //current node'u siler, nodeToOperateOn silinecek node'dan bir önceki çıkar.
    if (self->size == 0) {
        errorAndExit("List is already empty.");
    }
    if (self->size <= index) {
        errorAndExit("index out of bounds");
    }
    LinkedListNode *currentNode = self->head;

    LinkedListNode *nodeToOperateOn = NULL;
    int counter = 0;
    while (currentNode->next != NULL) {
        if (counter == index) {
            break;
        }
        nodeToOperateOn = currentNode;
        currentNode = currentNode->next;
        counter++;
    }
    if (nodeToOperateOn != NULL) {
        nodeToOperateOn->next = currentNode->next;
        if (currentNode == self->tail) {
            self->tail = nodeToOperateOn;
        }
        free(currentNode);

    } else {

        nodeToOperateOn = self->head;
        self->head = self->head->next;
        free(nodeToOperateOn);
    }
    self->size--;

}

#endif //RAS111_LINKEDLIST_H
