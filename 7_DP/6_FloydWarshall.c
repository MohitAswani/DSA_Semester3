#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INF INT_MAX
#define V 4
#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b
/**
 * @brief In this algorithm we basically try to find the shortest path between two vertices by interating though all the 
 * vertices and checking if a shorter path between any two vertices exists through the selected vertex. If yes then we update
 * the path.
 * 
 * @param graph Input graph
 */
void floydWarshall(int graph[V][V])
{
    long long dist[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];


    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);


    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if(dist[i][j]==INT_MAX)
            printf(" INF ");
            else
            printf("%5d",dist[i][j]);
        }
        printf("\n");
    }
            

}

int main()
{
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    floydWarshall(graph);
    return 0;
}