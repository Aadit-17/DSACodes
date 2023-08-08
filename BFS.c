#include <stdio.h>

int N, M,q[20],visited[20],ADJ[7][7];
void createAdjMatrix(int Adj[][N + 1],
int arr[][2])
{
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            Adj[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++)
    {
        char x = arr[i][0];
        char y = arr[i][1];

        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}

void printAdjMatrix(int Adj[][N + 1])
{
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            printf("%d ", Adj[i][j]);
            ADJ[i][j]=Adj[i][j];
        }
        printf("\n");
    }
}

int main()
{
    N = 6;
    int arr[][2] = { { 1, 2 }, { 2, 5 }, { 5, 4 }, { 4, 1 }, { 1, 3 }, { 3, 2 }, { 4, 6 } };
    M = sizeof(arr) / sizeof(arr[0]);

    int Adj[N + 1][N + 1];

    for (int i=1;i<=N;i++)
    {
        q[i]=0;
        visited[i]=0;
    }

    createAdjMatrix(Adj, arr);
    printAdjMatrix(Adj);
    BFS();
    return 0;
}
int a[20][20],q[20], visited[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
    for (i=1;i<=n;i++)
        if(a[v][i] && !visited[i])
            q[++r]=i;
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[f++]);
    }
}
void BFS()
{
    int v;
    n=6;
    for (i=1;i<=n;i++)
    {
        q[i]=0;
        visited[i]=0;
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            a[i][j]=ADJ[i][j];
        }
    }
    printf("\n Enter the starting vertex:");
    char c;
    scanf("%s",&c);
    v=(int)c-64;
    bfs(v);
    printf("\n The node which are reachable are:\n");
    for (i=1;i<=n;i++)
        if(visited[i])
            printf("%c\t",(i+64));
        else
            printf("\n Bfs is not possible");
}
