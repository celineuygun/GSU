#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sensor.h"

#define BUFFER_SIZE 100

void readFile(SensorInfo **sensors) {
    char buffer[BUFFER_SIZE]; // satirlari icinde tutacak
    int id, firstLine = 1, column = 0, row = 0;
    float x_axe, y_axe, z_axe;
    FILE *fp = fopen("sensor_locations.csv", "r");
    if(!fp) exit(1);
    while(fgets(buffer, BUFFER_SIZE, fp) != NULL){ // satir satir okuyup buffer'a kaydeder
        column = 0;
        if(firstLine) {
            firstLine = 0;
            continue;
        }
        for(char *token = strtok(buffer, ","); token != NULL; token = strtok(NULL, ",")) {
            if(column == 0)
                id = atoi(token);
            else if(column == 1)
                x_axe = atof(token);
            else if(column == 2)
                y_axe = atof(token);
            else if(column == 3)
                z_axe = atof(token);
            else break;
            column++;
        } sensors[row] = createSensorInfo(id, x_axe, y_axe, z_axe);
        printSensor(sensors[row]);
        row++;
    } fclose(fp);
}

AdjListNode *newAdjListNode(int dest) {
    AdjListNode *new = calloc(1, sizeof(AdjListNode));
    if(new) {
        new->dest = dest;
        new->next = NULL;
    } return new;
}

Graph* createGraph(int n_vertices, SensorInfo **sensors, int distance) {
    Graph *graph = calloc(1, sizeof(Graph));
    if(graph) {
        graph->n_vertices = n_vertices;
        graph->arr = calloc(n_vertices, sizeof(AdjList));
        for(int i = 0; i < n_vertices; ++i)
            graph->arr[i].head = NULL;
        graph->distances = calculateDistances(sensors, n_vertices);
        graph->matrix = createAdjecencyMatrix(graph->distances, n_vertices, distance);
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
}

SensorInfo *createSensorInfo(int id, float x_axe, float y_axe, float z_axe) {
    SensorInfo *new = calloc(1, sizeof(SensorInfo));
    if(new) {
        new->id = id;
        new->x_axe = x_axe;
        new->y_axe = y_axe;
        new->z_axe = z_axe;
    } return new;
}

void printSensor(SensorInfo *sensor) {
    if(sensor) {
        printf("ID: %2d  Coordonnees: (%.1f, %.1f, %.1f)\n", sensor->id, sensor->x_axe, sensor->y_axe, sensor->z_axe);
    }
}

float **calculateDistances(SensorInfo **sensors, int n_line) {
    float **distances = calloc(n_line, sizeof(float*));
    for(int i = 0; i < n_line; ++i)
        distances[i] = calloc(n_line, sizeof(float));

    for(int i = 0; i < n_line; ++i) {
        for(int j = 0; j < n_line; ++j) {
            float sum = pow(sensors[i]->x_axe - sensors[j]->x_axe, 2);
            sum += pow(sensors[i]->y_axe - sensors[j]->y_axe, 2);
            sum += pow(sensors[i]->z_axe - sensors[j]->z_axe, 2);
            distances[i][j] = sqrt(fabs(sum));
        }
    } return distances;
}

int **createAdjecencyMatrix(float **distances, int n_line, int distance) {
    int **adjMatrix = calloc(n_line, sizeof(int*));
    for(int i = 0; i < n_line; ++i)
        adjMatrix[i] = calloc(n_line, sizeof(int*));

    for(int i = 0; i < n_line; ++i) {
        int counter = 0;
        for(int j = 0; j < n_line; ++j) {
           if(distances[i][j] && distances[i][j] < distance) {
               adjMatrix[i][j] = 1;
               counter++;
            } else
                adjMatrix[i][j] = 0;
        } if(!counter)
            printf("\nThere're no adjacent nodes to sensor with the id %d\n", i);
    } return adjMatrix;
}

int findDegree(struct graph *graph, int ver) { 
    int degree = 0;          
    for (int i = 0; i < graph->n_vertices; ++i)      
        if(graph->matrix[ver][i] == 1)  
            degree++;              
    return degree;          
}

void printGraph(Graph* graph) {
    for(int i = 0; i < graph->n_vertices; ++i) {
        int degree = findDegree(graph, i);
        AdjListNode *tmp = graph->arr[i].head;
        printf("ID du capteur : %2d\nDistance au noeud central: %.2f\nVoisins : {", i, graph->distances[0][i]);
        for(; tmp != NULL; tmp = tmp->next)
            printf("%d ",tmp->dest);
        printf("}\nNombre de voisins: %2d\n", degree);
        if(degree == 0)
            printf("Remarque: Ce capteur n'a pas de voisins. Donner une sortie en tant que 'noeud isolé'\n");
        printf("\n");
    }
}

void printAdjMatrix(int **matrix, int n) {
    for(int i = 0; i < n; ++i) {
        printf("%2d\t", i);
        for(int j = 0; j < n; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}