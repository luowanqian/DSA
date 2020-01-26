#include "graph.h"
#include <stdio.h>

int main()
{
    int num_vertexes = 5;
    struct Graph *graph = create_graph(num_vertexes);

    add_undirected_edge(graph, 0, 1, 1);
    add_undirected_edge(graph, 0, 4, 2);
    add_undirected_edge(graph, 1, 2, 3);
    add_undirected_edge(graph, 1, 3, 4);
    add_undirected_edge(graph, 1, 4, 5);
    add_undirected_edge(graph, 2, 3, 6);
    add_undirected_edge(graph, 3, 4, 7);

    printf("Number of edges: %d\n", get_number_edges(graph));
    print_graph(graph);

    return 0;
}
