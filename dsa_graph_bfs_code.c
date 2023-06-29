#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct {
    int data[MAX_VERTICES];
    int front, rear;
} Queue;

void initializeGraph(Graph* graph, int vertices);
void addEdge(Graph* graph, int src, int dest);
void breadthFirstSearch(Graph* graph, int startVertex, bool visited[]);

void initializeQueue(Queue* queue);
void enqueue(Queue* queue, int vertex);
int dequeue(Queue* queue);
bool isQueueEmpty(Queue* queue);

int main() {
    Graph graph;
    int vertices, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(&graph, vertices);

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    int i;
    for ( i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    bool visited[MAX_VERTICES] = { false };

    printf("Breadth-First Traversal:\n");

    for ( i = 0; i < graph.vertices; i++) {
        if (!visited[i]) {
            breadthFirstSearch(&graph, i, visited);
        }
    }

    return 0;
}

void initializeGraph(Graph* graph, int vertices) {
    graph->vertices = vertices;
    int i,j;
    for ( i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;

}

void breadthFirstSearch(Graph* graph, int startVertex, bool visited[]) {
    Queue queue;
    initializeQueue(&queue);
    visited[startVertex] = true;
    enqueue(&queue, startVertex);

    while (!isQueueEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);
  int i;
        for ( i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                enqueue(&queue, i);
            }
        }
    }
}

void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

void enqueue(Queue* queue, int vertex) {
    if (queue->rear == MAX_VERTICES - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->data[queue->rear] = vertex;
}

int dequeue(Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int vertex = queue->data[queue->front];
    queue->front++;

    return vertex;
}

bool isQueueEmpty(Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}
