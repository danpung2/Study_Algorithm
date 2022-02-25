#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, pos;
vector<int> pre, in, post;

void rec(int l, int r)
{
    if(l >= r)
        return;
    int root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    rec(l, m);
    rec(m+1, r);
    post.push_back(root);
}

void solve()
{
    int i;
    pos = 0;
    rec(0, pre.size());
    for(i=0;i<n;i++)
    {
        if(i > 0)
            printf(" ");
        printf("%d", post[i]);
    }
    printf("\n");
}

int main(void)
{
    int i, k;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &k);
        pre.push_back(k);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d", &k);
        in.push_back(k);
    }

    solve();

    return 0;
}