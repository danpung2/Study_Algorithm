#include <iostream>
using namespace std;
#define MAX 2000000

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

int main(void)
{
    int i;

    scanf("%d", &H);

    for(i=1;i<=H;i++)
        scanf("%d", &A[i]);
    
    for(i=H/2;i>=1;i--)
        maxHeapify(i);

    for(i=1;i<=H;i++)
        printf(" %d", A[i]);

    printf("\n");

    return 0;
}