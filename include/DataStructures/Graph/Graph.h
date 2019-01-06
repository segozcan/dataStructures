//
// Created by ezgi on 31.12.2018.
//

#include <DataStructures/LinkedList/LinkedList.h>



typedef struct GraphVertex {

    int value; // actually, index
    GraphVertex *inNodes;
    GraphVertex* outNodes;
    int visited;
} GraphVertex;

typedef struct GraphEdge
{
    GraphVertex* startVertex;
    GraphVertex* endVertex;
    int weight;
}Edge;

typedef struct Graph {
    GraphVertex* vertexList;
    GraphEdge* edgeList;
    int numberOfVertices;
} Graph;


GraphVertex *graphNewVertex(int value);

GraphVertex *graphVertexFind(Graph *self, int value);

void doGraphDepthFirst(Graph* graph, GraphVertex* self, LinkedList* orderOfNodes, int(consumer)(int, LinkedList*));

Graph *graphNew() {

    Graph *graph = (Graph *) malloc(sizeof(Graph));

    if (!graph) {
        errorAndExit("Malloc returned null");
    }

    graph->vertexList = (GraphVertex*)malloc(sizeof(GraphVertex));
    graph->edgeList = (GraphEdge*)malloc(sizeof(GraphEdge));
    graph->numberOfVertices = 0;


    return graph;
}

void graphAddVertex(Graph *self) {

    GraphVertex* vertex = (GraphVertex*)malloc(sizeof(GraphVertex));

    vertex->value = sizeof(self->vertexList);
    vertex->inNodes = (GraphVertex*)malloc(sizeof(GraphVertex));
    vertex->outNodes = (GraphVertex*)malloc(sizeof(GraphVertex));

    self->vertexList = (GraphVertex*)realloc(self->vertexList, sizeof(self->vertexList) +1);
    self->numberOfVertices++;
    self->vertexList[sizeof(self->vertexList) - 1] = *vertex;


}

void graphAddEdge(Graph *self, GraphVertex* source, GraphVertex* destination, int weight) {

    if( self == NULL || source == NULL || destination == NULL)
    {
        errorAndExit("at least one of the arguments were null.");
    }

    GraphEdge* edge = (GraphEdge*)malloc(sizeof(GraphEdge));

    edge->weight = weight;
    edge->startVertex = source;
    edge->endVertex = destination;

    self->edgeList = (GraphEdge*)realloc(self->edgeList, sizeof(self->edgeList) +1);
    self->edgeList[sizeof(self->edgeList)-1] = *edge;

    source->outNodes = (GraphVertex*)realloc(source->outNodes, sizeof(source->outNodes) +1);
    source->outNodes[sizeof(source->outNodes) -1] = *destination;

    destination->inNodes = (GraphVertex*)realloc(destination->inNodes, sizeof(destination->inNodes) +1);
    destination->inNodes[sizeof(destination->inNodes) -1] = *source;

}


void graphPrint(Graph *self) {

    for(int i=0;i<sizeof(self->vertexList); i++)
    {
        printf("[%d] out nodes : ", self->vertexList[i]);
        for(int k=0; k<sizeof(self->vertexList[i].outNodes);k++)
        {
            printf("%d ", self->vertexList[i].outNodes[i].value);
        }
        printf("\n");
    }
}

void graphEdgeDelete(Graph* self, GraphVertex* sourceVertex, GraphVertex* destinationVertex)
{
    GraphVertex* ptrOut = &sourceVertex->outNodes[sizeof(sourceVertex->outNodes)-1];
    ptrOut = NULL;

    GraphVertex* ptrIn = &destinationVertex->inNodes[sizeof(destinationVertex->inNodes)-1];
    ptrOut = NULL;

}

int graphHasVertex(Graph* self, int value){

    if(value <0 )
    {
        errorAndExit("index out of bounds");
    }
    return value < sizeof(self->vertexList) ? 1 : 0;
}

int graphHasEdge(Graph* self, GraphVertex* source, GraphVertex* destination){

    int found=0;
    for(int i=0; i<sizeof(source->outNodes) ; i++)
    {
        if(source->outNodes[i].value == destination->value)
        {
            found==1;
            break;
        }
    }
    return found;
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
/*
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

*/
/*
typedef struct AdjacencyListNode
{
    int dest;
    AdjacencyListNode* next;
};

typedef struct AdjacencyList
{
    AdjacencyListNode* head;

};

typedef struct Edge
{
    AdjacencyListNode* startVertex;
    AdjacencyListNode* endVertex;
    int weight;

};

typedef struct EdgeList
{
    Edge* head;
};

typedef struct Graph
{
    int numberOfVertices;
    AdjacencyList* adjArr;
    EdgeList* edgeArr;
};

AdjacencyListNode* graphNewAdjNode(int dest)
{
    AdjacencyListNode* newAdjNode = (AdjacencyListNode*)malloc(sizeof(AdjacencyListNode));
    newAdjNode->dest=dest;
    newAdjNode->next=NULL;

    return newAdjNode;
}

Edge* graphNewUndirectedEdge(Graph* self, int source, int destination, int  weight)
{
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->weight = weight;

    AdjacencyListNode* startVertex =  self->adjArr[source];

    edge->endVertex = self->adjArr[source];
    edge->startVertex = self->adjArr[destination];



}

Graph* graphNew(int numberOfVertices)
{
    //Creates an array for each vertex.

    Graph * graph = (Graph*)malloc(sizeof(Graph));
    graph->numberOfVertices=numberOfVertices;
    graph->adjArr= (AdjacencyList*)malloc(numberOfVertices* sizeof(AdjacencyList));
    graph->edgeArr=(EdgeList*)malloc(sizeof(EdgeList));
}

void graphAddUndirectedEdge(Graph* self, int source, int destination, int  weight)
{

}

void graphAddDirectedEdge(Graph* self, int source, int destination)
{
    //Adds an edge only from the source to the destination.

    AdjacencyListNode* newNode = graphNewAdjNode(destination);
    newNode->next = self->adjArr[source].head;
    self->adjArr[source].head=newNode;

}

int graphHasEdge(Graph* self, int source, int destination)
{

    AdjacencyList listToBeChecked  = self->adjArr[source];
    AdjacencyList* addressOfList = &listToBeChecked;

    int i=0;
    while(addressOfList + i !=NULL)
    {
        AdjacencyListNode* currentNode = addressOfList->head;
        if(currentNode->dest==destination)
        {
            return 1;
        }
        currentNode = currentNode->next;
        i++;

    }

}
*/

