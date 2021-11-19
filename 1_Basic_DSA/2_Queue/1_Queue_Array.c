#include<stdio.h>
#define size 10
int rear=-1,front=-1;
int queue[size];
int isFull(){
    if(rear==size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if(front<-1||front>rear)
    return 1;
    else
    return 0;
}
void enqueue(int data)
{
    if(!isFull())
    {
        rear+=1;
        queue[rear]=data;
        return ;
    }
    else
    {
        printf("QUEUE IS FULL\n");
    }
}
void denqueue()
{
    if(!isEmpty())
    {
        front+=1;
        printf("FRONT IS: %d\n",queue[front]);
    }
    else
    {
        printf("THE QUEUE IS EMPTY\n");
    }
}
void print(){
    printf("QUEUE: ");
    for(int i=front+1;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main(){
    print();
    for(int i=1;i<=5;i++)
    {
        enqueue(i);
    }
    print();
}
