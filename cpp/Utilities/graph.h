#ifndef _GRAPH_H
#define _GRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

struct Graph;
struct AdjListNode;

struct Graph* create_graph(int num_vertexes);
void destroy_graph(struct Graph** pGraph);
void add_undirected_edge(struct Graph* graph, int src, int dest, int weight);
void add_directed_edge(struct Graph* graph, int src, int dest, int weight);
struct AdjListNode* get_vertex_adjacencies(struct Graph* graph, int idx);
int get_node_index(struct AdjListNode* node);
struct AdjListNode* get_next_node(struct AdjListNode* node);
int get_number_edges(struct Graph* graph);
int get_number_vertexes(struct Graph* graph);
void print_graph(struct Graph* graph);

#ifdef __cplusplus
}
#endif

#endif //_GRAPH_H
