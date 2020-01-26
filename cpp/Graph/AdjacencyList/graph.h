#ifndef _GRAPH_H
#define _GRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

struct Graph;

struct Graph* create_graph(int num_vertexes);
void add_undirected_edge(struct Graph* graph, int src, int dest, int weight);
void print_graph(struct Graph* graph);
int get_number_edges(struct Graph* graph);

#ifdef __cplusplus
}
#endif

#endif //_GRAPH_H
