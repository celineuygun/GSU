#ifndef GRAPH_H_
#define GRAPH_H_

typedef struct AdjacencyListNode {
    int dest;
    struct AdjacencyListNode *next;
} AdjListNode;

typedef struct AdjacencyList {
    AdjListNode *head;
} AdjList;

typedef struct graph {
    int n_vertices;
    AdjList *arr;
} Graph;

AdjListNode *newAdjListNode(int dest);
Graph* createGraph(int n_vertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);

#endif