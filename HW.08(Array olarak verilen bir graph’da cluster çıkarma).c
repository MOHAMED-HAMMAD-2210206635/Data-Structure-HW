#include <stdio.h>

int done[10] = {0};
int graph[10][10] = {
    {0, 1, 1, 0, 0}, 
    {1, 0, 1, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1}, 
    {0, 0, 0, 1, 0}
};

void search(int node, int total) {
    done[node] = 1;
    printf("%d ", node);
    for (int j = 0; j < total; j++) {
        if (graph[node][j] == 1 && done[j] == 0) {
            search(j, total);
        }
    }
}

int main() {
    int i;
    printf("Nodes in each cluster:\n");
    for (i = 0; i < 5; i++) {
        if (done[i] == 0) {
            printf("Group: ");
            search(i, 5);
            printf("\n");
        }
    }
    return 0;
}
------------------------------------------------------------
------------------------------------------------------------
How to find clusters?
We can find clusters by looking for nodes that are connected to each other. I used a simple DFS (Depth First Search) to visit all reachable nodes from a starting point. Every group of connected nodes is called a "Cluster".

How they are separated? 
They are separated if there is no edge (path) between them. In the code, if the adjacency matrix has a 0 between two nodes, it means they are not in the same group.
