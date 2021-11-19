#include <stdio.h>
#include <stdlib.h>
typedef struct data_type
{
    int d;
    char c;
    struct data_type *p;
    struct data_type *l;
    struct data_type *r;
} node;

struct data_type *root = NULL;

node *normal_insertion(node *r, node *temp)
{
    if (r == NULL)
    {
        return temp;
    }

    if (temp->d < r->d)
    {
        r->l = normal_insertion(r->l, temp);
        r->l->p = r;
    }
    else if (temp->d > r->d)
    {
        r->r = normal_insertion(r->r, temp);
        r->r->p = r;
    }
    return r;
}
void rightrotate(node *temp)
{
    node *left = temp->l;
    temp->l = left->r;
    if (temp->l)
        temp->l->p = temp;
    left->p = temp->p;
    if (!temp->p)
        root = left;
    else if (temp == temp->p->l)
        temp->p->l = left;
    else
        temp->p->r = left;
    left->r = temp;
    temp->p = left;
}
void leftrotate(node *temp)
{
    node *right = temp->r;
    temp->r = right->l;
    if (temp->r)
        temp->r->p = temp;
    right->p = temp->p;
    if (!temp->p)
        root = right;
    else if (temp == temp->p->l)
        temp->p->l = right;
    else
        temp->p->r = right;
    right->l = temp;
    temp->p = right;
}
void red_black_prop(node *root, node *pt)
{
    node *parent = NULL;
    node *grand_parent = NULL;

    while ((pt != root) && (pt->c != 'B') && (pt->p->c == 'R'))
    {
        parent = pt->p;
        grand_parent = pt->p->p;
        if (parent == grand_parent->l)
        {
            node *uncle = grand_parent->r;

            if (uncle != NULL && uncle->c == 'R')
            {
                grand_parent->c = 'R';
                parent->c = 'B';
                uncle->c = 'B';
                pt = grand_parent;
            }
            else
            {
                if (pt == parent->r)
                {
                    leftrotate(parent);
                    pt = parent;
                    parent = pt->p;
                }

                rightrotate(grand_parent);
                char c = parent->c;
                parent->c = grand_parent->c;
                grand_parent->c = c;
                pt = parent;
            }
        }
        else
        {
            node *uncle = grand_parent->l;

            if ((uncle != NULL) && (uncle->c == 'R'))
            {
                grand_parent->c = 1;
                parent->c = 0;
                uncle->c = 0;
                pt = grand_parent;
            }
            else
            {
                if (pt == parent->l)
                {
                    rightrotate(parent);
                    pt = parent;
                    parent = pt->p;
                }

                leftrotate(grand_parent);
                int t = parent->c;
                parent->c = grand_parent->c;
                grand_parent->c = t;
                pt = parent;
            }
        }
    }
    root->c = 'B';
}
void inorder(node *trav)
{
    if (trav == NULL)
        return;
    inorder(trav->l);
    printf("%d ", trav->d);
    inorder(trav->r);
}
int main()
{
    int n = 7;
    int a[7] = {7, 6, 5, 4, 3, 2, 1};

    for (int i = 0; i < n; i++)
    {

        node *temp = (node *)malloc(sizeof(node));
        temp->r = NULL;
        temp->l = NULL;
        temp->p = NULL;
        temp->d = a[i];
        temp->c = 1;

        root = normal_insertion(root, temp);

        red_black_prop(root, temp);
    }

    printf("Inorder Traversal of Created Tree\n");
    inorder(root);

    return 0;
}