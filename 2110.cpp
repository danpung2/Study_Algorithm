#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, c;
    vector<long long> xi;
    int i, tmp = 0;

    scanf("%d %d", &n, &c);
    for(i=0;i<n;i++){
        long long x;
        scanf("%lld", &x);
        xi.push_back(x);
    }
    sort(xi.begin(), xi.end());

    long long start = 1, end = xi[n-1] - xi[0];
    while(start <= end){
        long long already = xi[0];
        long long mid = (start + end) / 2;
        int cnt = 1;
        for(i=1;i<n;++i){
            if((xi[i] - already) >= mid){
                ++cnt;
                already = xi[i];
            }
        }
        if(cnt >= c){
            tmp = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    printf("%d\n", tmp);

    return 0;
}