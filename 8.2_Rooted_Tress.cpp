#include <iostream>
using namespace std;

#define MAX 100005

typedef struct NODE
{
    int p, l, r;
} Node;

Node T[MAX];
int n, D[MAX];

void print(int u)
{
    int i, c;
    printf("node %d: ", u);
    printf("    parent = %d: ", T[u].p);
    printf("    depth = %d: ", D[u]);
    if(T[u].p == -1)
        printf("root, ");
    else if(T[u].l == -1)
        printf("leaf, ");
    else
        printf("internal node, ");
    
    printf("[");
    for(i=0, c=T[u].l; c != -1;i++, c=T[c].r)
    {
        if(i)
            printf(", ");
        printf("%d", c);
    }
    printf("]\n");
}

void rec(int u, int p)
{
    D[u] = p;
    if(T[u].r != -1)
        rec(T[u].r, p);
    if(T[u].l != -1)
        rec(T[u].l, p+1);

    return;
}

int main(void)
{
    int i, j, d, v, c, l, r;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        T[i].p = T[i].l = T[i].r = -1;
    
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &v, &d);
        for(j=0;j<d;j++)
        {
            scanf("%d", &c);
            if(j == 0)
                T[v].l = c;
            else
                T[l].r = c;
            l = c;
            T[c].p = v;
        }
    }

    for(i=0;i<n;i++)
    {
        if (T[i].p != -1)
            r = i;
    }

    rec(r, 0);

    for(i=0;i<n;i++)
        print(i);

    return 0;
}