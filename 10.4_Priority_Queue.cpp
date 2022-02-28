#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 2000000
#define INFTY (1<<30)

int H, A[MAX+1];

void maxHeapify(int i)
{
    int left, right, largest;
    left = 2 * i;
    right = 2 * i + 1;

    if(left <= H && A[left] > A[i])
        largest = left;
    else
        largest = i;

    if(right <= H && A[right] > A[largest])
        largest = right;
    
    if(largest != i)
    {
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

int extract()
{
    int maxv;
    if(H < 1)
        return -INFTY;
    maxv = A[1];
    A[1] = A[H--];
    maxHeapify(1);
    return maxv;
}

void increaseKey(int i, int key)
{
    if(key < A[i])
        return;
    A[i] = key;
    while(i > 1 && (A[i/2] < A[i]))
    {
        swap(A[i], A[i/2]);
        i /= 2;
    }
}

void insert(int key)
{
    H++;
    A[H] = -INFTY;
    increaseKey(H, key);
}

int main(void)
{
    int key;
    char buffer[10];

    while(true)
    {
        scanf("%s", buffer);
        if(buffer[0] == 'e' && buffer[1] == 'n')
            break;
        if(buffer[0] == 'i')
        {
            scanf("%d", &key);
            insert(key);
        } else
            printf("%d\n", extract());
    }

    return 0;
}