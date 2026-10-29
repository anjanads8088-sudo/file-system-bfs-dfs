
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start, int target)
{
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        if (current == target)
            found = 1;

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS.\n");
    else
        printf("\nFile not found using BFS.\n");
}

void DFS(int current, int target, int *found)
{
    visited[current] = 1;
    printf("%d ", current);

    if (current == target)
        *found = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[current][i] && !visited[i])
            DFS(i, target, found);
    }
}

int main()
{
    int start, target;

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("Enter file/node to search: ");
    scanf("%d", &target);

    if (start < 0 || start >= n ||
        target < 0 || target >= n)
    {
        printf("Invalid node.\n");
        return 1;
    }

    BFS(start, target);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int found = 0;

    printf("DFS Traversal: ");
    DFS(start, target, &found);

    if (found)
        printf("\nFile found using DFS.\n");
    else
        printf("\nFile not found using DFS.\n");

    return 0;
}
