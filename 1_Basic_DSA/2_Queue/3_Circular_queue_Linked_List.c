#include <stdio.h>
#include <stdlib.h>
typedef struct data_type
{
    int data;
    struct data_type *next;
} node;
node *front = NULL, *rear = NULL;
void enqueue(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        rear->next = front;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        temp->next = front;
    }
}
void denqueue()
{
    node *temp = front;
    if (front == NULL)
    {
        printf("EMPTY QUEUE\n");
    }
    else if (front == rear)
    {
        printf("ELEMENT BEING REMOVED: %d\n", rear->data);
        front = rear = NULL;
        free(temp);
    }
    else
    {
        printf("ELEMENT BEING REMOVED: %d\n", front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}
void display()
{
    if (front == NULL)
    {
        printf("EMPTY QUEUE\n");
    }
    else
    {
        node *temp = front;
        printf("QUEUE :");
        printf("%d ", temp->data);
        temp = temp->next;
        while (temp != front)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    display();
    for (int i = 0; i < 10; i++)
        enqueue(i);
    display();
    denqueue();
    denqueue();
    display();
    enqueue(2);
    enqueue(3);
    display();
    return 0;
}
