#include <stdio.h>
#define MAX 100001

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void q_sort(int A[], int start, int end)
{
    int p = start;
    int left = start + 1;
    int right = end;

    if(start < end)
    {
        while(left <= right)
        {
            while(left <= end && A[left] <= A[p])
                left++;
            while(right > start && A[right] >= A[p])
                right--;
            if(left > right)
                swap(&A[right], &A[p]);
            else
                swap(&A[left], &A[p]);
        }
        q_sort(A, start, right-1);
        q_sort(A, right+1, end);
    }
}

int binary_search(int A[], int start, int end, int target)
{

    if(start > end)
        return -1;
    int mid = (start + end) / 2;
    if(A[mid] < target)
        return binary_search(A, mid+1, end, target);
    else if(A[mid] > target)
        return binary_search(A, start, mid-1, target);
    else
        return mid;
}

int main(void)
{
    int i;
    int n;
    int m;
    int target[MAX];
    int A[MAX];

    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);

    q_sort(A, 0, n-1);

    scanf("%d", &m);
    for(i=0;i<m;i++)
    {
        scanf("%d", &target[i]);
    }

    for(i=0;i<m;i++)
    {
        if(binary_search(A, 0, n-1, target[i]) == -1)
            printf("0\n");
        else
            printf("1\n");
    }

    return 0;
}