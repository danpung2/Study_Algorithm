#include <iostream>
#include <map>
using namespace std;

#define MAX 55

int main(void)
{
    int n, cnt;
    int i;
    char buffer[MAX];
    map<string, int> selling;
    map<string, int>::iterator it;

    scanf("%d", &n);
    
    for(i=0;i<n;i++)
    {
        scanf("%s", buffer);
        if(selling.size() > 0 && selling.find(buffer) != selling.end())
            selling[buffer]++;
        else
        {
            cnt = 0;
            selling.insert(make_pair(buffer, cnt));
        }
    }

    string max_sold = buffer;
    int max_cnt = selling[buffer];

    for(it=selling.begin();it!=selling.end();it++)
    {
        pair<string, int> sold = *it;
        if(max_cnt < sold.second)
        {
            max_sold = sold.first;
            max_cnt = sold.second;
        }
        else if(max_cnt == sold.second)
        {
            if(max_sold > sold.first)
            {
                max_sold = sold.first;
            }
        }
    }

    printf("%s\n", max_sold.c_str());

    return 0;
}