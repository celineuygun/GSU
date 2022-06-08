#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sensor.h"

int main() {
    SensorInfo *sensors[N_LINES];
    readFile(sensors);

    printf("\n================== [ Graph with 30 distance ]\n\n");
    Graph *graph30 = createGraph(N_LINES, sensors, 30);
    printAdjMatrix(graph30->matrix, graph30->n_vertices);
    for(int i = 0; i < N_LINES; ++i) {
        for(int j = 0; j < N_LINES; ++j) {
            if(i == j) continue;
            if(graph30->distances[i][j] <= 30)
                addEdge(graph30, i, j);
        }
    } printf("\n"); 
    printGraph(graph30);

    printf("\n================== [ Graph with 20 distance ]\n\n");
    Graph *graph20 = createGraph(N_LINES, sensors, 20);
    printAdjMatrix(graph20->matrix, graph20->n_vertices);
    for(int i = 0; i < N_LINES; ++i) {
        for(int j = 0; j < N_LINES; ++j) {
            if(i == j) continue;
            if(graph20->distances[i][j] <= 20)
                addEdge(graph20, i, j);
        }
    } printf("\n"); 
    printGraph(graph20);

    printf("\n================== [ Graph with 10 distance ]\n\n");
    Graph *graph10 = createGraph(N_LINES, sensors, 10);
    printAdjMatrix(graph10->matrix, graph10->n_vertices);
    for(int i = 0; i < N_LINES; ++i) {
        for(int j = 0; j < N_LINES; ++j) {
            if(i == j) continue;
            if(graph10->distances[i][j] <= 10)
                addEdge(graph10, i, j);
        }
    } printf("\n"); 
    printGraph(graph10);

    return 0;
}