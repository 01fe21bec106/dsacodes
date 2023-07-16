
#include <limits.h>
#include <stdio.h>
#include<stdlib.h>

int min_dist(int dist[], int visited[],int V)
{
    int v;
 int min = INT_MAX, min_index;

 for ( v = 0; v < V; v++)
  if (visited[v] == 0 && dist[v] < min)
        {
            min = dist[v];
   min_index = v;
        }
 return min_index;
}


int printMST(int path[], int graph[100][100], int V)
{
    int i;
 printf("Edge \tWeight\n");
 for (i = 1; i < V; i++)
  printf("%d - %d \t%d \n", path[i], i, graph[i][path[i]]);
}


void dijkstras(int graph[100][100],int V)
{
    int i;
 int path[V];
 int dist[V];
 int visited[V];

 for (i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
  visited[i] = 0;
    }

  int count;
 dist[0] = 0;
 path[0] = -1;
 for (count = 0; count < V - 1; count++)
    {

  int u = min_dist(dist, visited,V);

  visited[u] = 1;

    int v;
  for ( v = 0; v < V; v++)
        {
            if (graph[u][v] && visited[v] == 0 && graph[u][v]+dist[u] < dist[v])
            {
                path[v] = u;
    dist[v] = graph[u][v] + dist[u];
            }
        }

 }


 printMST(path, graph,V);
}

int main()
{
    int V;
    printf("Enter the number of nodes\t");
    scanf("%d",&V);

    int graph[100][100];
    printf("\nEnter the adjacency matrix\n");
    int i,j;
    for( i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            scanf("%d",&graph[i][j]);
    }

 dijkstras(graph,V);

 return 0;
}
/*
0 3 0 7 0
3 0 4 2 0
0 4 0 5 6
7 2 5 0 4
0 0 6 4 0*/
