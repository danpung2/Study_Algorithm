#include <stdio.h>
#define MAX 10000

typedef struct NODE
{
    int p, l, r;
} Node;
Node T[MAX];
int n;

void preParse(int u)
{
    if(u == -1)
        return;
    printf(" %d", u);
    preParse(T[u].l);
    preParse(T[u].r);
}

void inParse(int u)
{
    if(u == -1)
        return;
    inParse(T[u].l);
    printf(" %d", u);
    inParse(T[u].r);
}

void postParse(int u)
{
    if(u == -1)
        return;
    postParse(T[u].l);
    postParse(T[u].r);
    printf(" %d", u);
}

int main(void)
{
    int i, v, l, r, root;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        T[i].p = -1;

    for(i=0;i<n;i++)
    {
        scanf("%d %d %d", &v, &l, &r);
        T[v].l = l;
        T[v].r = r;
        if(l != -1)
            T[l].p = v;
        if(r != -1)
            T[r].p = v;
    }

    for(i=0;i<n;i++)
    {
        if(T[i].p == -1)
            root = i;
    }

    printf("Preorder\n");
    preParse(root);
    printf("\n");
    printf("Inorder\n");
    inParse(root);
    printf("\n");
    printf("Postorder\n");
    postParse(root);
    printf("\n");
    
    return 0;
}