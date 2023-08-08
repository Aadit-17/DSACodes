#include <stdio.h>
#define INFINITY 999
#define MAX 10
void Dijkstra(int Graph[MAX][MAX], int n, int start);
void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];

    for (i = 0; i < n; i++)
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    for (i = 0; i < n; i++)
        printf("%d",distance[i]);
        printf("\n");
    for (i = 0; i < n; i++)
        printf("%d",pred[i]);
        printf("\n");
    for (i = 0; i < n; i++)
        printf("%d",visited[i]);

    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    char conv[8]={'A','B','C','D','E','F','O','T'};
    for (i = 0; i < n; i++)
        if (i != start)
        {
            printf("\nDistance from source to %c: %d", conv[i], distance[i]);
            printf("\n The path is: %c",conv[i]);
            j=i;
            do
            {
                j=pred[j];
                printf("<-%c",conv[j]);
            }
            while(j!=start);
        }
}

int main()
{
    int Graph[MAX][MAX], i, j, v, u;
    v=8;

    Graph[0][0] = 0;
    Graph[0][1] = 0;
    Graph[0][2] = 2;
    Graph[0][3] = 8;
    Graph[0][4] = 9;
    Graph[0][5] = 1;
    Graph[0][6] = 14;
    Graph[0][7] = 2;
    Graph[1][0] = 2;
    Graph[1][1] = 0;
    Graph[1][2] = 1;
    Graph[1][3] = 3;
    Graph[1][4] = 1;
    Graph[1][5] = 0;
    Graph[1][6] = 0;
    Graph[1][7] = 6;
    Graph[2][0] = 2;
    Graph[2][1] = 1;
    Graph[2][2] = 8;
    Graph[2][3] = 0;
    Graph[2][4] = 1;
    Graph[2][5] = 0;
    Graph[2][6] = 0;
    Graph[2][7] = 4;
    Graph[3][0] = 2;
    Graph[3][1] = 7;
    Graph[3][2] = 0;
    Graph[3][3] = 8;
    Graph[3][4] = 1;
    Graph[3][5] = 0;
    Graph[3][6] = 0;
    Graph[3][7] = 3;
    Graph[4][0] = 0;
    Graph[4][1] = 6;
    Graph[4][2] = 4;
    Graph[4][3] = 1;
    Graph[4][4] = 0;
    Graph[4][5] = 0;
    Graph[4][6] = 7;
    Graph[4][7] = 0;
    Graph[5][0] = 2;
    Graph[5][1] = 15;
    Graph[5][2] = 0;
    Graph[5][3] = 19;
    Graph[5][4] = 0;
    Graph[5][5] = 0;
    Graph[5][6] = 3;
    Graph[5][7] = 0;
    Graph[6][0] = 0;
    Graph[6][1] = 0;
    Graph[6][2] = 0;
    Graph[6][3] = 5;
    Graph[6][4] = 7;
    Graph[6][5] = 3;
    Graph[6][6] = 0;
    Graph[6][7] = 0;
    Graph[7][0] = 2;
    Graph[7][1] = 5;
    Graph[7][2] = 4;
    Graph[7][3] = 0;
    Graph[7][4] = 0;
    Graph[7][5] = 0;
    Graph[7][6] = 0;
    Graph[7][7] = 0;
    u = 0;
    Dijkstra(Graph, v, u);
    return 0;
}

