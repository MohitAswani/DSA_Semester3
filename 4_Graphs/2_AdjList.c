#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define INF INT_MAX
#define V 5
typedef struct data_type1{
    int value;
    int weight;
    struct data_type1 *next;
}node;
typedef struct data_type2{
    node *head;
}nodeList;
typedef struct data_type3{
    int numV;
    nodeList *vertices;
}graph;
graph *createGraph(int v)
{
    graph *g1=(graph *)malloc(sizeof(graph));
    g1->numV=v;

    g1->vertices=(nodeList *)malloc(v*sizeof(nodeList));

    for(int i=0;i<v;i++)
    {
        g1->vertices[i].head=NULL;
    }

    return g1;
}

void addEdge(graph *g,int src,int dest,int w)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->value=dest;
    temp->weight=w;
    temp->next=g->vertices[src].head;
    g->vertices[src].head=temp;

    node *temp1=(node *)malloc(sizeof(node));
    temp1->value=src;
    temp1->weight=w;
    temp1->next=g->vertices[dest].head;
    g->vertices[dest].head=temp1;
}
void printGraph(graph *g)
{
    for(int i=0;i<g->numV;i++)
    {
        printf("%d : ",i);
        node *temp=g->vertices[i].head;
        while(temp)
        {
            printf("%d ",temp->value);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    graph *g1=createGraph(V);
    addEdge(g1,0,1,1);
    addEdge(g1,1,2,1);
    addEdge(g1,2,4,1);

    printGraph(g1);
    return 0;
}