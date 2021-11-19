#include<stdio.h>
#include<stdlib.h>
typedef struct data_type{
    int data;
    struct data_type* link;
}node;
node* front=NULL;
node* rear=NULL;
void enqueue(int data)
{
    node* ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    if(front==NULL)
    {
        front=rear=ptr;
        front->link=NULL;
        rear->link=NULL;
    }
    else
    {
        node* temp=rear;
        rear=ptr;
        temp->link=ptr;
        ptr->link=NULL;
    }
}
void denqueue(){
    if(rear==NULL)
    {
        printf("SORRY QUEUE IS EMPTY :(\n");
    }
    else
    {
        node *temp=front;
        front=front->link;
        free(temp);
    }
}
void print(){
    node *t=front;
    printf("QUEUE IS: ");
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->link;
    }
    printf("\n");
}
int main(){
    for(int i=1;i<=5;i++)
    enqueue(i);

    print();
    
    for(int i=1;i<=3;i++)
    denqueue();

    print();

    for(int i=1;i<=2;i++)
    denqueue();

    print();
    return 0;
}
