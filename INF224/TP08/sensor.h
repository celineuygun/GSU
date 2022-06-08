#ifndef SENSOR_H_
#define SENSOR_H_

#define N_LINES 70

typedef struct SensorInformation {
    int id;
    float x_axe, y_axe, z_axe;
} SensorInfo;

typedef struct AdjacencyListNode {
    int dest;
    struct AdjacencyListNode *next;
} AdjListNode;

typedef struct AdjacencyList {
    AdjListNode *head;
} AdjList;

typedef struct graph {
    int n_vertices;
    float **distances;
    int **matrix;
    AdjList *arr;
} Graph;

void readFile(SensorInfo **sensors);
AdjListNode *newAdjListNode(int dest);
Graph* createGraph(int n_vertices, SensorInfo **sensors, int distance);
void addEdge(Graph* graph, int src, int dest);
SensorInfo *createSensorInfo(int id, float x_axe, float y_axe, float z_axe);
void printSensor(SensorInfo *sensor);
int findDegree(struct graph *graph, int ver);
float **calculateDistances(SensorInfo **locations,int n_line);
int **createAdjecencyMatrix(float **distances, int n_line, int distance);
void printGraph(Graph *graph);
void printAdjMatrix(int **matrix, int n);

#endif