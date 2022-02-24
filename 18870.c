#include <stdio.h>
#include <stdlib.h>

void swap(long long *x, long long *y)
{
    long long tmp = *x;
    *x = *y;
    *y = tmp;
}

void make_heap(long long heap_array[], int size, int i)
{
    int c = 2 * i + 1;
    if (c < size - 1 && heap_array[c] <= heap_array[c + 1])
        if (heap_array[c] < heap_array[c + 1])
            c++;
    if (c < size && heap_array[i] <= heap_array[c])
        swap(&heap_array[i], &heap_array[c]);
    if (c < size / 2)
        make_heap(heap_array, size, c);
}

void heap_sort(long long heap_array[], int size)
{
    int i;
    for (i = size / 2; i >= 0; i--)
    {
        make_heap(heap_array, size, i);
    }

    for (i = size - 1; i >= 0; i--)
    {
        swap(&heap_array[i], &heap_array[0]);
        make_heap(heap_array, i, 0);
    }
}

void BinarySearch(long long arr[], int start, int end, long long find)
{
    int mid = (start + end) / 2;
    if (find > arr[mid])
        start = mid + 1;
    else if (find == arr[mid])
    {
        printf("%d ", mid);
        return;
    }
    else
        end = mid - 1;
    BinarySearch(arr, start, end, find);
}

int main(void)
{
    int i, j, k, n;

    scanf("%d", &n);
    long long *xi = (long long *)malloc(sizeof(long long) * n);
    long long *sorted = (long long *)malloc(sizeof(long long) * n);
    long long *deleteDuplication = (long long *)malloc(sizeof(long long) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%lld", &xi[i]);
        sorted[i] = xi[i];
    }

    heap_sort(sorted, n);
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (i < n - 1 && sorted[i] == sorted[i + 1])
            continue;
        deleteDuplication[j] = sorted[i];
        j++;
    }

    for (i = 0; i < n; i++)
    {
        BinarySearch(deleteDuplication, 0, j - 1, xi[i]);
    }

    printf("\n");

    return 0;
}
