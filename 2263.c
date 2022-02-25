#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

int n = 0;
int pre[MAX], in[MAX], post[MAX];

void solve(int in_start, int in_end, int post_start, int post_end)
{
    if(in_start > in_end || post_start > post_end)
        return;
    int root = post[post_end];
    printf("%d ", root);
    int in_right = pre[root];
    int left = in_right - in_start;
    solve(in_start, in_right, post_start, post_start + left - 1);
    solve(in_right + 1, in_end, post_start + left, post_end-1);
}

int main(void)
{
    int i;

    scanf("%d", &n);
    
    for(i=0;i<n;i++)
        scanf("%d", &in[i]);

    for(i=0;i<n;i++)
        scanf("%d", &post[i]);

    for(i=0;i<n;i++)
        pre[in[i]] = i;

    solve(0, n-1, 0, n-1);
    printf("\n");

    return 0;
}