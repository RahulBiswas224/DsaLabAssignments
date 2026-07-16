#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int adj[MAX][MAX] = {0}; // Adjacency Matrix
int visited[MAX] = {0};

// Depth First Search
void dfs(int start) {
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < MAX; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

// Breadth First Search
void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    int visitedBfs[MAX] = {0};
    
    queue[rear++] = start;
    visitedBfs[start] = 1;
    
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        for (int i = 0; i < MAX; i++) {
            if (adj[curr][i] == 1 && !visitedBfs[i]) {
                visitedBfs[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    // Creating a simple graph
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;

    printf("DFS traversal: ");
    dfs(0);
    
    // Reset visited for BFS
    for(int i=0; i<MAX; i++) visited[i] = 0; 
    
    printf("\nBFS traversal: ");
    bfs(0);
    return 0;
}