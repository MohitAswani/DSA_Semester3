#include <stdio.h>
#include <stdlib.h>
typedef struct data_type
{
    int data;
    struct data_type *link;
} node;
node *top = NULL;
void push(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    if (top == NULL)
    {
        top = ptr;
        top->link = NULL;
    }
    else
    {
        node *temp = top;
        top = ptr;
        ptr->link = temp;
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("SORRY ITS EMPTY :(\n");
    }
    else
    {
        node *temp = top;
        top = top->link;
        free(temp);
    }
}
void print()
{
    node *t = top;
    printf("STACK: ");
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->link;
    }
    printf("\n");
}
int main()
{
    for (int i = 1; i <= 5; i++)
        push(i);

    print();

    for (int i = 1; i <= 3; i++)
        pop();

    print();
    return 0;
}
