#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct NODE{
    int key;
    struct NODE *right, *left, *parent;
} Node;

Node *root;

Node *treeMin(Node *x)
{
    while(x->left != NULL)
        x = x->left;
    return x;
}

Node *treeSuccessor(Node *x)
{
    if(x->right != NULL)
        return treeMin(x->right);
    Node *y = x->parent;
    while(y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

void treeDelete(Node *z)
{
    Node *y;
    Node *x;

    if(z->left == NULL || z->right == NULL)
        y = z;
    else
        y = treeSuccessor(z);

    if(y->left != NULL)
        x = y->right;
    else
        x = y->right;

    if(x != NULL)
        x->parent = y->parent;
    
    if(y->parent == NULL)
        root = x;
    else
    {
        if(y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    }

    if(y != z)
        z->key = y->key;
    
    free(y);

}


Node *find(Node *u, int target)
{
    while(u != NULL && target != u->key)
    {
        if(target < u->key)
            u = u->left;
        else
            u = u->right;
    }
    return u;
}

void insert(int k)
{
    Node *y = NULL;
    Node *x = root;
    Node *z = (Node *)malloc(sizeof(Node));

    z->key = k;
    z->left = NULL;
    z->right = NULL;

    while(x != NULL)
    {
        y = x;
        if(z->key < x->key)
            x = x -> left;
        else
            x = x -> right;
    }

    z->parent = y;
    if(y == NULL)
        root = z;
    else{
        if(z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }
}

void inorder(Node *u)
{
    if(u == NULL)
        return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u)
{
    if(u == NULL)
        return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(void)
{
    int n, i, x;
    char buffer[100];
    string com;
    
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%s", buffer);
        com = buffer;
        if(buffer[0] == 'f')
        {
            scanf("%d", &x);
            Node *t = find(root, x);
            if(t != NULL)
                printf("yes\n");
            else
                printf("no\n");
        }
        else if(com == "insert")
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(com == "print")
        {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
        else if(com == "delete")
        {
            scanf("%d", &x);
            treeDelete(find(root, x));
        }
    }


    return 0;
}