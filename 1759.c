#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

void decode(char code[], int l, int c, int len, int idx, int cnt);
int comp(const void *x, const void *y);
char encode[MAX];

int main(void)
{
    int i;
    int l, c;
    char tmp[MAX];
    char *ptr;
    char code[MAX];
    scanf("%d %d", &l, &c);
    getchar();
    fgets(tmp, sizeof(tmp), stdin);
    i = 0;
    ptr = strtok(tmp, " ");
    encode[i] = ptr[0];
    while(1){
        i++;
        ptr = strtok(NULL, " ");
        if(ptr == NULL)
            break;
        encode[i] = ptr[0];
    }
    for(i=0;i<c;i++)
        code[i] = encode[i];
    qsort(code, c, sizeof(char), comp);
    decode(code, l, c, 0, 0, 0);

    return 0;
}

void decode(char code[], int l, int c, int len, int idx, int cnt){
    int i;
    if(len == l && cnt > 0 && len-cnt > 1)
    {
        for(i=0;i<len;i++)
            printf("%c", encode[i]);
        printf("\n");
        return;
    }
    else if(len == l || idx == c)
        return;
    encode[len] = code[idx];
    if(encode[len] == 'a' || encode[len] == 'e' || encode[len] == 'i' || encode[len] == 'o' || encode[len] == 'u')
        decode(code, l, c, len+1, idx+1, cnt+1);
    else
        decode(code, l, c, len+1, idx+1, cnt);
    decode(code, l, c, len, idx+1, cnt);
    return;
}

int comp(const void *x, const void *y)
{
    char code1 = *(char *)x;
    char code2 = *(char *)y;
    if(code1 > code2)
        return 1;
    else if(code1 < code2)
        return -1;
    else
        return 0;
}