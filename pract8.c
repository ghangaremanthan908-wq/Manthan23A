#include <stdio.h>
#define V 5

int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

int colorGraph(int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return 1;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (colorGraph(graph, m, color, v + 1))
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    int graph1[V][V] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };

    int graph2[V][V] = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}
    };

    int color[V] = {0};
    int m = 3;

    printf("Graph 1:\n");
    if (colorGraph(graph1, m, color, 0)) {
        for (int i = 0; i < V; i++)
            printf("Vertex %d -> Color %d\n", i + 1, color[i]);
    } else {
        printf("No solution exists.\n");
    }

    for (int i = 0; i < V; i++)
        color[i] = 0;

    printf("\nGraph 2:\n");
    if (colorGraph(graph2, m, color, 0)) {
        for (int i = 0; i < V; i++)
            printf("Vertex %d -> Color %d\n", i + 1, color[i]);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}