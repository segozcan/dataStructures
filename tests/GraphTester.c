//
// Created by ezgi on 01.01.2019.
//

#include <DataStructures/Graph/Graph.h>

static char *const STR_GRAPH = "Graph";


void graphTestAll()
{
    log(STR_GRAPH, "Started testing graph");
    /*Graph* graph = graphNew();
    graphAddVertex(graph,0);
    graphAddVertex(graph,1);
    graphAddVertex(graph,3);
    graphAddVertex(graph,5);
    graphAddVertex(graph,6);
    graphAddVertex(graph,7);

    graphAddEdge(graph,0,1);
    graphAddEdge(graph,5,6);
    graphAddEdge(graph,3,5);
    graphAddEdge(graph,6,3);
    graphAddEdge(graph,0,7);
    graphAddEdge(graph,6,7);
    graphAddEdge(graph,1,5);

    assert(graphDFS(graph,0, 3 )==1);



    assert(graphHasVertex(graph,3));

    assert(graphHasEdge(graph, 3, 5)==1);
    assert(graphHasEdge(graph, 3, 0)==0);
    assert(graphHasEdge(graph, 0, 1)==1);
    assert(graphHasEdge(graph, 7, 5)==0);


    graphPrint(graph);
*/

    /*Graph* graph = graphNew(0);
    graphNewAdjNode(1);
    graphNewAdjNode(2);
    graphNewAdjNode(3);
    graphNewAdjNode(4);
    graphNewAdjNode(5);
    graphNewAdjNode(6);

    graphAddUndirectedEdge(graph, 2, 3);
    graphAddUndirectedEdge(graph, 2, 5);
    graphAddUndirectedEdge(graph, 6, 3);
    graphAddUndirectedEdge(graph, 4, 3);
    graphAddUndirectedEdge(graph, 5, 0);
    graphAddUndirectedEdge(graph, 0, 1);
    graphAddUndirectedEdge(graph, 1, 4);

    assert(graphHasEdge(graph, 0, 1 )==1);
    assert(graphHasEdge(graph, 0, 2 )==0);
    assert(graphHasEdge(graph, 0, 3 )==0);
    assert(graphHasEdge(graph, 3,6 )==1);
    assert(graphHasEdge(graph, 4, 1 )==1);
*/

    Graph* self = graphNew();

    graphAddVertex(self);
    graphAddVertex(self);
    graphAddVertex(self);
    graphAddVertex(self);
    graphAddVertex(self);
    graphAddVertex(self);
    graphAddVertex(self);


    graphAddEdge(self, &self->vertexList[2], &self->vertexList[3],4);
    graphAddEdge(self, &self->vertexList[2], &self->vertexList[1],1);
    graphAddEdge(self, &self->vertexList[3], &self->vertexList[1], 6);
    graphAddEdge(self, &self->vertexList[0], &self->vertexList[3], 5);
    graphAddEdge(self, &self->vertexList[3], &self->vertexList[0], 10);
    graphAddEdge(self, &self->vertexList[3], &self->vertexList[2], 3);
    graphAddEdge(self, &self->vertexList[1], &self->vertexList[2], 3);
    graphAddEdge(self, &self->vertexList[0], &self->vertexList[2], 8);
    graphAddEdge(self, &self->vertexList[1], &self->vertexList[0], 9);
    graphAddEdge(self, &self->vertexList[5], &self->vertexList[4], 2);
    graphAddEdge(self, &self->vertexList[6], &self->vertexList[5], 1);
    graphAddEdge(self, &self->vertexList[1], &self->vertexList[6], 7);
    graphAddEdge(self, &self->vertexList[2], &self->vertexList[4], 12);
    graphAddEdge(self, &self->vertexList[5], &self->vertexList[3], 6);
    graphAddEdge(self, &self->vertexList[4], &self->vertexList[1], 3);
    graphAddEdge(self, &self->vertexList[2], &self->vertexList[6], 6);
    graphAddEdge(self, &self->vertexList[1], &self->vertexList[4], 20);


    assert(graphHasVertex(self,2)==1);
    assert(graphHasVertex(self,4)==1);
    assert(graphHasVertex(self,3)==1);

    assert(graphHasEdge(self, &self->vertexList[0], &self->vertexList[1])== 0);
    assert(graphHasEdge(self, &self->vertexList[2], &self->vertexList[1])== 1);
    assert(graphHasEdge(self, &self->vertexList[3], &self->vertexList[1])== 1);
    assert(graphHasEdge(self, &self->vertexList[0], &self->vertexList[2])== 1);
    assert(graphHasEdge(self, &self->vertexList[1], &self->vertexList[3])== 0);
    assert(graphHasEdge(self, &self->vertexList[2], &self->vertexList[0])== 0);

    graphPrint(self);

    Queue* queue = queueCreate();

    graphBreadthFirst(self, &self->vertexList[3], queue);

    graphDepthFirst(self, &self->vertexList[4]);


    log(STR_GRAPH, "Finished testing graph");
}