//
// Created by ezgi on 28.12.2018.
//

#ifndef RAS111_QUEUE_H
#define RAS111_QUEUE_H


typedef LinkedList Queue;

//Check if the queue is empty.
int queueIsEmpty(Queue *queue) {
    return queue->size == 0;
}

Queue *queueCreate() {
    return linkedListNew();
}

Queue *queueEnqueue(Queue *self, int value) {
    linkedListAdd(self, value);
    return self;
}

Queue *queueDequeue(Queue *self) {
    if (self->size < 1) {
        errorAndExit("queue was empty");
    }
    self->head = self->head->next;
    self->size--;
    return self;
}

int queueFront(Queue* self){
    if (self->size < 1) {
        errorAndExit("queue was empty");
    }
    return self->head->value;
}


int queueRear(Queue* self)
{
    if (self->size < 1) {
        errorAndExit("queue was empty");
    }
    return self->tail->value;
}

#endif //RAS111_QUEUE_H


