//
// Created by ezgi on 31.12.2018.
//

#include <DataStructures/LinkedList/LinkedList.h>
#include <malloc.h>

typedef struct GraphVertex {

    int value;
    LinkedList *connectedNodes;  //linked list of nodes connected to this node
    int visited;
} GraphVertex;


typedef struct Graph {
    LinkedList *vertexList;
    int size;
} Graph;


GraphVertex *graphNewVertex(int value);

GraphVertex *graphVertexFind(Graph *self, int value);

void doGraphDepthFirst(Graph* graph, GraphVertex* self, LinkedList* orderOfNodes, int(consumer)(int, LinkedList*));

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
/*
void graphDepthFirst(int data, Graph* self, LinkedList* orderOfNodes, int(consumer)(int, LinkedList*))
{
    GraphVertex* vertex = graphVertexFind(self, data);
    doGraphDepthFirst(self, vertex, orderOfNodes, consumer);


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

void doGraphDepthFirst(Graph* graph, GraphVertex* self, LinkedList* orderOfNodes, int(consumer)(int, LinkedList*))
{
    if(self->connectedNodes==NULL)
    {
        errorAndExit("Given node is not connected to any other node.");
    }
    LinkedList* unvisitedIndex= graphIndexFind(graph);

    int currentIndex = linkedListIndex(graph->vertexList, self->value);
    int indexToBeDeleted = linkedListIndex(unvisitedIndex, currentIndex);
    if(indexToBeDeleted<unvisitedIndex->size)
    {
        linkedListAdd(orderOfNodes, self->value);
        linkedListDelete(unvisitedIndex, indexToBeDeleted);
        doGraphDepthFirst(graph, self->connectedNodes->tail, orderOfNodes,  consumer);
    }

}
*/
/*void graphDFS(Graph* self, GraphVertex* startVertex, LinkedList* orderOfNodes)
{
    LinkedList* unvisited = self->vertexList;
    if(startVertex->visited==0)
    {
        LinkedList* orderOfNodes = linkedListNew();
        startVertex->visited=1;
    }

    int nextData = startVertex->connectedNodes->head->value;

    startVertex= graphVertexFind(self, nextData);
    graphDFS(self, startVertex, orderOfNodes);

}
*/

void graphDevisit()
{

}

int graphDFS(Graph* self, int startValue, int findValue)
{
    GraphVertex* Vertex = graphVertexFind(self, startValue);

    Vertex->visited=1;

    if(startValue==findValue)
    {

        return 1;
    }else
        {
        for(int i=0;i<Vertex->connectedNodes->size;i++)
        {

            LinkedListNode* currentNode = Vertex->connectedNodes->head;

            int value = currentNode->value;

            GraphVertex* currentVertex = graphVertexFind(self, value);

            if(currentVertex->visited==0)
            {
                graphDFS(self, value, findValue);
            }

            currentNode=currentNode->next;

            if(i==Vertex->connectedNodes->size - 1)
            {
                return 0;
            }
        }

        }
}