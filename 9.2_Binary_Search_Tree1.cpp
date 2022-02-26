#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

typedef struct NODE{
    int key;
    struct NODE *right, *left, *parent;
} Node;

Node *root;

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
        if(com == "insert")
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
    }

    return 0;
}

