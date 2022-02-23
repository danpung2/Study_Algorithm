#include <stdio.h>

#define MAX 1000000

int arr[MAX], n;

int binarySearch(int key){
    int left = 0;
    int right = n;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(key == arr[mid])
            return 1;
        if(key > arr[mid])
            left = mid + 1;
        else if(key < arr[mid])
            right = mid;
    }
    return 0;
}

int main(void)
{
    int i, q, k, sum = 0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &q);
    for(i=0;i<q;i++){
        scanf("%d", &k);
        if(binarySearch(k))
            sum++;
    }
    printf("%d\n", sum);


    return 0;
}