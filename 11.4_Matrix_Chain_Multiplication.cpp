#include <iostream>
#include <algorithm>
using namespace std;

static const int N = 100;

int main(void)
{
    int i, j, k, len;
    int n, p[N+1], m[N+1][N+1];

    scanf("%d", &n);

    for(i=1;i<=n;i++)
        scanf("%d %d", &p[i-1], &p[i]);

    for(i=1;i<=n;i++)
        m[i][i] = 0;

    for(len=2;len<=n;len++)
    {
        for(i=1;i<=n-len+1;i++)
        {
            j = i + len - 1;
            m[i][j] = (1 << 21);
            for(k=i;k<=j-1;k++)
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]);
        }
    }

    printf("%d\n", m[1][n]);

    return 0;
}