#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 100001

int idx = 1;
int n;

void heapify(int *heap, int idx)
{
    int left, right, largest;
    left = 2 * idx;
    right = 2 * idx + 1;

    if(left <= n && (abs(heap[left]) >= abs(heap[idx])) && heap[left] != 0 && heap[idx] != 0)
    {
        if((abs(heap[left]) > abs(heap[idx])) || (abs(heap[left]) == abs(heap[idx]) && (heap[left] < heap[idx])))
            largest = left;
        else
            largest = idx;
    }
    else
        largest = idx;

    if(right <= n && (abs(heap[right]) >= abs(heap[largest])) && heap[right] != 0 && heap[largest] != 0)
        if((abs(heap[right]) > abs(heap[largest])) || abs(heap[right]) == abs(heap[largest]) && (heap[right] < heap[largest]))
            largest = right;

    if(largest != idx && heap[largest] != 0 && heap[idx] != 0)
    {
        swap(heap[idx], heap[largest]);
        heapify(heap, largest);
    }
}
void push(int *heap, int data)
{
    heap[idx] = data;
    heapify(heap, 1);
    idx++;
}
void pop(int *heap)
{
    if(idx < 1)
        printf("0\n");
    else{
        printf("%d\n", heap[idx]);
        idx--;
        if(idx > 1)
            heapify(heap, 1);
    }
}

int main(void)
{
    int i, x;
    
    int *heap = (int *)malloc(sizeof(int) * MAX);

    printf("%d\n", abs(-2));

    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &x);
        if(x == 0)
        {
            pop(heap);
            // printf("idx: %d\n", idx);
        }
        else
        {
            push(heap, x);
            // for(int j=0;j<idx;j++)
            // {
            //     printf(" %d", heap[j]);
            // }
            // printf("\n");
            //printf("idx: %d\n", idx);
        }
    }


    return 0;
}