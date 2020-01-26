#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "bfs.h"
#include "graph.h"
#include "queue.h"

void bfs(struct Graph* graph, int src)
{
    struct Queue *queue;
    struct AdjListNode *node;
    int *visited;
    int idx, node_idx, num_vertexes;

    if (get_number_vertexes(graph) == 0)
        return;
    if (src < 0) {
        fprintf(stderr, "source node index is less than 0\n");
        return;
    }

    num_vertexes = get_number_vertexes(graph);
    queue = create_queue(num_vertexes);
    visited = (int*)malloc(sizeof(int)*num_vertexes);
    memset(visited, 0, sizeof(int)*num_vertexes);

    enqueue(queue, src);
    visited[src] = 1;
    while (!is_empty(queue)) {
        idx = front(queue);
        dequeue(queue);
        node = get_vertex_adjacencies(graph, idx);
        printf("%d ", idx);

        while (node != NULL) {
            node_idx = get_node_index(node);
            if (visited[node_idx] == 0) {
                visited[node_idx] = 1;
                enqueue(queue, node_idx);
            }
            node = get_next_node(node);
        }
    }

    free(visited);
    dispose_queue(&queue);
}
