#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

AdjListNode *newAdjListNode(int dest) {
    AdjListNode *new = calloc(1, sizeof(AdjListNode));
    if(new) {
        new->dest = dest;
        new->next = NULL;
    } return new;
}

Graph* createGraph(int n_vertices) {
    Graph *graph = calloc(1, sizeof(Graph));
    if(graph) {
        graph->n_vertices = n_vertices;
        graph->arr = calloc(n_vertices, sizeof(AdjList));
        for(int i = 0; i < n_vertices; ++i)
            graph->arr[i].head = NULL;
    } return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    AdjListNode *node = newAdjListNode(dest), *tmp = NULL;
    if(!graph->arr[src].head)
        graph->arr[src].head = node;
    else {
        for(tmp = graph->arr[src].head; tmp->next != NULL; tmp = tmp->next);
        tmp->next = node;
    }
    node = newAdjListNode(src);
    if(!graph->arr[dest].head)
        graph->arr[dest].head = node;
    else {
        for(tmp = graph->arr[dest].head; tmp->next != NULL; tmp = tmp->next);
        tmp->next = node;
    }
}

void printGraph(Graph* graph) {
    for(int v = 0; v < graph->n_vertices; ++v) {
        AdjListNode *tmp = graph->arr[v].head;
        printf("\nAdjacency list of vertex %d\n head ", v);
        for(; tmp != NULL; tmp = tmp->next)
            printf("-> %d ", tmp->dest);
        printf("\n");
    }
}