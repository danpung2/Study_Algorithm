#include <stdio.h>
#define MAX 50
#define TRUE 1
#define FALSE 0

int solve(int n, int arr[], int i, int m){
    if(m == 0)
        return TRUE;
    if(i >= n)
        return FALSE;
    int res = solve(n, arr, i+1, m) || solve(n, arr, i+1, m-arr[i]);

    return res;
}

int main(void)
{
    int n, arr[MAX];
    int q, m, i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    scanf("%d", &q);
    for(i=0;i<q;i++){
        scanf("%d", &m);
        if(solve(n, arr, 0, m) == FALSE)
            printf("no\n");
        else
            printf("yes\n");
    }

    return 0;
}