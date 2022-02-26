#include <iostream>
#include <set>
using namespace std;

void print(set<int> S)
{
    printf("%lu:", S.size());
    for(set<int>::iterator it = S.begin(); it != S.end(); it++)
    {
        printf(" %d", *it);
    }
    printf("\n");
}

int main()
{
    set<int> S;
    S.insert(8);
    S.insert(1);
    S.insert(7);
    S.insert(4);
    S.insert(8);
    S.insert(4);

    print(S);

    S.erase(7);
    print(S);

    S.insert(2);
    print(S);

    if(S.find(10) == S.end())
        printf("Not Found\n");
    
    return 0;
}