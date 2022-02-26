#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int a, b;
    int i, buffer;
    vector<int> v1, v2, v3, v4;

    scanf("%d %d", &a, &b);

    for(i=0;i<a;i++)
    {
        scanf("%d", &buffer);
        v1.push_back(buffer);
    }

    sort(v1.begin(), v1.end());

    for(i=0;i<b;i++)
    {
        scanf("%d", &buffer);
        v2.push_back(buffer);
        if(binary_search(v1.begin(), v1.end(), buffer) == false)
            v3.push_back(buffer);
    }

    sort(v2.begin(), v2.end());

    for(i=0;i<a;i++)
    {
        if(binary_search(v2.begin(), v2.end(), v1[i]) == false)
            v4.push_back(v1[i]);
    }

    int answer = v3.size() + v4.size();

    printf("%d\n", answer);

    return 0;
}