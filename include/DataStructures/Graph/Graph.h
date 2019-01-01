//
// Created by ezgi on 31.12.2018.
//

#include <DataStructures/LinkedList/LinkedList.h>
#include <malloc.h>

typedef struct GraphVertex {
    int value;
    LinkedList *connectedNodes;
} GraphVertex;


typedef struct Graph {
    LinkedList *vertexList;
    int size;
} Graph;


GraphVertex *graphNewVertex(int value);

GraphVertex *graphVertexFind(Graph *self, int value);

Graph *graphNew() {

    Graph *graph = (Graph *) malloc(sizeof(Graph));

    if (!graph) {
        errorAndExit("Malloc returned null");
    }

    graph->vertexList = linkedListNew();


    return graph;
}

void graphAddVertex(Graph *self, int value) {

    GraphVertex *vertex = graphNewVertex(value);
    self->size++;
    linkedListAddGeneric(self->vertexList, (void *) vertex);

}

void graphAddEdge(Graph *self, int srcValue, int destValue) {
    GraphVertex *srcVertex = graphVertexFind(self, srcValue);
    GraphVertex *destVertex = graphVertexFind(self, destValue);
    if (!srcVertex) {
        errorAndExit("srcValue vertex was null");
    }
    if (!destVertex) {
        errorAndExit("destValue vertex was null");
    }
    linkedListAdd(srcVertex->connectedNodes, destVertex->value);
    linkedListAdd(destVertex->connectedNodes, srcVertex->value);
}

GraphVertex *graphVertexFind(Graph *self, int value) {
    for (int i = 0; i < self->vertexList->size; i++) {
        GraphVertex *vertex = (GraphVertex *) linkedListGetGeneric(self->vertexList, i);
        if (vertex->value == value) {
            return vertex;
        }
    }
    return NULL;
}


GraphVertex *graphNewVertex(int value) {
    GraphVertex *vertex = (GraphVertex *) malloc(sizeof(GraphVertex));
    vertex->connectedNodes = linkedListNew();
    vertex->value = value;
    return vertex;
}

void graphPrint(Graph *self) {
    for (int i = 0; i < self->vertexList->size; i++) {
        GraphVertex *vertex = (GraphVertex *) linkedListGetGeneric(self->vertexList, i);
        printf("[%d]:", vertex->value);
        for (int j = 0; j < vertex->connectedNodes->size; j++) {
            printf(" %d ", linkedListGet(vertex->connectedNodes, j));
        }
        printf("\n");
    }
}

int graphHasVertex(Graph* self, int value){
    return graphVertexFind(self,value) != NULL;
}

int graphHasEdge(Graph* self, int src, int dest){

}