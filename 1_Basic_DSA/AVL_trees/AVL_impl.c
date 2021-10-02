
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct data_type
{
    int key;
    struct data_type *left;
    struct data_type *right;
    int height;
} node;
int max(int x, int y)
{
    return (x > y) ? x : y;
}
int getHeight(node *n)
{
    if (n == NULL)
        return 0;

    return n->height;
}
int getBalance(node *n)
{
    if (n == NULL)
        return 0;

    return getHeight(n->left) - getHeight(n->right);
}
node *rightRotate(node *n)
{
    node *x = n->left;
    node *t2 = x->right;

    x->right = n;
    n->left = t2;

    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}
node *leftRotate(node *n)
{
    node *y = n->right;
    node *t2 = y->left;

    y->left = n;
    n->right = t2;

    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->key = data;
        new_node->height = 1;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    else if (root->key > data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->key)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->key)
    {
        return rightRotate(root);
    }
    if (balance < -1 && data > root->right->key)
    {
        return leftRotate(root);
    }
    if (balance > 1 && data > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && data < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
node *minValueNode(node *n)
{
    node *curr = n;
    while (curr->left != NULL)
        curr = curr->left;

    return curr;
}
node *remove_nodes(node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->key)
        root->left = remove_nodes(root->left, data);
    else if (data > root->key)
        root->right = remove_nodes(root->right, data);
    else
    {
        if ((root->left == NULL && root->right == NULL))
        {
            free(root);
            root = NULL;
        }
        else if ((root->left == NULL))
        {
            node *temp = root;
            root = root->right;
            free(temp);
        }
        else if ((root->right == NULL))
        {
            node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = remove_nodes(root->right, temp->key);
        }
    }
    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left)>=0)
    {
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->left)<=0)
    {
        return leftRotate(root);
    }
    if (balance > 1 && getBalance(root->right)<0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right)>0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    
    /*
                4
               / \
             2     6
            / \   / \
            1  3  5  7
                      \
                       8  
                    
    */

    root = remove_nodes(root, 4);
    root = remove_nodes(root, 7);
    free(root);
    return 0;
}