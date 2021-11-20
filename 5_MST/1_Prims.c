#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define V 4
void prims(int graph[V][V])
{
    printf("PRIMS : \n\n");
    int cost = 0;
    int key[V];
    int mSet[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mSet[i] = 0;
        parent[i]=-1;
    }

    key[0] = 0;
    parent[0] = -1;

    printf("STEPS : \n");
    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (mSet[i] == 0 && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
            else if(mSet[i]==0&&u!=-1&&parent[i]!=-1)
            {
                // printf("Edge (%d,%d) is rejected because its not the small edge\n",parent[i],i);
            }
        }
        // printf("Edge (%d,%d) is selected\n",parent[u],u);
        mSet[u] = 1;
        cost += key[u];
        for (int v = 0; v < V; v++) // theta(V)
        {
            if (graph[u][v] != 0 && mSet[v] == 0 && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        printf("Edge %d:(%d, %d) cost:%d \n",
               (i + 1), parent[i], i, graph[i][parent[i]]);
    }
    printf("\nCost:%d\n",cost);
}
int main()
{
    int graph[V][V] = {
        {0, 5, 8, 0},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {0, 15, 20, 0},
    };
    prims(graph);

    return 0;
}