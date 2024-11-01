#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

const char direction[] = "DLRU";
const int dr[] = {1, 0, 0, -1};
const int dc[] = {0, -1, 1, 0};

typedef struct {
    int row;
    int col;
    int steps;
} State;

bool isValid(int r, int c, int m, int n) {
    return r >= 0 && c >= 0 && r < m && c < n;
}

int findShortestPath(int** maze, int m, int n, int startRow, int startCol) {
    State queue[m * n];
    int front = 0, rear = 0;

    int visited[m][n];
    memset(visited, 0, sizeof(visited));

    queue[rear++] = (State){startRow, startCol, 0};
    visited[startRow][startCol] = 1;

    while (front < rear) {
        State current = queue[front++];
        int currentRow = current.row;
        int currentCol = current.col;
        int currentSteps = current.steps;

        if (currentRow == m - 1 && currentCol == n - 1) {
            return currentSteps;
        }

        for (int i = 0; i < 4; i++) {
            int nextRow = currentRow + dr[i];
            int nextCol = currentCol + dc[i];

            if (isValid(nextRow, nextCol, m, n) && maze[nextRow][nextCol] == 1 && !visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = 1;
                queue[rear++] = (State){nextRow, nextCol, currentSteps + 1};
            }
        }
    }

    return -1; // No path found
}

int main() {
    int m, n;
    printf("Enter the size of the maze (m n, space-separated): ");
    scanf("%d %d", &m, &n);

    int** maze = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        maze[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    int startRow, startCol;
    printf("Enter the starting position (row and column, space-separated): ");
    scanf("%d %d", &startRow, &startCol);

    if (isValid(startRow, startCol, m, n) && maze[startRow][startCol] == 1) {
        int shortestPath = findShortestPath(maze, m, n, startRow, startCol);

        if (shortestPath == -1) {
            printf("No path found to exit.\n");
        } else {
            printf("Shortest path to exit: %d steps\n", shortestPath);
        }
    } else {
        printf("Invalid starting position.\n");
    }

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}
