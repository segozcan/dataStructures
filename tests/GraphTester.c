//
// Created by ezgi on 01.01.2019.
//

#include <DataStructures/Graph/Graph.h>

static char *const STR_GRAPH= "LinkedList";

void graphTestAll()
{
    log(STR_GRAPH, "Started testing graph");
    Graph* graph = graphNew();
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

    assert(graphHasVertex(graph,3));

    assert(graphHasEdge(graph, 3, 5)==1);
    assert(graphHasEdge(graph, 3, 0)==0);
    assert(graphHasEdge(graph, 0, 1)==1);
    assert(graphHasEdge(graph, 7, 5)==0);
    graphPrint(graph);

    log(STR_GRAPH, "Finished testing graph");
}