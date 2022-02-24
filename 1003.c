#include <stdio.h>
#define MAX 50

int main(void)
{
    int i, n, t;
    int cnt_zero[MAX] = {1, 0, };
    int cnt_one[MAX] = {0, 1, };

    scanf("%d", &t);
    for(i=2;i<MAX;i++){
        cnt_zero[i] = cnt_zero[i-2] + cnt_zero[i-1];
        cnt_one[i] = cnt_one[i-2] + cnt_one[i-1];
    }
    for(i=0;i<t;i++){
        scanf("%d", &n);
        printf("%d %d\n", cnt_zero[n], cnt_one[n]);
    }

    return 0;
}
