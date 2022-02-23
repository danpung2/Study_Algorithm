#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500000

int upper_bound(int card[], int find, int first, int last){
    int mid;
    while(first < last){
        mid = (first + last) / 2;
        if(card[mid] <= find)
            first = mid + 1;
        else
            last = mid;
    }
    return last + 1;
}

int lower_bound(int card[], int find, int first, int last){
    int mid;
    while(first < last){
        mid = (first + last) / 2;
        if(card[mid] < find)
            first = mid + 1;
        else
            last = mid;
    }
    return last + 1;
}

int main(void)
{
    int n, m;
    int i;
    int card[MAX];
    int find_card[MAX];
    int answer[MAX];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &card[i]);
    sort(card, card + n);
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%d", &find_card[i]);

    for (i = 0; i < m; i++)
        printf("%d ", upper_bound(card, find_card[i], 0, n) - lower_bound(card, find_card[i], 0, n));
    printf("\n");
    return 0;
}