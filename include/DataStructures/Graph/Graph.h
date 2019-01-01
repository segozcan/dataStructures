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

void doGraphDepthFirst(int data, Graph* self, LinkedList* orderOfNodes);

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
    vertex->visited=0;
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

int graphHasEdge(Graph* self, int srcValue, int destValue){

    GraphVertex* source = graphVertexFind(self, srcValue);
    GraphVertex* destination = graphVertexFind(self, destValue);
    GraphVertex* referenceVertex=NULL;
    GraphVertex* comparisonVertex=NULL;

    if(source==NULL||destination==NULL)
    {
        errorAndExit("at least one of the values do not exist on graph.");
    }
    if(source->connectedNodes->size <= destination->connectedNodes->size)
    {
        referenceVertex= source;
        comparisonVertex=destination;
    }
    else
        {
        referenceVertex=destination;
        comparisonVertex=source;
        }

    int found=0;

    for(int i=0; i<referenceVertex->connectedNodes->size; i++)
    {
        int readValue = linkedListGet(referenceVertex->connectedNodes, i);

        if(readValue==comparisonVertex->value)
        {
            found=1;
            break;
        }

    }
    if(found==1)
    {
        return 1;
    }else
        {
        return 0;
        }
}

void graphDepthFirst(int data, Graph* self, LinkedList* orderOfNodes)
{
    GraphVertex* vertex = graphVertexFind(self, data);
    doGraphDepthFirst(vertex, orderOfNodes);


}

LinkedList* graphIndexFind(Graph* graph)
{
    LinkedList* unvisitedIndex = linkedListNew();
    LinkedListNode* currentVertex = graph->vertexList->head;
    while(currentVertex!=NULL)
    {
        linkedListAdd(unvisitedIndex, linkedListIndex(graph->vertexList, currentVertex->value));
        currentVertex=currentVertex->next;
    }
    return unvisitedIndex;
}

void doGraphDepthFirst(Graph* graph, GraphVertex* self,LinkedList* orderOfNodes)
{
       if(self->connectedNodes==NULL)
       {
           errorAndExit("Given node is not connected to any other node.");
       }
       int currentIndex=linkedListIndex(graph->vertexList, self->value);
       //undone


}
