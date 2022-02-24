#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct POINT{
    int x, y;
} Point;

int comp(const void *x, const void *y);

int main(void)
{
    int n;
    int i;
    Point p[MAX];
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    qsort(p, n, sizeof(Point), comp);
    for(i=0;i<n;i++)
        printf("%d %d\n", p[i].x, p[i].y);
    
    return 0;
}

int comp(const void* x, const void *y)
{
    Point p1 = *(Point *)x;
    Point p2 = *(Point *)y;

    if(p1.x == p2.x){
        if(p1.y > p2.y)
            return 1;
        else if(p1.y < p2.y)
            return 0;
        else
            return -1;
    }
    else {
        if(p1.x > p2.x)
            return 1;
        else if(p1.x < p2.x)
            return 0;
        else
            return -1;
    }
}