#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct data_type
{
    struct data_type *lchild;
    struct data_type *rchild;
    int data;
} node;
node *insert(node *head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        node *cpy = head;
        node *prev = NULL;
        do
        {
            prev = cpy;
            if (data < cpy->data)
            {
                cpy = cpy->lchild;
            }
            else
            {
                cpy = cpy->rchild;
            }
        } while (cpy != NULL);
        if (data < prev->data)
        {
            prev->lchild = new_node;
        }
        else
        {
            prev->rchild = new_node;
        }
    }
    return head;
}
node *search(node *head, int data)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        node *cpy = head;
        do
        {
            if (data < cpy->data)
            {
                cpy = cpy->lchild;
            }
            else if (data > cpy->data)
            {
                cpy = cpy->rchild;
            }
            else
            {
                printf("NODE FOUND\n");
                return cpy;
            }
        } while (cpy != NULL);
    }
    printf("NODE NOT FOUND\n");
    return NULL;
}
node *findMax(node *n)
{
    while (n->rchild != NULL)
    {
        n = n->rchild;
    }
    return n;
}
node *delete (node *head, int data)
{
    node *cpy = head;
    node *prev = head;
    do
    {
        if (data < cpy->data)
        {
            cpy = cpy->lchild;
            if (cpy->data == data)
            {
                break;
            }
        }
        else if (data > cpy->data)
        {
            cpy = cpy->rchild;
            if (cpy->data == data)
            {
                break;
            }
        }
        else
        {
            break;
        }
        prev = cpy;
    } while (cpy != NULL);
    if (cpy != NULL)
    {
        if (cpy->lchild == NULL && cpy->rchild == NULL)
        {
            if (prev->lchild == cpy)
            {
                prev->lchild = NULL;
            }
            else
            {
                prev->rchild = NULL;
            }
            free(cpy);
        }
        else if (cpy->lchild == NULL && cpy->rchild != NULL)
        {
            if (prev->lchild == cpy)
            {
                prev->lchild = cpy->rchild;
            }
            else
            {
                prev->rchild = cpy->rchild;
            }
            free(cpy);
        }
        else if (cpy->lchild != NULL && cpy->rchild == NULL)
        {
            if (prev->lchild == cpy)
            {
                prev->lchild = cpy->lchild;
            }
            else
            {
                prev->rchild = cpy->lchild;
            }
            free(cpy);
        }
        else
        {
            node *leftmostMax = findMax(cpy->lchild);
            int temp = leftmostMax->data;
            delete (head, temp);
            cpy->data = temp;
        }
    }
    else
    {
        printf("NODE NOT PRESENT IN THE TREE\n");
    }
    return head;
}
int main()
{
    node *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 12);
    insert(root, 11);
    insert(root, 14);
    insert(root, 16);
    search(root,11);
    insert(root, 17);
    delete (root, 10);
    return 0;
}