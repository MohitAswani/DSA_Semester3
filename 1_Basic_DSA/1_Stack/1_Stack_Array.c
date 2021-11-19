#include <stdio.h>
#define size 100
int stack[size];
int top = -1;
void peek(){
    if(top==-1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("CURRENT ELEMENT:%d\n",stack[top]);
    }
}
int isFull()
{
    if (top==size-1)
    {
        return 1;
    }
    else
        return 0;
}
void push(int data)
{
    if (!isFull())
    {
        top += 1;
        stack[top] = data;
    }
    else
        printf("STACK IS FULL\n");
}
void print()
{
    if (top != -1)
    {
        printf("STACK: ");
        for (int i = 0; i <=top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("STACK IS EMPTY\n");
    }
}
void pop(){
    if(top==-1)
    {
        printf("YOU CANNOT POP THE DATA SINCE THE STACK IS EMPTY");
        return ;
    }
    top--;
}
int main()
{
    print();
    for(int i=1;i<=10;i++)
    {
        push(i);
    }
    print();
    for(int i=1;i<=7;i++)
    {
        pop();
    }
    print();
    peek();
    return 0;
}
