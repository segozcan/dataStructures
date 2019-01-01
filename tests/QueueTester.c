//
// Created by ezgi on 29.12.2018.
//
#include <DataStructures/Queue/Queue.h>

static char *const STR_QUEUE = "Queue";

void queueTestEnqueue() {
    Queue *queue = queueCreate();
    queueEnqueue(queue, 5);
    assert(queueRear(queue) == 5);
    queueEnqueue(queue, 3);
    assert(queueRear(queue) == 3);
}

void queueTestDequeue() {

    Queue *queue = queueCreate();
    queueEnqueue(queue, 5);
    queueEnqueue(queue, 3);
    queueEnqueue(queue, 7);
    queueEnqueue(queue, 9);

    queueDequeue(queue);
    assert(queueFront(queue) == 3);
    queueDequeue(queue);
    assert(queueFront(queue) == 7);

}


void queueTestEmpty() {
    Queue *queue = queueCreate();
    assert(queueIsEmpty(queue) == TRUE);
    queueEnqueue(queue, 4);
    assert(queueIsEmpty(queue) == FALSE);
}

void queueTestAll() {
    log(STR_QUEUE, "Started testing queue");
    queueTestDequeue();
    queueTestEmpty();
    queueTestEnqueue();
    log(STR_QUEUE, "Finished tetsing queue.");
}