#include <stdio.h>
#include <stdbool.h>
#define MAX 1000001

int main(void)
{
    int i;
    int arr[MAX];
    bool checkbox[MAX];
    int sum, min;
    int m, n;
    scanf("%d %d", &m, &n);

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
    for(i=0;i<=n;i++)
    {
        if(checkbox[i] == true && i >= m && i > 1)
        {
            printf("%d\n", arr[i]);
        }
    }

    return 0;
}