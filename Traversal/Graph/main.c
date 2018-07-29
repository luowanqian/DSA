/*
 * BFS and DFS for a graph
 * Headers: in directory 'Utilities'
 */

#include "graph.h"
#include "bfs.h"
#include <stdio.h>

int main()
{
    int num_vertexes = 4;
    struct Graph *graph = create_graph(num_vertexes);
    add_directed_edge(graph, 0, 1, 0);
    add_directed_edge(graph, 0, 2, 0);
    add_directed_edge(graph, 1, 2, 0);
    add_directed_edge(graph, 2, 0, 0);
    add_directed_edge(graph, 2, 3, 0);
    add_directed_edge(graph, 3, 3, 0);
    //print_graph(graph);

    // BFS for a graph, start from node 2
    bfs(graph, 2);

    destroy_graph(&graph);

    return 0;
}
