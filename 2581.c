#include <stdio.h>
#include <stdbool.h>
#define MAX 10001

int main(void)
{
    int i;
    int arr[MAX];
    bool checkbox[MAX];
    int sum, min;
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    for(i=0;i<=n;i++)
    {
        arr[i] = i;
        checkbox[i] = true;
    }

    for(i=2;i * i<=n;i++)
    {
        if(checkbox[i] == true)
            for(int j = i*i;j<=n;j+=i)
                checkbox[j] = false;
    }
    sum = 0;
    min = MAX;
    for(i=0;i<=n;i++)
    {
        if(checkbox[i] == true && i >= m && i > 1)
        {
            if(min > arr[i])
                min = arr[i];
            sum += arr[i];
        }
    }

    if(sum == 0)
        printf("-1\n");
    else
        printf("%d\n%d\n", sum, min);


    return 0;
}