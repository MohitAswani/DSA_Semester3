#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

struct tree_24
{
    int item[MAX + 1], cntr;
    struct tree_24 *l[MAX + 1];
};

struct tree_24 *root;


struct tree_24 *create(int item, struct tree_24 *child)
{
    struct tree_24 *newNode;
    newNode = (struct tree_24 *)malloc(sizeof(struct tree_24));
    newNode->item[1] = item;
    newNode->cntr = 1;
    newNode->l[0] = root;
    newNode->l[1] = child;
    return newNode;
}


void insert_val(int item, int position, struct tree_24 *node,
                 struct tree_24 *child)
{
    int j = node->cntr;
    while (j > position)
    {
        node->item[j + 1] = node->item[j];
        node->l[j + 1] = node->l[j];
        j--;
    }
    node->item[j + 1] = item;
    node->l[j + 1] = child;
    node->cntr++;
}

void split(int item, int *pval, int position, struct tree_24 *node,
               struct tree_24 *child, struct tree_24 **newNode)
{
    int median, j;

    if (position > MIN)
        median = MIN + 1;
    else
        median = MIN;

    *newNode = (struct tree_24 *)malloc(sizeof(struct tree_24));
    j = median + 1;
    while (j <= MAX)
    {
        (*newNode)->item[j - median] = node->item[j];
        (*newNode)->l[j - median] = node->l[j];
        j++;
    }
    node->cntr = median;
    (*newNode)->cntr = MAX - median;

    if (position <= MIN)
    {
        insert_val(item, position, node, child);
    }
    else
    {
        insert_val(item, position - median, *newNode, child);
    }
    *pval = node->item[node->cntr];
    (*newNode)->l[0] = node->l[node->cntr];
    node->cntr--;
}

int set_val(int item, int *pval,
                 struct tree_24 *node, struct tree_24 **child)
{
    int position;
    if (!node)
    {
        *pval = item;
        *child = NULL;
        return 1;
    }

    if (item < node->item[1])
    {
        position = 0;
    }
    else
    {
        for (position = node->cntr;
             (item < node->item[position] && position > 1); position--)
            ;
        if (item == node->item[position])
        {
            printf("Duplicates not allowed\n");
            return 0;
        }
    }
    if (set_val(item, pval, node->l[position], child))
    {
        if (node->cntr < MAX)
        {
            insert_val(*pval, position, node, *child);
        }
        else
        {
            split(*pval, pval, position, node, *child, child);
            return 1;
        }
    }
    return 0;
}

void insert(int item)
{
    int flag, i;
    struct tree_24 *child;

    flag = set_val(item, &i, root, &child);
    if (flag)
        root = create(i, child);
}
void copy(struct tree_24 *node_temp, int position)
{
    struct tree_24 *t;
    t = node_temp->l[position];

    for (; t->l[0] != NULL;)
        t = t->l[0];
    node_temp->item[position] = t->item[1];
}

void rem_val(struct tree_24 *node_temp, int position)
{
    int i = position + 1;
    while (i <= node_temp->cntr)
    {
        node_temp->item[i - 1] = node_temp->item[i];
        node_temp->l[i - 1] = node_temp->l[i];
        i++;
    }
    node_temp->cntr--;
}

void rightShift(struct tree_24 *node_temp, int position)
{
    struct tree_24 *x = node_temp->l[position];
    int j = x->cntr;

    while (j > 0)
    {
        x->item[j + 1] = x->item[j];
        x->l[j + 1] = x->l[j];
    }
    x->item[1] = node_temp->item[position];
    x->l[1] = x->l[0];
    x->cntr++;

    x = node_temp->l[position - 1];
    node_temp->item[position] = x->item[x->cntr];
    node_temp->l[position] = x->l[x->cntr];
    x->cntr--;
    return;
}

void leftShift(struct tree_24 *node_temp, int position)
{
    int j = 1;
    struct tree_24 *x = node_temp->l[position - 1];

    x->cntr++;
    x->item[x->cntr] = node_temp->item[position];
    x->l[x->cntr] = node_temp->l[position]->l[0];

    x = node_temp->l[position];
    node_temp->item[position] = x->item[1];
    x->l[0] = x->l[1];
    x->cntr--;

    while (j <= x->cntr)
    {
        x->item[j] = x->item[j + 1];
        x->l[j] = x->l[j + 1];
        j++;
    }
    return;
}

void mergeNodes(struct tree_24 *node_temp, int position)
{
    int j = 1;
    struct tree_24 *x1 = node_temp->l[position], *x2 = node_temp->l[position - 1];

    x2->cntr++;
    x2->item[x2->cntr] = node_temp->item[position];
    x2->l[x2->cntr] = node_temp->l[0];

    while (j <= x1->cntr)
    {
        x2->cntr++;
        x2->item[x2->cntr] = x1->item[j];
        x2->l[x2->cntr] = x1->l[j];
        j++;
    }

    j = position;
    while (j < node_temp->cntr)
    {
        node_temp->item[j] = node_temp->item[j + 1];
        node_temp->l[j] = node_temp->l[j + 1];
        j++;
    }
    node_temp->cntr--;
    free(x1);
}

void adjust(struct tree_24 *node_temp, int position)
{
    if (!position)
    {
        if (node_temp->l[1]->cntr > MIN)
        {
            leftShift(node_temp, 1);
        }
        else
        {
            mergeNodes(node_temp, 1);
        }
    }
    else
    {
        if (node_temp->cntr != position)
        {
            if (node_temp->l[position - 1]->cntr > MIN)
            {
                rightShift(node_temp, position);
            }
            else
            {
                if (node_temp->l[position + 1]->cntr > MIN)
                {
                    leftShift(node_temp, position + 1);
                }
                else
                {
                    mergeNodes(node_temp, position);
                }
            }
        }
        else
        {
            if (node_temp->l[position - 1]->cntr > MIN)
                rightShift(node_temp, position);
            else
                mergeNodes(node_temp, position);
        }
    }
}

