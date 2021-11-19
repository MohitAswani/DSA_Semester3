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
typedef struct data_type4
{
    int data;
    struct data_type4 *link;
} qnode;
qnode *front = NULL;
qnode *rear = NULL;

void enqueue(int data)
{
    qnode *ptr = (qnode *)malloc(sizeof(qnode));
    ptr->data = data;
    if (front == NULL)
    {
        front = rear = ptr;
        front->link = NULL;
        rear->link = NULL;
    }
    else
    {
        qnode *temp = rear;
        rear = ptr;
        temp->link = ptr;
        ptr->link = NULL;
    }
}
void denqueue()
{
    if (rear == NULL)
    {
        printf("SORRY QUEUE IS EMPTY :(\n");
    }
    else if(front==rear)
    {
        qnode *temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else
    {
        qnode *temp = front;
        front = front->link;
        free(temp);
    }
}

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
void BFS_helper(graph *g,int i,int visited[])
{
    visited[i]=1;
    enqueue(i);
    while(rear!=NULL)
    {
        int u=front->data;
        denqueue();
        printf("%d ",u);
        node *temp=g->vertices[u].head;
        while(temp!=NULL)
        {
            if(visited[temp->value]==0)
            {
                enqueue(temp->value);
                visited[temp->value]=1;
            }
            temp=temp->next;
        }
    }
}
void BFS(graph *g)
{
    int visited[g->numV];
    for(int i=0;i<g->numV;i++)
    visited[i]=0;

    printf("BFS : ");
    for(int i=0;i<g->numV;i++)
    {
        if(visited[i]==0)
        {
            BFS_helper(g,i,visited);
        }
    }
    printf("\n");
}
int main(){
    graph *g1=createGraph(V);
    addEdge(g1,0,1,1);
    addEdge(g1,1,2,1);
    addEdge(g1,2,4,1);
    addEdge(g1,1,3,1);

    printGraph(g1);

    BFS(g1);
    return 0;
}