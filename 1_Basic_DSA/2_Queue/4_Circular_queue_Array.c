#include <stdio.h>
#define size 10
int queue[size];
int front = -1;
int rear = -1;
int isFull()
{
    if (front == 0 && rear == size - 1)
    {
        return 1;
    }
    else if (front == rear + 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}
void enqueue(int data)
{
    if (isFull() != 1)
    {
        if (front == -1)
        {
            front++;
            rear++;
            queue[front] = data;
        }
        else
        {
            rear++;
            rear = rear % size;
            queue[rear] = data;
        }
    }
    else
    {
        printf("SORRY THE QUEUE IS FULL\n");
    }
}
void denqueue()
{
    if (isEmpty() != 1)
    {
        if (front == rear)
        {
            queue[rear] = 0;
            front = rear = -1;
        }
        else
        {
            printf("ELEMENT BEING DENQUEUED:%d \n", queue[front]);
            queue[front] = 0;
            front++;
        }
    }
    else
    {
        printf("SORRY THE QUEUE IS EMPTY HENCE IT CANNOT BE denqueueED\n");
    }
}
void display()
{
    if (isEmpty() != 1)
    {
        int i = front;
        printf("QUEUE:");
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i++;
            i = i % size;
        }
        printf("%d \n", queue[rear]);
    }
    else
    {
        printf("QUEUE IS EMPTY\n");
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
