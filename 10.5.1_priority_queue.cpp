#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    priority_queue<int> PQ;

    PQ.push(1);
    PQ.push(8);
    PQ.push(3);
    PQ.push(5);

    printf("%d ", PQ.top());
    PQ.pop();
    printf("%d ", PQ.top());
    PQ.pop();

    PQ.push(11);

    printf("%d ", PQ.top());
    PQ.pop();

    printf("%d ", PQ.top());
    PQ.pop();

    printf("\n");

    return 0;
}