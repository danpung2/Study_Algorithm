#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 30

int main(void)
{
    int n, m;
    int i;
    char buffer[MAX];
    int cnt = 0;
    vector<string> v1, v2;

    scanf("%d %d", &n, &m);

    for(i=0;i<n;i++)
    {
        scanf("%s", buffer);
        v1.push_back(buffer);
    }

    sort(v1.begin(), v1.end());

    for(i=0;i<m;i++)
    {
        scanf("%s", buffer);
        
        if(binary_search(v1.begin(), v1.end(), buffer))
        {
            v2.push_back(buffer);
            cnt++;
        }
    }

    sort(v2.begin(), v2.end());

    printf("%d\n", cnt);

    for(i=0;i<v2.size();i++)
        printf("%s\n", v2[i].c_str());

    return 0;
}