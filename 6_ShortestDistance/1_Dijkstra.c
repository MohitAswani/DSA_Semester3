#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INF INT_MAX
#define V 4
#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b
/**
 * Dijkstra's algorithm: in this algorithm we need find the minimum distance of every vertices from a given source.
 *
 * This algorithm is quite similiar to the implemenation of Prim's algorithm (Not prim's algorithm)
 *
 * Explanation of dijkstra's algorithm : * first the distance of every vertex from the source is INT_MAX other than the source.
                                         * then we find the minimum distance vertex in the distance array.
                                         * then we go though all the adjacent vertices of this array and update the distances.
                                         (this operation is called RELAX)
                                         * and keep repeating the same process until we loop through all the vertices.
 *
 * Fact about dijkstra's algorithm : * Does not work if the graph contains negative weight edge.
                                     * And the shortest path a given vertex might change if we add common weight to all
                                     vertices.(this due to the fact the number of edges in path might be more even if
                                     the path if shortest)
 *
 * In this algorithm we need a data structure which does min key and update key operation quickly and the perfect data structure
 for that is priority queue/min heap.
 *
 * Implementation : * Create an empty priority queue (min heap).
                    * dist[V]={INF,INF,....INF}
                    * dist[s]=0
                    * Insert all the distances in priority queue.
                    * while(pq is not empty)
                      {
                          u=pq.extractmin   // O(V*logV) (Complexity for while and min heap operation combined)
                          Relax all the adjacent of u that are not in pq/not fixed.  // O(E*logV) (Complexity for while and relax operation combined)
                      }
                    *
                    * Time complexity : O(V*logV)+O(E*logV)
 *
 *
 * The only issue with this implementation is that priority queue do not have update key operation in cpp.
 *
 */
void dijkstra(int graph[V][V], int s)
{
    int dist[V];
    int fin[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        fin[i] = 0;
    }
    dist[s] = 0;
    for (int i = 0; i < V - 1; i++) // run this loop V-1 times since the last vertex will be decided anyways
    {
        int u = -1;
        for (int v = 0; v < V; v++)
        {
            if (fin[v] == 0 && (u == -1 || dist[u] > dist[v]))
            {
                u = v;
            }
        }
        fin[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && fin[v] == 0)
            {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        printf("SHORTEST PATH OF %d FROM %d : %d\n", s, i, dist[i]);
    }
    // Time complexity : O(V^2)

    // To make the algorithm more efficient we need to use adjacency list and min heap.
    // Time complexity is O((V+E)*logV)
}

int main()
{
    int graph[V][V] = {
        {0, 5, 8, 0},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {0, 15, 20, 0},
    };
    dijkstra(graph, 0);
    return 0;
}