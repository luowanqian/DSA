#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

struct AdjListNode {
    double weight;  // weight
    int idx;        // index of vertex
    struct AdjListNode *next;
};

struct AdjList {
    struct AdjListNode *head;
};

struct Graph
{
    struct AdjList *vertexes;
    int num_vertexes;
    int num_edges;
};

struct Graph* create_graph(int num_vertexes)
{
    int i;
    struct Graph *graph;

    graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertexes = num_vertexes;
    graph->vertexes = (struct AdjList*)malloc(sizeof(struct AdjList)*num_vertexes);
    graph->num_edges = 0;

    for (i=0; i<num_vertexes; i++)
        graph->vertexes[i].head = NULL;

    return graph;
}

struct AdjListNode* create_node(int idx, int weight)
{
    struct AdjListNode *node;

    node = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    node->next = NULL;
    node->idx = idx;
    node->weight = weight;

    return node;
}

void add_undirected_edge(struct Graph* graph, int src, int dest, int weight)
{
    struct AdjListNode *node;

    // src -> dest
    node = create_node(dest, weight);
    node->next = graph->vertexes[src].head;
    graph->vertexes[src].head = node;

    // dest -> src
    node = create_node(src, weight);
    node->next = graph->vertexes[dest].head;
    graph->vertexes[dest].head = node;

    graph->num_edges++;
}

void print_graph(struct Graph* graph)
{
    int i;
    struct AdjListNode *node;

    for (i=0; i<graph->num_vertexes; i++) {
        node = graph->vertexes[i].head;
        printf("\nAdjacency list of vertex %d\n head", i);
        while (node != NULL) {
            printf(" -> %d(%f)", node->idx, node->weight);
            node = node->next;
        }
        printf("\n");
    }
}

int get_number_edges(struct Graph* graph)
{
    return graph->num_edges;
}
