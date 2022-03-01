#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
static const int N = 1000;

int lcs(string X, string Y)
{
    int i, j;
    int c[N+1][N+1];
    int m = X.size();
    int n = Y.size();
    int maxl = 0;

    X = ' ' + X;
    Y = ' ' + Y;

    for(i=0;i<=m;i++)
        c[i][0] = 0;
    for(j=0;j<=n;j++)
        c[0][j] = 0;
    
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(X[i] == Y[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            maxl = max(maxl, c[i][j]);
        }
    }
    return maxl;
}

int main(void)
{
    string s1, s2;
    int i, n;
    char buffer1[N];
    char buffer2[N];
    
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%s %s", buffer1, buffer2);
        s1 = buffer1;
        s2 = buffer2;
        printf("%d\n", lcs(s1, s2));
    }

    return 0;
}