#include <stdio.h>

int main(void)
{
    int a, b, c;
    int h, m;

    scanf("%d %d", &a, &b);
    scanf("%d", &c);

    m = b + c;
    h = a;
    if(m >= 60)
    {
        h += m/60;
        m %= 60;
    }
    if(h >= 24)
    {
        h %= 24;
    }

    printf("%d %d\n", h, m);



    return 0;
}