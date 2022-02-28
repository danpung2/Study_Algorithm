#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10005
using namespace std;

int main(void)
{
    vector<int> v1, v2, v3;
    char a[MAX];
    char b[MAX];
    string str_a;
    string str_b;
    int i;

    scanf("%s %s", a, b);
    str_a = a;
    str_b = b;

    for (i = 0; i < str_a.length(); i++)
        v1.push_back(a[i] - '0');

    for (i = 0; i < str_b.length(); i++)
        v2.push_back(b[i] - '0');

    while (v1.size() > v2.size())
    {
        v2.insert(v2.begin(), 0);
    }
    while (v1.size() < v2.size())
    {
        v1.insert(v1.begin(), 0);
    }

    int w = 0;

    for (i = v1.size() - 1; i >= 0; i--)
    {
        int data = w + v1[i] + v2[i];
        if (data > 9)
        {
            w = data / 10;
            v3.push_back(data % 10);
        }
        else
        {
            w = 0;
            v3.push_back(data);
        }
    }
    
    if (w > 0)
        v3.push_back(w);
    reverse(v3.begin(), v3.end());
    for (i = 0; i < v3.size(); i++)
        printf("%d", v3[i]);
    printf("\n");

    return 0;
}