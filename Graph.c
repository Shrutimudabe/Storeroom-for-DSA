#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Graph representation using adjacency matrix
int adjMatrix[MAX][MAX] = {0};
int visited[MAX] = {0};
int n; // Number of vertices

void addEdgeMatrix(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For undirected graph
}

void bfsMatrix(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void dfsMatrix(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsMatrix(i);
        }
    }
}
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX] = {NULL};

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdgeList(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u); // For undirected graph
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void bfsList(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node* temp = adjList[current];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void dfsList(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    Node* temp = adjList[vertex];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfsList(temp->vertex);
        }
        temp = temp->next;
    }
}
int main() {
    n = 5; // Number of vertices
    // Adjacency Matrix Example
    addEdgeMatrix(0, 1);
    addEdgeMatrix(0, 2);
    addEdgeMatrix(1, 3);
    addEdgeMatrix(1, 4);

    printf("Using Adjacency Matrix:\n");
    bfsMatrix(0);
    for (int i = 0; i < n; i++) visited[i] = 0; // Reset visited array
    printf("DFS: ");
    dfsMatrix(0);
    printf("\n");

    // Reset visited for adjacency list example
    for (int i = 0; i < n; i++) visited[i] = 0;

    // Adjacency List Example
    addEdgeList(0, 1);
    addEdgeList(0, 2);
    addEdgeList(1, 3);
    addEdgeList(1, 4);

    printf("Using Adjacency List:\n");
    bfsList(0);
    for (int i = 0; i < n; i++) visited[i] = 0; // Reset visited array
    printf("DFS: ");
    dfsList(0);
    printf("\n");

    return 0;
}