int del_val(int item, struct tree_24 *node_temp)
{
    int position, flag = 0;
    if (node_temp)
    {
        if (item < node_temp->item[1])
        {
            position = 0;
            flag = 0;
        }
        else
        {
            for (position = node_temp->cntr; (item < node_temp->item[position] && position > 1); position--)
                ;
            if (item == node_temp->item[position])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if (flag)
        {
            if (node_temp->l[position - 1])
            {
                copy(node_temp, position);
                flag = del_val(node_temp->item[position], node_temp->l[position]);
                if (flag == 0)
                {
                }
            }
            else
            {
                rem_val(node_temp, position);
            }
        }
        else
        {
            flag = del_val(item, node_temp->l[position]);
        }
        if (node_temp->l[position])
        {
            if (node_temp->l[position]->cntr < MIN)
                adjust(node_temp, position);
        }
    }
    return flag;
}

void delete (int item, struct tree_24 *node_temp)
{
    struct tree_24 *tmp;
    if (!del_val(item, node_temp))
    {
        printf("Not present\n");
        return;
    }
    else
    {
        if (node_temp->cntr == 0)
        {
            tmp = node_temp;
            node_temp = node_temp->l[0];
            free(tmp);
        }
    }
    root = node_temp;
    return;
}
void traversal(struct tree_24 *node_temp)
{
    int i;
    if (node_temp)
    {
        int j = 0;
        for (i = 0; i < node_temp->cntr; i++)
        {
            traversal(node_temp->l[i]);
            printf("%d ", node_temp->item[i + 1]);
        }
        if (i != j)
            traversal(node_temp->l[i]);
    }
}
typedef struct data_type
{
    int d;
    char c;
    struct data_type *p;
    struct data_type *r;
    struct data_type *l;
} node;

node *ROOT = NULL;

node *traverse(node *n, node *temp)
{
    if (n == NULL)
        return temp;

    if (temp->d < n->d)
    {
        n->l = traverse(n->l, temp);
        n->l->p = n;
    }
    else if (temp->d > n->d)
    {
        n->r = traverse(n->r, temp);
        n->r->p = n;
    }
    return n;
}
void right_rot(node *temp)
{
    node *left = temp->l;
    temp->l = left->r;
    if (temp->l)
        temp->l->p = temp;
    left->p = temp->p;
    if (!temp->p)
        ROOT = left;
    else if (temp == temp->p->l)
        temp->p->l = left;
    else
        temp->r->p = left;

    left->r = temp;
    temp->p = left;
}
void left_rot(node *temp)
{
    node *right = temp->r;
    temp->r = right->r;
    if (temp->r)
        temp->r->p = temp;
    right->p = temp->p;
    if (!temp->p)
        ROOT = right;
    else if (temp == temp->p->r)
        temp->p->r = right;
    else
        temp->r->p = right;

    right->r = temp;
    temp->p = right;
}

void RBT_prop(node *r, node *pt)
{
    node *pt_parent = NULL;
    node *pt_grand_parent = NULL;

    while ((pt != r) && (pt->c != 'B') && (pt->p->c == 'R'))
    {
        pt_parent = pt->p;
        pt_grand_parent = pt->p->p;

        if (pt_parent == pt_grand_parent->l)
        {
            node *pt_uncle = pt_grand_parent->r;
            if (pt_uncle != NULL && pt_uncle->c == 'R')
            {
                pt_grand_parent->c = 'R';
                pt_parent->c = 'B';
                pt_uncle->c = 'B';
            }
            else
            {
                if (pt == pt_parent->r)
                {
                    left_rot(pt_parent);
                    pt = pt_parent;
                    pt_parent = pt->p;
                }

                right_rot(pt_grand_parent);
                char tclr = pt_parent->c;
                pt_parent->c = pt_grand_parent->c;
                pt_grand_parent->c = tclr;
                pt = pt_parent;
            }
        }
        else
        {
            node *pt_uncle = pt_grand_parent->r;

            if ((pt_uncle != NULL) && (pt_uncle->c == 1))
            {
                pt_grand_parent->c = 1;
                pt_parent->c = 0;
                pt_uncle->c = 0;
                pt = pt_grand_parent;
            }
            else
            {
                if (pt == pt_parent->l)
                {
                    right_rot(pt_parent);
                    pt = pt_parent;
                    pt_parent = pt->p;
                }

                left_rot(pt_grand_parent);
                int t = pt_parent->c;
                pt_parent->c = pt_grand_parent->c;
                pt_grand_parent->c = t;
                pt = pt_parent;
            }
        }
    }
    r->c = 'B';
}
void inorder(node* trav)
{
    if (trav == NULL)
        return;
    inorder(trav->l);
    printf("%d ", trav->d);
    inorder(trav->r);
}
int main()
{
    printf("2-4 TREE:");
    insert(10);
    insert(1);
    insert(2);
    insert(5);
    insert(6);
    insert(8);
    insert(9);
    insert(3);
    insert(4);
    insert(7);
    traversal(root);
    printf("\n");
    delete (3, root);
    delete (5, root);
    delete (9, root);

    printf("RED BLACK TREE:");
    int n = 6;
    int a[6] = {41,38,31,12,19,8};

    for (int i = 0; i < n; i++)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->r = NULL;
        temp->l = NULL;
        temp->p = NULL;
        temp->d = a[i];
        temp->c = 1;

        ROOT= traverse(ROOT, temp);

        RBT_prop(ROOT, temp);
    }

    inorder(ROOT);

    return 0;
}