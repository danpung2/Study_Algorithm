#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 1000;
static const int VMAX = 10000;

int n, A[MAX], s;
int B[MAX], T[VMAX + 1];

int solve(){
    int answer = 0;
    bool V[MAX];
    int i;
    for(i=0;i<n;i++){
        B[i] = A[i];
        V[i] = false;
    }
    sort(B, B+n);
    for(i=0;i<n;i++)
        T[B[i]] = i;
    for(i=0;i<n;i++){
        if(V[i])
            continue;
        int cur = i;
        int S = 0;
        int m = VMAX;
        int an = 0;
        while(1){
            V[cur] = true;
            an++;
            int v = A[cur];
            m = min(m, v);
            S += v;
            cur = T[v];
            if(V[cur])
                break;
        }
        answer += min(S + (an - 2) * m, m+S+(an+1) * s);
    }
    return answer;
}

int main(void)
{
    scanf("%d", &n);
    s = VMAX;
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &A[i]);
        s = min(s, A[i]);
    }
    int answer = solve();
    printf("%d\n", answer);

    return 0;
}