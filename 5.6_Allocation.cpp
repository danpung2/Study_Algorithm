#include <iostream>
using namespace std;
#define MAX 100000
#define ERROR -1

int check(long long p, long long t[], int n, int k)
{
    int i = 0;
    for (int j = 0; j < k; j++)
    {
        long long s = 0;
        while (s + t[i] <= p)
        {
            s += t[i];
            i++;
            if (i == n)
                return n;
        }
    }
    return i;
}

int solve(long long t[], int n, int k)
{
    long long left = 0;
    long long right = 100000 * 10000;
    long long mid;
    while (right - left > 1)
    {
        mid = (left + right) / 2;
        int v = check(mid, t, n, k);
        if (v >= n)
            right = mid;
        else
            left = mid;
    }
    return right;
}

int main(void)
{
    int n, k;
    long long t[MAX];

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    long long ans = solve(t, n, k);
    cout << ans << endl;

    return 0;
}